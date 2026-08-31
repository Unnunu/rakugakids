#ifndef _COMMON_STRUCTS_H
#define _COMMON_STRUCTS_H

typedef struct HeapChunk {
    /* 0x00 */ struct HeapChunk *next;
    /* 0x04 */ void *data;
    /* 0x08 */ s32 size;
    /* 0x0C */ struct HeapChunk **unk_0C;
} HeapChunk; // size = 0x10

typedef struct ScTask {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ void *fb;
    /* 0x10 */ OSTask osTask;
    /* 0x50 */ OSMesgQueue *unk_50;
    /* 0x54 */ OSMesg unk_54;
} ScTask; // size = 0x58

typedef struct Asset {
    /* 0x00 */ u32 fileId;
    /* 0x04 */ u32 uncompressedSize;
    /* 0x08 */ HeapChunk *data;
} Asset; // size >= 0xC

typedef struct SchedulerSub {
    /* 0x00 */ s32 mode;
    /* 0x04 */ s32 index;
    /* 0x08 */ OSMesgQueue *queue;
    /* 0x0C */ Asset *unk_0C;
} SchedulerSub; // size = 0x10

typedef struct Scheduler {
    /* 0x0000 */ u16 unk_00;
    /* 0x0002 */ u16 unk_02;
    /* 0x0004 */ u16 unk_04;
    /* 0x0006 */ u16 unk_06;
    /* 0x0008 */ u16 unk_08;
    /* 0x000A */ s16 unk_0A;
    /* 0x000C */ OSMesgQueue audioTaskQueue;
    /* 0x0024 */ OSMesg audioTaskMsgs[8];
    /* 0x0044 */ OSMesgQueue gfxTaskQueue;
    /* 0x005C */ OSMesg gfxTaskMsgs[8];
    /* 0x007C */ OSMesgQueue dmaQueue;
    /* 0x0094 */ OSMesg dmaMesgs[64];
    /* 0x0194 */ OSMesgQueue unk_194;
    /* 0x01AC */ OSMesg unk_1AC[8];
    /* 0x01CC */ OSMesgQueue unk_1CC;
    /* 0x01E4 */ OSMesg unk_1E4[64];
    /* 0x02E4 */ OSMesgQueue eventQueue;
    /* 0x02FC */ OSMesg unk_2FC[8];
    /* 0x031C */ OSMesgQueue queueSPComplete;
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
    /* 0x0E70 */ struct ScClient *clientList;
    /* 0x0E74 */ HeapChunk *dmaRequests[0x40];
    /* 0x0F74 */ SchedulerSub unk_F74[0x40];
    /* 0x1374 */ HeapChunk *unk_1374[0x40];
    /* 0x1474 */ ScTask *gfxTask;
    /* 0x1478 */ ScTask *audioTask;
    /* 0x147C */ ScTask *unk_147C;
    /* 0x1480 */ s32 unk_1480;
    /* 0x1484 */ s32 unk_1484;
    /* 0x1488 */ s32 unk_1488;
    /* 0x148C */ s32 unk_148C;
    /* 0x1490 */ s32 isDmaBusy;
    /* 0x1494 */ s32 unk_1494;
} Scheduler; // size = 0x1498

typedef struct ScClient {
    /* 0x00 */ struct ScClient *next;
    /* 0x04 */ OSMesgQueue *queue;
    /* 0x08 */ s32 mask;
} ScClient; // size = 0x4

typedef struct StructOvl2B {
    /* 0x000 */ Mtx mtxProjection;
    /* 0x040 */ Mtx mtxView;
    /* 0x080 */ Mtx mtxRotateX;
    /* 0x0C0 */ Mtx mtxRotateY;
    /* 0x100 */ Mtx mtxRotateZ;
    /* 0x140 */ Mtx unk_140;
} StructOvl2B; // size = 0x180

typedef struct Struct5 {
    /* 0x00000 */ Gfx unk_00[0x800];
    /* 0x04000 */ Gfx unk_4000[4];
    /* 0x04020 */ char unk_4020[0x1C800 - 0x04020];
    /* 0x1C800 */ s32 unk_1C800[4];
    /* 0x1C810 */ Gfx *unk_1C810[4];
    /* 0x1C820 */ Gfx *unk_1C820[4];
    /* 0x1C830 */ Gfx *unk_1C830[4];
    /* 0x1C840 */ HeapChunk *unk_1C840;
    /* 0x1C844 */ char unk_1C844[4];
    /* 0x1C848 */ StructOvl2B unk_1C848[4];
} Struct5; // size = 0x1CE48

typedef struct Struct4Sub1Sub {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} Struct4Sub1Sub; // size = 4

typedef struct InputData {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s8 unk_0E;
    /* 0x0F */ s8 unk_0F;
    /* 0x10 */ Struct4Sub1Sub unk_10[20];
} InputData; // size = 0x60

typedef struct Struct4Sub2 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ s32 unk_0C;
} Struct4Sub2; // size = 0x10

typedef struct CameraSettings {
    /* 0x00 */ u16 id;
    /* 0x04 */ void (*updateFunc)(struct CameraSettings *);
    /* 0x08 */ u8 flags;
    /* 0x0C */ f32 xEye;
    /* 0x10 */ f32 yEye;
    /* 0x14 */ f32 zEye;
    /* 0x18 */ f32 xAt;
    /* 0x1C */ f32 yAt;
    /* 0x20 */ f32 zAt;
    /* 0x24 */ f32 xUp;
    /* 0x28 */ f32 yUp;
    /* 0x2C */ s32 zUp;
    /* 0x30 */ f32 xAngle;
    /* 0x34 */ f32 yAngle;
    /* 0x38 */ f32 zAngle;
    /* 0x3C */ f32 fovy;
    /* 0x40 */ f32 aspect;
    /* 0x44 */ f32 near;
    /* 0x48 */ f32 far;
    /* 0x4C */ f32 scale;
    /* 0x50 */ f32 left;
    /* 0x54 */ f32 right;
    /* 0x58 */ f32 bottom;
    /* 0x5C */ f32 top;
    /* 0x60 */ Vp *viewport;
    /* 0x64 */ s32 scisLeft;
    /* 0x68 */ s32 scisTop;
    /* 0x6C */ s32 scisRight;
    /* 0x70 */ s32 scisBottom;
} CameraSettings; // size = 0x74

typedef struct Struct4Sub5 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ struct Struct4Sub5 *unk_04;
    /* 0x08 */ Struct4Sub2 *unk_08;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ f32 unk_10;
} Struct4Sub5; // size = 0x14

typedef struct Struct4Sub4 {
    /* 0x00 */ Struct4Sub5 *unk_00;
    /* 0x04 */ s32 unk_04;
} Struct4Sub4; // size = 0x8

typedef struct Struct4 {
    /* 0x00000 */ Struct5 unk_00[2];
    /* 0x39C90 */ s16 cfbIdx;
    /* 0x39C92 */ u16 bitDepth;
    /* 0x39C94 */ s32 flags;
    /* 0x39C98 */ u32 frameCounter;
    /* 0x39C9C */ u8 unk_39C9C;
    /* 0x39C9D */ u8 unk_39C9D;
    /* 0x39C9E */ InputData inputs[4];
    /* 0x39E1E */ char unk_39E1E[2]; // padding?
    /* 0x39E20 */ CameraSettings cameras[4];
    /* 0x39FF0 */ char unk_39FF0[0x757F0 - 0x39FF0];
    /* 0x757F0 */ void (*unk_757F0)(void);
    /* 0x757F4 */ Struct4Sub2 unk_757F4[0x40];
    /* 0x75BF4 */ s32 unk_75BF4;
    /* 0x75BF8 */ u8 unk_75BF8[0xD00];
    /* 0x768F8 */ Struct4Sub4 unk_768F8[1];
    /* 0x76900 */ char unk_76900[0x76C78 - 0x76900];
    /* 0x76C78 */ s32 unk_76C78;
    /* 0x76C7C */ u32 unk_76C7C;
    /* 0x76C80 */ s32 unk_76C80;
    /* 0x76C84 */ s32 unk_76C84;
    /* 0x76C88 */ s32 unk_76C88;
    /* 0x76C8C */ char unk_76C8C[0x80C90 - 0x76C8C];
} Struct4; // size = 0x80C90

typedef struct AudioConfig {
    /* 0x00 */ s32 frequency;
    /* 0x04 */ u32 freqMultiplier;
    /* 0x08 */ s32 maxCommands;
} AudioConfig; // size >= 0xC

typedef struct Overlay {
    /* 0x00 */ s32 romStart;
    /* 0x04 */ s32 romEnd;
    /* 0x08 */ s32 vramAddr;
    /* 0x0C */ s32 (*runFunc)(s32);
} Overlay; // size = 0x10

typedef struct StructD48 {
    /* 0x000 */ s32 romAddr;
    /* 0x004 */ u32 romPtr;
    /* 0x008 */ u32 romEnd;
    /* 0x00C */ u8 *inBufPtr;
    /* 0x010 */ u8 *outBufPtr;
    /* 0x014 */ s32 size;
    /* 0x018 */ s32 batchSize;
    /* 0x01C */ s32 unk_1C;
    /* 0x020 */ s32 offset;
    /* 0x024 */ s32 unk_24;
    /* 0x028 */ u8 buffer[0xD00];
    /* 0xD28 */ OSMesgQueue unk_D28;
    /* 0xD40 */ OSMesg unk_D40[1];
    /* 0xD44 */ s32 unk_D44;
} StructD48; // size = 0xD48

typedef struct HuffmanTreeNode {
    /* 0x00 */ u16 frequency;
    /* 0x00 */ u16 leftChild;
    /* 0x00 */ u16 rightChild;
} HuffmanTreeNode; // size = 0x6

typedef struct HuffmanTree {
    /* 0x0000 */ s32 romPtr;
    /* 0x0004 */ u8 *outPtr;
    /* 0x0008 */ s32 bufIndex;
    /* 0x000C */ HuffmanTreeNode tree[0x204];
    /* 0x0C24 */ u32 wordValue;
    /* 0x0C28 */ u32 bitMask;
    /* 0x0C2C */ s32 rootIndex;
    /* 0x0C30 */ u8 buffer[0xD00];
    /* 0x1930 */ OSMesgQueue unk_1930;
    /* 0x1948 */ OSMesg unk_1948[1];
    /* 0x194C */ s32 unk_194C;
} HuffmanTree; // size = 0x1950

#endif
