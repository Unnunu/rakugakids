#ifndef _COMMON_STRUCTS_H
#define _COMMON_STRUCTS_H

typedef struct Struct6 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void *unk_0C;
    /* 0x10 */ OSTask unk_10;
    /* 0x50 */ OSMesgQueue *unk_50;
    /* 0x54 */ OSMesg unk_54;
} Struct6; // size = 0x58

typedef struct Scheduler {
    /* 0x0000 */ u16 unk_00;
    /* 0x0002 */ u16 unk_02;
    /* 0x0004 */ u16 unk_04;
    /* 0x0006 */ u16 unk_06;
    /* 0x0008 */ u16 unk_08;
    /* 0x000A */ s16 unk_0A;
    /* 0x0044 */ OSMesgQueue unk_C;
    /* 0x005C */ OSMesg unk_24[8];
    /* 0x0044 */ OSMesgQueue unk_44;
    /* 0x005C */ OSMesg unk_5C[8];
    /* 0x007C */ OSMesgQueue unk_7C;
    /* 0x0094 */ OSMesg unk_94[64];
    /* 0x0194 */ OSMesgQueue unk_194;
    /* 0x01AC */ OSMesg unk_1AC[8];
    /* 0x01CC */ OSMesgQueue unk_1CC;
    /* 0x01E4 */ OSMesg unk_1E4[64];
    /* 0x02E4 */ OSMesgQueue queueSync;
    /* 0x02FC */ OSMesg unk_2FC[8];
    /* 0x031C */ OSMesgQueue queueSP;
    /* 0x0334 */ OSMesg unk_334[8];
    /* 0x0354 */ OSMesgQueue queueDP;
    /* 0x036C */ OSMesg unk_36C[8];
    /* 0x038C */ OSMesgQueue unk_38C;
    /* 0x03A4 */ OSMesg unk_3A4[8];
    /* 0x03C4 */ char unk_3C4[0x18];
    /* 0x03DC */ OSMesgQueue unk_3DC;
    /* 0x03F4 */ OSMesg unk_3F4[1];
    /* 0x03F8 */ OSMesgQueue unk_3F8;
    /* 0x0410 */ OSMesg unk_410[1];
    /* 0x0414 */ OSMesgQueue unk_414;
    /* 0x042C */ OSMesg unk_42C[8];
    /* 0x0450 */ OSThread unk_450;
    /* 0x0600 */ OSThread unk_600;
    /* 0x07B0 */ OSThread unk_7B0;
    /* 0x0960 */ OSThread unk_960;
    /* 0x0B10 */ OSThread unk_B10;
    /* 0x0CC0 */ OSThread unk_CC0;
    /* 0x0E70 */ struct Struct3 *unk_E70;
    /* 0x0E74 */ char unk_E74[0x600];
    /* 0x1474 */ Struct6 *unk_1474;
    /* 0x1478 */ Struct6 *unk_1478;
    /* 0x147C */ Struct6 *unk_147C;
    /* 0x1480 */ s32 unk_1480;
    /* 0x1484 */ s32 unk_1484;
    /* 0x1488 */ s32 unk_1488;
    /* 0x148C */ s32 unk_148C;
    /* 0x1490 */ s32 unk_1490;
    /* 0x1494 */ s32 unk_1494;
} Scheduler; // size = 0x1498

typedef struct Struct3 {
    /* 0x00 */ struct Struct3 *next;
    /* 0x04 */ OSMesgQueue *unk_04;
    /* 0x08 */ s32 unk_08;
} Struct3; // size = 0x4

typedef struct Struct5 {
    /* 0x00000 */ Gfx unk_00[0x39C9];
} Struct5; // size = 0x1CE48

typedef struct Struct4 {
    /* 0x00000 */ Struct5 unk_00[2];
    /* 0x39C90 */ s16 unk_39C90;
    /* 0x39C92 */ u16 unk_39C92;
    /* 0x39C94 */ s32 unk_39C94;
    /* 0x39C98 */ s32 unk_39C98;
    /* 0x39C9C */ char unk_39C9C[0x76C78 - 0x39C9C];
    /* 0x76C78 */ s32 unk_76C78;
    /* 0x76C7C */ s32 unk_76C7C;
    /* 0x76C80 */ s32 unk_76C80;
    /* 0x76C84 */ s32 unk_76C84;
    /* 0x76C88 */ s32 unk_76C88;
    /* 0x76C8C */ char unk_76C8C[0x80C90 - 0x76C8C];
} Struct4; // size = 0x80C90

typedef struct Struct7 {
    /* 0x00 */ char unk_00[0x1980];
} Struct7; // size = 0x1980

typedef struct HeapChunk {
    /* 0x00 */ struct HeapChunk *next;
    /* 0x04 */ void *data;
    /* 0x08 */ s32 size;
    /* 0x0C */ struct HeapChunk **unk_0C;
} HeapChunk; // size = 0x10

#endif
