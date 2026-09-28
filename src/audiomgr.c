#include "common.h"

#define AUDIO_CACHE_SIZE 0x800
// TODO: make audio rsp ucode
extern u64 D_80026910[];
extern u64 D_8002F790[];

struct UnkAudioBeta;
typedef struct AudioCompletionMesg {
    /* 0x00 */ s16 unk_00;
    /* 0x04 */ struct UnkAudioBeta *unk_04;
} AudioCompletionMesg; // size = 0x8

typedef struct UnkAudioBeta {
    /* 0x00 */ u8 *unk_00;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ ScTask unk_08;
    /* 0x60 */ AudioCompletionMesg unk_60;
} UnkAudioBeta; // size = 0x68

typedef struct AudioCacheEntry {
    /* 0x00 */ ALLink node;
    /* 0x08 */ u32 rom_addr;
    /* 0x0C */ u32 unk_0C;
    /* 0x10 */ u8 *vram_addr;
} AudioCacheEntry; // size = 0x14

typedef struct UnkAudioEpsilon {
    /* 0x00 */ Acmd *cmdBuffers[2];
    /* 0x08 */ UnkAudioBeta *unk_08[3];
} UnkAudioEpsilon;

typedef struct AudioCache {
    /* 0x00 */ u8 unk_00;
    /* 0x04 */ AudioCacheEntry *unk_04;
    /* 0x08 */ AudioCacheEntry *unk_08;
} AudioCache; // size >= 0xC

extern u32 D_8002A440;
extern s32 D_8002A444;
extern s32 D_8002A448;
extern s32 D_8002A44C;

extern OSMesgQueue *D_80050580;
extern UnkAudioEpsilon D_80050588;
extern OSThread D_800505A0;
extern OSMesgQueue D_80050750;
extern OSMesg D_80050768[64];
extern OSMesgQueue D_80050868;
extern OSMesg D_80050880[64];
extern ALGlobals D_80050980;
extern u8 D_800509D0[0x4000];
extern AudioCache D_800549D0;
extern AudioCacheEntry D_800549E0[40];
extern u32 D_80054D00;
extern u32 D_80054D04;
extern u32 D_80054D08;
extern s32 D_80054D0C;
extern OSIoMesg D_80054D10[];
extern OSMesgQueue D_80055310;
extern OSMesg D_80055328[64];

ALDMAproc func_800110D4(void **state);
void func_80010BF8(void *);
s32 func_80010D70(UnkAudioBeta *, UnkAudioBeta *);
void func_80010F18(UnkAudioBeta *);
void func_8001110C(void);

void func_800108F0(ALSynConfig *synConfig, s32 arg1, AudioConfig *arg2) {
    f32 tmp;
    u32 i;

    synConfig->dmaproc = func_800110D4;
    synConfig->outputRate = osAiSetFrequency(arg2->frequency);

    for (i = 16; i > 0; i--) {}

    tmp = (f32) arg2->freqMultiplier * (f32) synConfig->outputRate / 60.0f;
    D_80054D04 = (s32) tmp;
    if ((f32) D_80054D04 < (f32) tmp) {
        D_80054D04++;
    }
    if (D_80054D04 & 0xF) {
        D_80054D04 = (D_80054D04 & ~0xF) + 0x10;
    }
    D_80054D00 = D_80054D04 - 0x10;
    D_80054D08 = D_80054D04 + 0x100;

    alInit(&D_80050980, synConfig);

    D_800549E0[0].node.prev = NULL;
    D_800549E0[0].node.next = NULL;

    for (i = 0; i < ARRAY_COUNT(D_800549E0) - 1; i++) {
        alLink(&D_800549E0[i + 1].node, &D_800549E0[i].node);
        D_800549E0[i].vram_addr = alHeapAlloc(synConfig->heap, 1, AUDIO_CACHE_SIZE);
    }
    D_800549E0[i].vram_addr = alHeapAlloc(synConfig->heap, 1, AUDIO_CACHE_SIZE);

    for (i = 0; i < ARRAY_COUNT(D_80050588.cmdBuffers); i++) {
        D_80050588.cmdBuffers[i] = alHeapAlloc(synConfig->heap, 1, arg2->maxCommands * 8);
    }

    D_80054D0C = arg2->maxCommands;

    for (i = 0; i < ARRAY_COUNT(D_80050588.unk_08); i++) {
        D_80050588.unk_08[i] = alHeapAlloc(synConfig->heap, 1, sizeof(UnkAudioBeta));
        D_80050588.unk_08[i]->unk_60.unk_00 = 667;
        D_80050588.unk_08[i]->unk_60.unk_04 = D_80050588.unk_08[i];
        D_80050588.unk_08[i]->unk_00 = alHeapAlloc(synConfig->heap, 1, D_80054D08 * 4);
    }

    osCreateMesgQueue(&D_80050868, D_80050880, ARRAY_COUNT(D_80050880));
    osCreateMesgQueue(&D_80050750, D_80050768, ARRAY_COUNT(D_80050768));
    osCreateMesgQueue(&D_80055310, D_80055328, ARRAY_COUNT(D_80055328));

    osCreateThread(&D_800505A0, 3, func_80010BF8, NULL, D_800509D0 + sizeof(D_800509D0), arg1);
    osStartThread(&D_800505A0);
}

void func_80010BF8(void *arg) {
    u32 s0;
    UnkAudioBeta *s1;
    AudioCompletionMesg *sp54;
    s32 temp;
    ScClient sp44;

    s0 = FALSE;
    s1 = NULL;

    sched_register_client(&gScheduler, &sp44, &D_80050750, 9);
    D_80050580 = func_80002134(&gScheduler);

    while (!s0) {
        osRecvMesg(&D_80050750, (OSMesg *) &sp54, OS_MESG_BLOCK);
        switch (sp54->unk_00) {
            case 1:
                if (func_80010D70(D_80050588.unk_08[D_8002A440 % 3], s1) != 0) {
                    osRecvMesg(&D_80050868, &sp54, OS_MESG_BLOCK);
                    func_80010F18(sp54->unk_04);
                    s1 = sp54->unk_04;
                }
                break;
            case 2:
                s0 = TRUE;
                break;
            case 32:
                s0 = TRUE;
                break;
        }
    }

    alClose(&D_80050980);
}

s32 func_80010D70(UnkAudioBeta *arg0, UnkAudioBeta *arg1) {
    s16 *sp3C;
    Acmd *temp_a3;
    s32 sp34;
    s32 pad[2];

    func_8001110C();
    sp3C = (s16 *) osVirtualToPhysical(arg0->unk_00);
    if (arg1 != 0) {
        osAiSetNextBuffer(arg1->unk_00, arg1->unk_04 * 4);
    }

    arg0->unk_04 = (D_80054D04 - osAiGetLength() / 4 + 0x100) & ~0xF;
    if (arg0->unk_04 < D_80054D00) {
        arg0->unk_04 = D_80054D00;
    }

    temp_a3 = alAudioFrame(D_80050588.cmdBuffers[D_8002A448], &sp34, sp3C, arg0->unk_04);
    if (sp34 == 0) {
        return FALSE;
    }

    arg0->unk_08.unk_00 = 0;
    arg0->unk_08.unk_50 = &D_80050868;
    arg0->unk_08.unk_54 = (OSMesg) &arg0->unk_60;
    arg0->unk_08.osTask.t.data_ptr = (u64 *) D_80050588.cmdBuffers[D_8002A448];
    arg0->unk_08.osTask.t.data_size = (temp_a3 - D_80050588.cmdBuffers[D_8002A448]) * sizeof(Acmd);
    arg0->unk_08.osTask.t.type = M_AUDTASK;
    arg0->unk_08.osTask.t.ucode_boot = (u64 *) rspbootTextStart;
    arg0->unk_08.osTask.t.ucode_boot_size = (u32) rspbootTextEnd - (u32) rspbootTextStart;
    arg0->unk_08.osTask.t.flags = 0;
    arg0->unk_08.osTask.t.ucode = D_80026910;
    arg0->unk_08.osTask.t.ucode_data = D_8002F790;
    arg0->unk_08.osTask.t.ucode_data_size = SP_UCODE_DATA_SIZE;
    arg0->unk_08.osTask.t.yield_data_ptr = NULL;
    arg0->unk_08.osTask.t.yield_data_size = 0;

    osSendMesg(D_80050580, &arg0->unk_08, OS_MESG_BLOCK); // TODO: check types
    D_8002A448 ^= 1;
    return 1;
}

void func_80010F18(UnkAudioBeta *arg0) {
    s32 temp = FALSE; // required to match

    if ((osAiGetLength() / 4) == 0 && !D_8002A44C) {
        D_8002A44C = temp;
    }
}

s32 func_80010F58(s32 addr, s32 len, void *state) {
    u8 *s1;
    s32 sp40;
    s32 v1;
    AudioCacheEntry *s0;
    AudioCacheEntry *v0;
    AudioCacheEntry *a2;

    a2 = NULL;

    for (s0 = D_800549D0.unk_04; s0 != NULL; s0 = (AudioCacheEntry *) s0->node.next) {
        v1 = s0->rom_addr + AUDIO_CACHE_SIZE;
        if (s0->rom_addr > addr) {
            break;
        }

        a2 = s0;

        if (v1 >= addr + len) {
            s0->unk_0C = D_8002A440;
            s1 = s0->vram_addr + addr - s0->rom_addr;
            return osVirtualToPhysical(s1);
        }
    }

    s0 = D_800549D0.unk_08;
    D_800549D0.unk_08 = (AudioCacheEntry *) s0->node.next;
    alUnlink(&s0->node);

    if (a2 != NULL) {
        alLink(&s0->node, &a2->node);
    } else {
        v0 = D_800549D0.unk_04;
        if (v0 != NULL) {
            D_800549D0.unk_04 = s0;
            s0->node.next = v0;
            s0->node.prev = NULL;
            v0->node.prev = s0;
        } else {
            D_800549D0.unk_04 = s0;
            s0->node.next = NULL;
            s0->node.prev = NULL;
        }
    }

    s1 = s0->vram_addr;
    sp40 = addr & 1;
    addr -= sp40;
    s0->rom_addr = addr;
    s0->unk_0C = D_8002A440;

    osPiStartDma(&D_80054D10[D_8002A444++], OS_MESG_PRI_NORMAL, OS_READ, addr, s1, AUDIO_CACHE_SIZE, &D_80055310);
    return osVirtualToPhysical(s1) + sp40;
}

ALDMAproc func_800110D4(void **state) {
    if (!D_800549D0.unk_00) {
        D_800549D0.unk_04 = NULL;
        D_800549D0.unk_08 = D_800549E0;
        D_800549D0.unk_00 = TRUE;
    }

    *state = &D_800549D0;
    return func_80010F58;
}

void func_8001110C(void) {
    u32 i;
    OSMesg sp40; // TODO: type
    AudioCacheEntry *s0;
    AudioCacheEntry *v0;

    for (i = 0; i < D_8002A444; i++) {
        osRecvMesg(&D_80055310, &sp40, OS_MESG_NOBLOCK);
    }

    for (s0 = D_800549D0.unk_04; s0 != NULL;) {
        v0 = (AudioCacheEntry *) s0->node.next;
        if (s0->unk_0C + 6 < D_8002A440) {
            if (s0 == D_800549D0.unk_04) {
                D_800549D0.unk_04 = (AudioCacheEntry *) s0->node.next;
            }

            alUnlink(&s0->node);
            if (D_800549D0.unk_08 != NULL) {
                alLink(&s0->node, &D_800549D0.unk_08->node);
            } else {
                D_800549D0.unk_08 = s0;
                s0->node.next = NULL;
                s0->node.prev = NULL;
            }
        }
        s0 = v0;
    }

    D_8002A444 = 0;
    D_8002A440++;
}
