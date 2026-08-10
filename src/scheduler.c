#include "common.h"

/* .bss */

Scheduler gScheduler;
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

void sched_notify_clients(Scheduler *, u16 *, s32);

void sched_event_loop(Scheduler *);
void sched_audio_rsp_loop(Scheduler *);
void sched_gfx_rsp_loop(Scheduler *);
void func_8000276C(Scheduler *);
void func_80002938(void *);
void func_80002D50(void *);

void sched_init(Scheduler *arg0, u8 videoMode, u8 retraceCount) {

    mem_clear(arg0, sizeof(Scheduler));

    arg0->gfxTask = NULL;
    arg0->audioTask = NULL;
    arg0->unk_147C = NULL;
    arg0->clientList = NULL;
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

    osCreateMesgQueue(&arg0->eventQueue, arg0->unk_2FC, ARRAY_COUNT(arg0->unk_2FC));
    osCreateMesgQueue(&arg0->queueSPComplete, arg0->unk_334, ARRAY_COUNT(arg0->unk_334));
    osCreateMesgQueue(&arg0->queueDP, arg0->unk_36C, ARRAY_COUNT(arg0->unk_36C));

    osCreateMesgQueue(&arg0->gfxTaskQueue, arg0->unk_5C, ARRAY_COUNT(arg0->unk_5C));
    osCreateMesgQueue(&arg0->unk_194, arg0->unk_1AC, ARRAY_COUNT(arg0->unk_1AC));
    osCreateMesgQueue(&arg0->audioTaskQueue, arg0->unk_24, ARRAY_COUNT(arg0->unk_24));
    osCreateMesgQueue(&arg0->unk_7C, arg0->unk_94, ARRAY_COUNT(arg0->unk_94));
    osCreateMesgQueue(&arg0->unk_1CC, arg0->unk_1E4, ARRAY_COUNT(arg0->unk_1E4));
    osCreateMesgQueue(&arg0->unk_414, arg0->unk_42C, ARRAY_COUNT(arg0->unk_42C));
    osCreateMesgQueue(&arg0->unk_38C, arg0->unk_3A4, ARRAY_COUNT(arg0->unk_3A4));
    osCreateMesgQueue(&arg0->unk_3DC, arg0->unk_3F4, ARRAY_COUNT(arg0->unk_3F4));
    osCreateMesgQueue(&arg0->unk_3F8, arg0->unk_410, ARRAY_COUNT(arg0->unk_410));

    osCreateViManager(OS_PRIORITY_VIMGR);
    osViSetMode(&osViModeTable[videoMode]);
    osViBlack(1);
    osViSetEvent(&arg0->eventQueue, (OSMesg) 666, retraceCount);
    osSetEventMesg(OS_EVENT_SP, &arg0->queueSPComplete, (OSMesg) 668);
    osSetEventMesg(OS_EVENT_DP, &arg0->queueDP, (OSMesg) 669);
    osSetEventMesg(OS_EVENT_PRENMI, &arg0->eventQueue, (OSMesg) 670);

    osCreateThread(&arg0->unk_450, 19, sched_event_loop, arg0, D_80037480 + sizeof(D_80037480), 120);
    osStartThread(&arg0->unk_450);
    osCreateThread(&arg0->unk_600, 18, sched_audio_rsp_loop, arg0, D_80039480 + sizeof(D_80039480), 110);
    osStartThread(&arg0->unk_600);
    osCreateThread(&arg0->unk_B10, 17, func_8000276C, arg0, D_8003F480 + sizeof(D_8003F480), 100);
    osStartThread(&arg0->unk_B10);
    osCreateThread(&arg0->unk_7B0, 16, sched_gfx_rsp_loop, arg0, D_8003B480 + sizeof(D_8003B480), 90);
    osStartThread(&arg0->unk_7B0);
    osCreateThread(&arg0->unk_CC0, 15, func_80002D50, arg0, D_80041480 + sizeof(D_80041480), 5);
    osStartThread(&arg0->unk_CC0);
    osCreateThread(&arg0->unk_960, 14, func_80002938, arg0, D_8003D480 + sizeof(D_8003D480), 10);
    osStartThread(&arg0->unk_960);
}

OSMesgQueue *func_80002134(Scheduler *arg0) {
    return &arg0->audioTaskQueue;
}

OSMesgQueue *func_8000213C(Scheduler *arg0) {
    return &arg0->gfxTaskQueue;
}

s32 func_80002144(Scheduler *arg0) {
    return arg0->unk_1480;
}

void sched_event_loop(Scheduler *arg0) {
    OSMesg mesg = 0;

    while (TRUE) {
        osRecvMesg(&arg0->eventQueue, &mesg, OS_MESG_BLOCK);

        switch ((s32) mesg) {
            case 666:
                sched_notify_clients(arg0, &arg0->unk_00, 1);
                break;
            case 668:
                sched_notify_clients(arg0, &arg0->unk_04, 2);
                break;
            case 669:
                sched_notify_clients(arg0, &arg0->unk_06, 4);
                break;
            case 800:
                sched_notify_clients(arg0, &arg0->unk_08, 16);
                break;
            case 670:
                sched_notify_clients(arg0, &arg0->unk_02, 8);
                break;
        }
    }
}

void sched_register_client(Scheduler *sc, ScClient *client, OSMesgQueue *queue, s32 eventMask) {
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    client->queue = queue;
    client->next = sc->clientList;
    client->mask = eventMask;
    sc->clientList = client;

    osSetIntMask(mask);
}

void sched_unregister_client(Scheduler *sc, ScClient *client) {
    ScClient *sp1C;
    ScClient *sp18;
    OSIntMask mask;

    sp1C = sc->clientList;
    sp18 = NULL;

    mask = osSetIntMask(OS_IM_NONE);

    while (sp1C != NULL) {
        if (sp1C == client) {
            if (sp18 != NULL) {
                sp18->next = client->next;
            } else {
                sc->clientList = client->next;
            }
            break;
        }

        sp18 = sp1C;
        sp1C = sp1C->next;
    }

    osSetIntMask(mask);
}

void sched_notify_clients(Scheduler *sc, u16 *mesg, s32 event) {
    ScClient *client;

    for (client = sc->clientList; client != NULL; client = client->next) {
        if (client->mask & event) {
            osSendMesg(client->queue, (OSMesg) mesg, OS_MESG_NOBLOCK);
        }
    }
}

void sched_audio_rsp_loop(Scheduler *arg0) {
    s32 mesg;
    ScTask *task;
    ScTask *s3;
    u32 s1;
    s32 pad[3];

    mesg = NULL;
    task = NULL;
    s1 = 0;

    while (TRUE) {
        osRecvMesg(&arg0->audioTaskQueue, (OSMesg *) &task, OS_MESG_BLOCK);
        osWritebackDCacheAll();

        s3 = arg0->gfxTask;
        if (s3 != NULL) {
            osSpTaskYield();
            osRecvMesg(&arg0->queueSPComplete, (OSMesg *) &mesg, OS_MESG_BLOCK);

            s1 = (osSpTaskYielded(&s3->osTask) != 0) ? 1 : 2;
        }

        arg0->audioTask = task;
        osSpTaskStart(&task->osTask);
        osRecvMesg(&arg0->queueSPComplete, (OSMesg *) &mesg, OS_MESG_BLOCK);
        arg0->audioTask = NULL;

        if (arg0->unk_147C != NULL) {
            osSendMesg(&arg0->unk_414, (OSMesg *) &mesg, OS_MESG_BLOCK);
        }

        if (s1 == 1) {
            osSpTaskStart(&s3->osTask);
        } else if (s1 == 2) {
            osSendMesg(&arg0->queueSPComplete, (OSMesg *) &mesg, OS_MESG_BLOCK);
        }

        osSendMesg(task->unk_50, task->unk_54, OS_MESG_BLOCK);
        s1 = 0;
    }
}

void sched_gfx_rsp_loop(Scheduler *arg0) {
    void *mesg;
    ScTask *task;
    ScClient sp4C;

    mesg = NULL;

    while (TRUE) {
        osRecvMesg(&arg0->gfxTaskQueue, (OSMesg *) &task, OS_MESG_BLOCK);

        while (osViGetCurrentFramebuffer() == task->fb || osViGetNextFramebuffer() == task->fb) {
            sched_register_client(arg0, &sp4C, &arg0->unk_414, 1);
            osRecvMesg(&arg0->unk_414, (OSMesg *) &mesg, OS_MESG_BLOCK);
            sched_unregister_client(arg0, &sp4C);
        }

        if (arg0->audioTask != NULL) {
            arg0->unk_147C = task;
            osRecvMesg(&arg0->unk_414, (OSMesg *) &mesg, OS_MESG_BLOCK);
            arg0->unk_147C = NULL;
        }

        arg0->gfxTask = task;
        osSpTaskStart(&task->osTask);
        osRecvMesg(&arg0->queueSPComplete, (OSMesg *) &mesg, OS_MESG_BLOCK);
        osSendMesg(&arg0->eventQueue, (OSMesg) mesg, OS_MESG_BLOCK);
        arg0->gfxTask = NULL;

        osRecvMesg(&arg0->queueDP, (OSMesg *) &mesg, OS_MESG_BLOCK);

        if (arg0->unk_1488 != 0) {
            arg0->unk_1488--;
            if (arg0->unk_1488 == 0) {
                osViBlack(0);
            }
        }

        if (task->unk_08 & 0x40) {
            osSendMesg(&arg0->unk_194, (OSMesg) task, OS_MESG_BLOCK);
            arg0->unk_1484--;
        }
        osSendMesg(&arg0->eventQueue, (OSMesg) mesg, OS_MESG_BLOCK);
    }
}

void func_8000276C(Scheduler *arg0) {
    void *sp54;
    ScTask *sp50;
    ScClient sp44;

    sp54 = NULL;

    while (TRUE) {
        osRecvMesg(&arg0->unk_194, (OSMesg *) &sp50, OS_MESG_BLOCK);

        if (arg0->unk_148C == 0) {
            while (osViGetCurrentFramebuffer() != osViGetNextFramebuffer()) {
                sched_register_client(arg0, &sp44, &arg0->unk_38C, 1);
                osRecvMesg(&arg0->unk_38C, (OSMesg *) &sp54, OS_MESG_BLOCK);
                sched_unregister_client(arg0, &sp44);
            }
        } else {
            arg0->unk_148C = 0;
        }

        osViSwapBuffer(sp50->fb);
    }
}

s32 func_80002888(Scheduler *arg0) {
    return arg0->unk_1484;
}

void func_80002890(Scheduler *arg0, ScTask *arg1) {
    s32 pad;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    if (arg0->unk_1484 < 2U) {
        if (arg1->unk_08 & 0x40) {
            arg0->unk_1480 ^= 1;
            arg0->unk_1484++;
        }

        osSendMesg(&arg0->eventQueue, (OSMesg) 800, OS_MESG_BLOCK);
        osSendMesg(&arg0->gfxTaskQueue, (OSMesg) arg1, OS_MESG_BLOCK);

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
