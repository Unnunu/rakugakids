#include "common.h"

/**
 * ============================================================================
 *   CUSTOM LZ-VARIANT DECOMPRESSION STREAM SPECIFICATION
 * ============================================================================
 *
 * The data stream is read byte by byte. The operation type is determined
 * by the most significant bits (MSB) of the first byte read (the prefix).
 *
 * BITMASK AND STREAM MAP:
 * ----------------------------------------------------------------------------
 *  Case | First Byte Bits        | Second Byte Bits       | Operation Type
 * ----------------------------------------------------------------------------
 *   (a) | 0 X X X X X Y Y        | Y Y Y Y Y Y Y Y        | Dictionary Copy
 *   (b) | 1 0 0 X X X X X        | (none)                 | Raw Literals
 *   (c) | 1 0 1 X X X X X  -or-  |                        |
 *       | 1 1 0 X X X X X        | Y Y Y Y Y Y Y Y        | Byte Fill
 *   (d) | 1 1 1 X X X X X        | (none)                 | Zero Fill (Short)
 *   (e) | 1 1 1 1 1 1 1 1        | X X X X X X X X        | Zero Fill (Long)
 * ----------------------------------------------------------------------------
 *
 * DETAILED OPERATION BREAKDOWN:
 *
 * a) DICTIONARY COPY (Back-reference)
 *    Prefix:   0xxxxx.. (MSB is 0)
 *    Format:   2 bytes.
 *              Length = xxxxx + 2   [Range: 2..33 bytes]
 *              Offset = yyyyyyyyyy  [Range: 0..1023 bytes backward]
 *    Action:   Move back into the output history buffer by Offset bytes
 *              and copy Length bytes to the current output position.
 *
 * b) RAW LITERALS (Uncompressed Data)
 *    Prefix:   100xxxxx
 *    Format:   1 byte.
 *              Length = xxxxx       [Range: 0..31 bytes]
 *    Action:   Read the next Length bytes directly from the input stream
 *              and copy them to the output without any modification.
 *
 * c) BYTE FILL (Run-Length Encoding)
 *    Prefix:   101xxxxx or 110xxxxx
 *    Format:   2 bytes. Second byte is the fill value (yyyyyyyy).
 *              Length = xxxxx + 2   [Range: 2..33 bytes]
 *    Action:   Write the byte value yyyyyyyy into the output stream,
 *              repeating it Length times.
 *
 * d) SHORT ZERO FILL
 *    Prefix:   111xxxxx (where xxxxx is NOT 11111 / 0x1F)
 *    Format:   1 byte.
 *              Length = xxxxx + 2   [Range: 2..32 bytes]
 *    Action:   Write Length zero bytes (0x00) into the output stream.
 *
 * e) EXTENDED ZERO FILL
 *    Prefix:   11111111 (0xFF)
 *    Format:   2 bytes. Second byte is xxxxxxxx.
 *              Length = xxxxxxxx + 2 [Range: 2..257 bytes]
 *    Action:   Write Length zero bytes (0x00) into the output stream.
 *
 * ============================================================================
 */

StructD48 D_8004F720;
OSIoMesg D_80050468;
OSIoMesg D_80050480;

void func_8000D5C4(StructD48 *);
u8 *func_8000D38C(StructD48 *);

u8 huffman_read_byte(HuffmanTree *);
void huffman_dma_read(HuffmanTree *);

void func_8000D2A0(u32 romAddr, u8 *outBuf, s32 size) {
    func_8000D2E4(&D_8004F720, romAddr, outBuf, size);
    func_8000D38C(&D_8004F720);
}

void func_8000D2E4(StructD48 *arg0, u32 romAddr, u8 *outBuf, s32 size) {
    u32 sp24;

    mem_clear(arg0, sizeof(StructD48));
    arg0->romAddr = arg0->romPtr = romAddr;
    arg0->size = size;
    arg0->inBufPtr = arg0->buffer;
    arg0->outBufPtr = outBuf;
    arg0->offset = 0;
    func_8000D5C4(arg0);
    sp24 = *(u32 *) arg0->inBufPtr;
    func_8000D568(arg0);
    func_8000D568(arg0);
    func_8000D568(arg0);
    func_8000D568(arg0);
    arg0->romEnd = arg0->romPtr + sp24 - 4;
}

u8 *func_8000D38C(StructD48 *s1) {
    u8 byteVal;
    u16 distance;
    u16 length;
    u8 *v1;
    s32 fillValue;

    while (s1->romPtr < s1->romEnd) {
        byteVal = *s1->inBufPtr;
        func_8000D568(s1);
        if (byteVal < 0x80) {
            distance = (*s1->inBufPtr + (byteVal << 8)) & 0x3FF;
            length = (byteVal >> 2) + 2;
            func_8000D568(s1);

            v1 = s1->outBufPtr - distance;
            while (length--) {
                *s1->outBufPtr++ = *v1++;
            }
        } else if (byteVal < 0xA0) {
            length = byteVal & 0x1F;
            while (length--) {
                *s1->outBufPtr++ = *s1->inBufPtr;
                func_8000D568(s1);
            }
        } else {
            if (byteVal < 0xE0) {
                length = (byteVal & 0x1F) + 2;
                fillValue = *s1->inBufPtr;
                func_8000D568(s1);
            } else if (byteVal < 0xFF) {
                length = (byteVal & 0x1F) + 2;
                fillValue = 0;
            } else {
                length = *s1->inBufPtr + 2;
                func_8000D568(s1);
                fillValue = 0;
            }

            while (length--) {
                *s1->outBufPtr++ = fillValue;
            }
        }
    }

    return s1->outBufPtr;
}

void func_8000D568(StructD48 *arg0) {
    arg0->romPtr++;
    arg0->offset++;
    if (--arg0->batchSize) {
        arg0->inBufPtr++;
    } else {
        arg0->inBufPtr = arg0->buffer;
        func_8000D5C4(arg0);
    }
}

void func_8000D5C4(StructD48 *arg0) {
    void *mesg = NULL;

    arg0->batchSize = 0xD00;
    arg0->size -= 0xD00;
    if (arg0->size < 0) {
        arg0->batchSize += (arg0->size + 1) & ~1;
        arg0->size = 0;
    }

    if (arg0->batchSize > 0) {
        osInvalDCache(arg0->buffer, arg0->batchSize);
        osInvalICache(arg0->buffer, arg0->batchSize);
        osPiStartDma(&D_80050468, OS_MESG_PRI_NORMAL, OS_READ, arg0->romAddr, arg0->buffer, arg0->batchSize,
                     &gScheduler.unk_3DC);
        while (mesg == NULL) {
            osRecvMesg(&gScheduler.unk_3DC, &mesg, OS_MESG_NOBLOCK);
        }
    }
    arg0->romAddr += arg0->batchSize;
}

u8 huffman_read_byte(HuffmanTree *ht) {
    if (ht->bufIndex == 0xD00) {
        huffman_dma_read(ht);
    }

    return ht->buffer[ht->bufIndex++];
}

s32 huffman_read_word(HuffmanTree *ht) {
    s32 value;

    if (ht->bufIndex == 0xD00) {
        huffman_dma_read(ht);
    }

    value = *(s32 *) (ht->buffer + ht->bufIndex);
    ht->bufIndex += 4;
    return value;
}

#ifdef NON_EQUIVALENT
void func_8000D744(HuffmanTree *ht) {
    switch (ht->bufIndex % 4) {
        case 0:
            ht->wordValue = 0;
            ht->bitMask = 0x80000000;
            break;
        case 1:
            ht->bufIndex++;
            ht->bufIndex++;
            ht->bufIndex++;
            ht->bitMask = 0x800000;
            ht->wordValue = *(u32 *) (ht->buffer + ht->bufIndex);
            break;
        case 2:
            ht->bufIndex++;
            ht->bufIndex++;
            ht->bitMask = 0x8000;
            ht->wordValue = *(u32 *) (ht->buffer + ht->bufIndex);
            break;
        case 3:
            ht->bufIndex++;
            ht->bitMask = 0x80;
            ht->wordValue = *(u32 *) (ht->buffer + ht->bufIndex);
            break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/compression/func_8000D744.s")
#endif

void huffman_dma_read(HuffmanTree *ht) {
    void *mesg = NULL;

    osInvalDCache(ht->buffer, 0xD00);
    osInvalICache(ht->buffer, 0xD00);
    osPiStartDma(&D_80050480, OS_MESG_PRI_NORMAL, OS_READ, ht->romPtr, ht->buffer, 0xD00, &gScheduler.unk_3F8);
    while (mesg == NULL) {
        osRecvMesg(&gScheduler.unk_3F8, &mesg, OS_MESG_NOBLOCK);
    }
    ht->bufIndex = 0;
    ht->romPtr += 0xD00;
}

s32 huffman_get_bit(HuffmanTree *ht) {
    u32 v1;
    u32 bitValue;
    u8 var_v1;

    if (ht->bitMask == 0x80000000) {
        ht->wordValue = huffman_read_word(ht);
    }

    bitValue = ht->wordValue & ht->bitMask;
    ht->bitMask >>= 1;
    if (ht->bitMask == 0) {
        ht->bitMask = 0x80000000;
    }

    if (bitValue != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void huffman_read_frequencies(HuffmanTree *ht) {
    s32 i;
    s32 low;
    s32 high;

    for (i = 0; i < 0x100; i++) {
        ht->tree[i].frequency = 0;
    }

    for (i = 0; i < 8; i++) {
        huffman_read_byte(ht);
    }

    ht->tree[0x100].frequency = huffman_read_byte(ht);

    low = huffman_read_byte(ht);
    high = huffman_read_byte(ht);

    while (TRUE) {
        for (i = low; i <= high; i++) {
            ht->tree[i].frequency = huffman_read_byte(ht);
        }

        low = huffman_read_byte(ht);
        if (low == 0) {
            break;
        }
        high = huffman_read_byte(ht);
    }

    ht->tree[0x101].frequency = 1;
}

s32 huffman_build_tree(HuffmanTree *ht) {
    s32 index;
    s32 minFreqIndex;
    s32 secondFreqIndex;
    s32 i;

    ht->tree[0x203].frequency = 0xFFFF;

    index = 0x102;

    while (TRUE) {
        secondFreqIndex = minFreqIndex = 0x203;

        for (i = 0; i < index; i++) {
            if (ht->tree[i].frequency != 0) {
                if (ht->tree[i].frequency < ht->tree[minFreqIndex].frequency) {
                    secondFreqIndex = minFreqIndex;
                    minFreqIndex = i;
                } else if (ht->tree[i].frequency < ht->tree[secondFreqIndex].frequency) {
                    secondFreqIndex = i;
                }
            }
        }
        if (secondFreqIndex != 0x203) {
            ht->tree[index].frequency = ht->tree[minFreqIndex].frequency + ht->tree[secondFreqIndex].frequency;
            ht->tree[minFreqIndex].frequency = 0;
            ht->tree[secondFreqIndex].frequency = 0;
            ht->tree[index].leftChild = minFreqIndex;
            ht->tree[index].rightChild = secondFreqIndex;
            index++;
        } else {
            break;
        }
    }

    return index - 1;
}

s32 huffman_get_char(HuffmanTree *ht) {
    s32 index;

    index = ht->rootIndex;
    do {
        if (huffman_get_bit(ht)) {
            index = ht->tree[index].rightChild;
        } else {
            index = ht->tree[index].leftChild;
        }
    } while (index > 0x101);
    return index;
}

void func_8000DC48(HuffmanTree *ht) {
    s32 length;
    s32 extraBits;
    s32 i;
    s32 a0;
    s32 extraLength;
    s32 chVal;

    length = 3;
    a0 = (huffman_get_bit(ht) << 1) | huffman_get_bit(ht);

    while (a0 == 3) {
        length += 84;
        a0 = (huffman_get_bit(ht) << 1) | huffman_get_bit(ht);
    }

    switch (a0) {
        case 0:
            extraBits = 2;
            break;
        case 1:
            extraBits = 4;
            length += 4;
            break;
        case 2:
            extraBits = 6;
            length += 20;
            break;
    }

    for (i = 0, extraLength = 0; i < extraBits; i++) {
        extraLength = (extraLength << 1) | huffman_get_bit(ht);
    }

    length += extraLength;
    chVal = huffman_get_char(ht);

    for (i = 0; i < length; i++) {
        *ht->outPtr++ = chVal;
    }
}
