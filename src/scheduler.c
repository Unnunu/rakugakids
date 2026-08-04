#include "common.h"

/* .bss */

Scheduler D_80035FC0;
OSMesgQueue *D_80037458;
s32 D_8003745C_unused; // split ?
OSIoMesg D_80037460;
s32 D_80037478_unused; // split ?
u8 D_80037480[0x2000];
u8 D_80039480[0x2000];
u8 D_8003B480[0x2000];
u8 D_8003D480[0x2000];
u8 D_8003F480[0x2000];
u8 D_80041480[0x2000];

void func_80002370(Scheduler *, u16 *, s32);

void func_8000214C(Scheduler *);
void func_800023DC(Scheduler *);
void func_80002570(Scheduler *);
void func_8000276C(Scheduler *);
void func_80002938(void *);
void func_80002D50(void *);

void func_80001E20(Scheduler *arg0, u8 videoMode, u8 retraceCount) {

    mem_clear(arg0, sizeof(Scheduler));

    arg0->unk_1474 = NULL;
    arg0->unk_1478 = NULL;
    arg0->unk_147C = NULL;
    arg0->unk_E70 = NULL;
    arg0->unk_1484 = 0;
    arg0->unk_1480 = 0;
    arg0->unk_1488 = 5;
    arg0->unk_148C = 1;

    arg0->unk_00 = 1;
    arg0->unk_02 = 2;
    arg0->unk_04 = 3;
    arg0->unk_06 = 4;
    arg0->unk_08 = 5;

    arg0->unk_1494 = 0;

    osCreateMesgQueue(&arg0->queueSync, arg0->unk_2FC, ARRAY_COUNT(arg0->unk_2FC));
    osCreateMesgQueue(&arg0->queueSP, arg0->unk_334, ARRAY_COUNT(arg0->unk_334));
    osCreateMesgQueue(&arg0->queueDP, arg0->unk_36C, ARRAY_COUNT(arg0->unk_36C));

    osCreateMesgQueue(&arg0->unk_44, arg0->unk_5C, ARRAY_COUNT(arg0->unk_5C));
    osCreateMesgQueue(&arg0->unk_194, arg0->unk_1AC, ARRAY_COUNT(arg0->unk_1AC));
    osCreateMesgQueue(&arg0->unk_C, arg0->unk_24, ARRAY_COUNT(arg0->unk_24));
    osCreateMesgQueue(&arg0->unk_7C, arg0->unk_94, ARRAY_COUNT(arg0->unk_94));
    osCreateMesgQueue(&arg0->unk_1CC, arg0->unk_1E4, ARRAY_COUNT(arg0->unk_1E4));
    osCreateMesgQueue(&arg0->unk_414, arg0->unk_42C, ARRAY_COUNT(arg0->unk_42C));
    osCreateMesgQueue(&arg0->unk_38C, arg0->unk_3A4, ARRAY_COUNT(arg0->unk_3A4));
    osCreateMesgQueue(&arg0->unk_3DC, arg0->unk_3F4, ARRAY_COUNT(arg0->unk_3F4));
    osCreateMesgQueue(&arg0->unk_3F8, arg0->unk_410, ARRAY_COUNT(arg0->unk_410));

    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[videoMode]);
    osViBlack(1);
    osViSetEvent(&arg0->queueSync, (OSMesg) 666, retraceCount);
    osSetEventMesg(OS_EVENT_SP, &arg0->queueSP, (OSMesg) 668);
    osSetEventMesg(OS_EVENT_DP, &arg0->queueDP, (OSMesg) 669);
    osSetEventMesg(OS_EVENT_PRENMI, &arg0->queueSync, (OSMesg) 670);

    osCreateThread(&arg0->unk_450, 19, func_8000214C, arg0, D_80037480 + sizeof(D_80037480), 120);
    osStartThread(&arg0->unk_450);
    osCreateThread(&arg0->unk_600, 18, func_800023DC, arg0, D_80039480 + sizeof(D_80039480), 110);
    osStartThread(&arg0->unk_600);
    osCreateThread(&arg0->unk_B10, 17, func_8000276C, arg0, D_8003F480 + sizeof(D_8003F480), 100);
    osStartThread(&arg0->unk_B10);
    osCreateThread(&arg0->unk_7B0, 16, func_80002570, arg0, D_8003B480 + sizeof(D_8003B480), 90);
    osStartThread(&arg0->unk_7B0);
    osCreateThread(&arg0->unk_CC0, 15, func_80002D50, arg0, D_80041480 + sizeof(D_80041480), 5);
    osStartThread(&arg0->unk_CC0);
    osCreateThread(&arg0->unk_960, 14, func_80002938, arg0, D_8003D480 + sizeof(D_8003D480), 10);
    osStartThread(&arg0->unk_960);
}

OSMesgQueue *func_80002134(Scheduler *arg0) {
    return &arg0->unk_C;
}

OSMesgQueue *func_8000213C(Scheduler *arg0) {
    return &arg0->unk_44;
}

s32 func_80002144(Scheduler *arg0) {
    return arg0->unk_1480;
}

void func_8000214C(Scheduler *arg0) {
    OSMesg mesg = 0;

    while (TRUE) {
        osRecvMesg(&arg0->queueSync, &mesg, OS_MESG_BLOCK);

        switch ((s32) mesg) {
            case 666:
                func_80002370(arg0, &arg0->unk_00, 1);
                break;
            case 668:
                func_80002370(arg0, &arg0->unk_04, 2);
                break;
            case 669:
                func_80002370(arg0, &arg0->unk_06, 4);
                break;
            case 800:
                func_80002370(arg0, &arg0->unk_08, 16);
                break;
            case 670:
                func_80002370(arg0, &arg0->unk_02, 8);
                break;
        }
    }
}

void func_8000228C(Scheduler *arg0, Struct3 *arg1, OSMesgQueue *arg2, s32 arg3) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    arg1->unk_04 = arg2;
    arg1->next = arg0->unk_E70;
    arg1->unk_08 = arg3;
    arg0->unk_E70 = arg1;

    osSetIntMask(mask);
}

void func_800022E8(Scheduler *arg0, Struct3 *arg1) {
    Struct3 *sp1C;
    Struct3 *sp18;
    OSIntMask mask;

    sp1C = arg0->unk_E70;
    sp18 = NULL;

    mask = osSetIntMask(OS_IM_NONE);

    while (sp1C != NULL) {
        if (sp1C == arg1) {
            if (sp18 != NULL) {
                sp18->next = arg1->next;
            } else {
                arg0->unk_E70 = arg1->next;
            }
            break;
        }

        sp18 = sp1C;
        sp1C = sp1C->next;
    }

    osSetIntMask(mask);
}

void func_80002370(Scheduler *arg0, u16 *arg1, s32 arg2) {
    Struct3 *s0;

    for (s0 = arg0->unk_E70; s0 != NULL; s0 = s0->next) {
        if (s0->unk_08 & arg2) {
            osSendMesg(s0->unk_04, (OSMesg) arg1, OS_MESG_NOBLOCK);
        }
    }
}

void func_800023DC(Scheduler *arg0) {
    s32 sp64;
    Struct6 *sp60;
    Struct6 *s3;
    u32 s1;
    s32 pad[3];

    sp64 = NULL;
    sp60 = NULL;
    s1 = 0;

    while (TRUE) {
        osRecvMesg(&arg0->unk_C, (OSMesg *) &sp60, OS_MESG_BLOCK);
        osWritebackDCacheAll();

        s3 = arg0->unk_1474;
        if (s3 != NULL) {
            osSpTaskYield();
            osRecvMesg(&arg0->queueSP, (OSMesg *) &sp64, OS_MESG_BLOCK);

            s1 = (osSpTaskYielded(&s3->unk_10) != 0) ? 1 : 2;
        }

        arg0->unk_1478 = sp60;
        osSpTaskStart(&sp60->unk_10);
        osRecvMesg(&arg0->queueSP, (OSMesg *) &sp64, OS_MESG_BLOCK);
        arg0->unk_1478 = NULL;

        if (arg0->unk_147C != NULL) {
            osSendMesg(&arg0->unk_414, (OSMesg *) &sp64, OS_MESG_BLOCK);
        }

        if (s1 == 1) {
            osSpTaskStart(&s3->unk_10);
        } else if (s1 == 2) {
            osSendMesg(&arg0->queueSP, (OSMesg *) &sp64, OS_MESG_BLOCK);
        }

        osSendMesg(sp60->unk_50, sp60->unk_54, OS_MESG_BLOCK);
        s1 = 0;
    }
}

void func_80002570(Scheduler *arg0) {
    void *sp5C;
    Struct6 *sp58;
    Struct3 sp4C;

    sp5C = NULL;

    while (TRUE) {
        osRecvMesg(&arg0->unk_44, (OSMesg *) &sp58, OS_MESG_BLOCK);

        while (osViGetCurrentFramebuffer() == sp58->unk_0C || osViGetNextFramebuffer() == sp58->unk_0C) {
            func_8000228C(arg0, &sp4C, &arg0->unk_414, 1);
            osRecvMesg(&arg0->unk_414, (OSMesg *) &sp5C, OS_MESG_BLOCK);
            func_800022E8(arg0, &sp4C);
        }

        if (arg0->unk_1478 != NULL) {
            arg0->unk_147C = sp58;
            osRecvMesg(&arg0->unk_414, (OSMesg *) &sp5C, OS_MESG_BLOCK);
            arg0->unk_147C = NULL;
        }

        arg0->unk_1474 = sp58;
        osSpTaskStart(&sp58->unk_10);
        osRecvMesg(&arg0->queueSP, (OSMesg *) &sp5C, OS_MESG_BLOCK);
        osSendMesg(&arg0->queueSync, (OSMesg) sp5C, OS_MESG_BLOCK);
        arg0->unk_1474 = NULL;

        osRecvMesg(&arg0->queueDP, (OSMesg *) &sp5C, OS_MESG_BLOCK);

        if (arg0->unk_1488 != 0) {
            arg0->unk_1488--;
            if (arg0->unk_1488 == 0) {
                osViBlack(0);
            }
        }

        if (sp58->unk_08 & 0x40) {
            osSendMesg(&arg0->unk_194, (OSMesg) sp58, OS_MESG_BLOCK);
            arg0->unk_1484--;
        }
        osSendMesg(&arg0->queueSync, (OSMesg) sp5C, OS_MESG_BLOCK);
    }
}

void func_8000276C(Scheduler *arg0) {
    void *sp54;
    Struct6 *sp50;
    Struct3 sp44;

    sp54 = NULL;

    while (TRUE) {
        osRecvMesg(&arg0->unk_194, (OSMesg *) &sp50, OS_MESG_BLOCK);

        if (arg0->unk_148C == 0) {
            while (osViGetCurrentFramebuffer() != osViGetNextFramebuffer()) {
                func_8000228C(arg0, &sp44, &arg0->unk_38C, 1);
                osRecvMesg(&arg0->unk_38C, (OSMesg *) &sp54, OS_MESG_BLOCK);
                func_800022E8(arg0, &sp44);
            }
        } else {
            arg0->unk_148C = 0;
        }

        osViSwapBuffer(sp50->unk_0C);
    }
}

s32 func_80002888(Scheduler *arg0) {
    return arg0->unk_1484;
}

void func_80002890(Scheduler *arg0, Struct6 *arg1) {
    s32 pad;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    if (arg0->unk_1484 < 2U) {
        if (arg1->unk_08 & 0x40) {
            arg0->unk_1480 ^= 1;
            arg0->unk_1484++;
        }

        osSendMesg(&arg0->queueSync, (OSMesg) 800, OS_MESG_BLOCK);
        osSendMesg(&arg0->unk_44, (OSMesg) arg1, OS_MESG_BLOCK);

        osSetIntMask(mask);
    }
}

void func_80002928(Scheduler *arg0) {
    arg0->unk_1484 += 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002B64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002C94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002D30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80002D50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_800030C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/scheduler/func_80003108.s")
