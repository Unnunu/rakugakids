#include "common.h"

typedef struct Struct14 {
    /* 0x00 */ u32 frequency;
    /* 0x04 */ s32 leftChild;
    /* 0x08 */ s32 rightChild;
} Struct14; // size = 0xC

s32 D_8002A2E0 = 0;
s32 D_8002A2E4 = 256;
s32 D_8002A2E8 = 257;

Struct14 *D_8004F700;
s32 D_8004F704;
u32 D_8004F708;
u32 D_8004F70C;
u32 D_8004F710;
u32 D_8004F714;
u8 *D_8004F718;
HeapChunk *D_8004F71C;

void func_8000C9CC(u32, u8 *);
void func_8000CCA8(void);
s32 func_8000CDE4(void);
void func_8000D208(void);
void func_8000CBDC(void);

u8 *func_8000C930(u32 romAddr, u8 *vramAddr) {
    func_8000C9CC(romAddr, vramAddr);

    D_8002A2E0 = 0x204;
    D_8004F71C = mem_alloc(&D_8004F71C, D_8002A2E0 * sizeof(Struct14));
    if (D_8004F71C == NULL) {
        return 0;
    }
    D_8004F700 = D_8004F71C->data;
    func_8000CCA8();
    D_8004F704 = func_8000CDE4();
    func_8000D208();
    mem_free(D_8004F71C);
    return D_8004F718;
}

void func_8000C9CC(u32 arg0, u8 *arg1) {
    D_8004F708 = arg0;
    D_8004F70C = 0xD00;
    D_8004F718 = arg1;
    D_8004F710 = 0;
    D_8004F714 = 0x80000000;
}

u8 func_8000CA00(void) {
    if (D_8004F70C == 0xD00) {
        func_8000CBDC();
    }
    return D_80044254->unk_75BF8[D_8004F70C++];
}

s32 func_8000CA58(void) {
    s32 value;

    if (D_8004F70C == 0xD00) {
        func_8000CBDC();
    }

    value = *(s32 *) (D_80044254->unk_75BF8 + D_8004F70C);
    D_8004F70C += 4;
    return value;
}

#pragma GLOBAL_ASM("asm/nonmatchings/huffman/func_8000CAB0.s")

void func_8000CBDC(void) {
    func_80000D1C(D_8004F708, D_80044254->unk_75BF8, 0xD00);
    D_8004F708 += 0xD00;
    D_8004F70C = 0;
}

s32 func_8000CC30(void) {
    u32 v0;
    s32 ret;

    if (D_8004F714 == 0x80000000) {
        D_8004F710 = func_8000CA58();
    }

    v0 = D_8004F710 & D_8004F714;
    D_8004F714 >>= 1;
    if (D_8004F714 == 0) {
        D_8004F714 = 0x80000000;
    }
    if (v0) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

void func_8000CCA8(void) {
    s32 i;
    s32 low;
    s32 high;

    for (i = 0; i < 0x100; i++) {
        D_8004F700[i].frequency = 0;
    }

    for (i = 0; i < 8; i++) {
        func_8000CA00();
    }

    D_8004F700[D_8002A2E4].frequency = func_8000CA00();
    low = func_8000CA00();
    high = func_8000CA00();

    while (TRUE) {
        for (i = low; i <= high; i++) {
            D_8004F700[i].frequency = func_8000CA00();
        }

        low = func_8000CA00();
        if (low == 0) {
            break;
        }
        high = func_8000CA00();
    }

    D_8004F700[D_8002A2E8].frequency = 1;
}

s32 func_8000CDE4(void) {
    s32 v1;
    s32 a2, a0;
    s32 i;

    D_8004F700[D_8002A2E0 - 1].frequency = 0xFFFFFFFF; // or -1 ?
    v1 = D_8002A2E8 + 1;

    while (TRUE) {
        a0 = D_8002A2E0 - 1;
        a2 = D_8002A2E0 - 1;

        for (i = 0; i < v1; i++) {
            if (D_8004F700[i].frequency != 0) {
                if (D_8004F700[i].frequency < D_8004F700[a0].frequency) {
                    a2 = a0;
                    a0 = i;
                } else if (D_8004F700[i].frequency < D_8004F700[a2].frequency) {
                    a2 = i;
                }
            }
        }

        if (a2 != D_8002A2E0 - 1) {
            D_8004F700[v1].frequency = D_8004F700[a0].frequency + D_8004F700[a2].frequency;
            D_8004F700[a0].frequency = 0;
            D_8004F700[a2].frequency = 0;
            D_8004F700[v1].leftChild = a0;
            D_8004F700[v1].rightChild = a2;
            v1++;
        } else {
            break;
        }
    }

    return v1 - 1;
}

s32 func_8000CFFC(void) {
    s32 i;

    i = D_8004F704;
    do {
        if (func_8000CC30() != 0) {
            i = D_8004F700[i].rightChild;
        } else {
            i = D_8004F700[i].leftChild;
        }
    } while (i > D_8002A2E8);
    return i;
}

void func_8000D09C(void) {
    s32 length;
    s32 extraBits;
    s32 i;
    s32 a0;
    s32 extraLength;
    s32 chVal;

    length = 3;
    a0 = (func_8000CC30() << 1) | func_8000CC30();

    while (a0 == 3) {
        length += 84;
        a0 = (func_8000CC30() << 1) | func_8000CC30();
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
        extraLength = (extraLength << 1) | func_8000CC30();
    }

    length += extraLength;
    chVal = func_8000CFFC();

    for (i = 0; i < length; i++) {
        *D_8004F718++ = chVal;
    }
}

void func_8000D208(void) {
    s32 temp_v0;

    func_8000CAB0();

    while (TRUE) {
        temp_v0 = func_8000CFFC();
        if (temp_v0 == D_8002A2E8) {
            break;
        }
        if (temp_v0 == D_8002A2E4) {
            func_8000D09C();
        } else {
            *D_8004F718++ = temp_v0;
        }
    }
}
