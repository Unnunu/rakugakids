#include "common.h"

typedef struct DMARequest {
    /* 0x00 */ OSIoMesg ioMesg;
    /* 0x18 */ OSMesgQueue piCompletionQueue;
    /* 0x30 */ OSMesg piMesgs[1];
    /* 0x34 */ OSMesgQueue *requestCompletionQueue;
    /* 0x38 */ u16 flags;
    /* 0x3A */ u16 batchSize;
    /* 0x3C */ u32 size;
    /* 0x40 */ s32 ramAddr;
    /* 0x44 */ s32 romAddr;
    /* 0x48 */ u16 id;
} DMARequest; // size ?

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
void sched_dma_loop(Scheduler *);
void func_80002D50(Scheduler *);
void execute_dma_request(DMARequest *arg0);

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

    osCreateMesgQueue(&arg0->gfxTaskQueue, arg0->gfxTaskMsgs, ARRAY_COUNT(arg0->gfxTaskMsgs));
    osCreateMesgQueue(&arg0->unk_194, arg0->unk_1AC, ARRAY_COUNT(arg0->unk_1AC));
    osCreateMesgQueue(&arg0->audioTaskQueue, arg0->audioTaskMsgs, ARRAY_COUNT(arg0->audioTaskMsgs));
    osCreateMesgQueue(&arg0->dmaQueue, arg0->dmaMesgs, ARRAY_COUNT(arg0->dmaMesgs));
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
    osCreateThread(&arg0->unk_960, 14, sched_dma_loop, arg0, D_8003D480 + sizeof(D_8003D480), 10);
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

void sched_dma_loop(Scheduler *arg0) {
    s32 numActiveTransfers;
    OSIoMesg *completed;
    DMARequest *request;
    s32 pad;

    completed = NULL;
    numActiveTransfers = 0;

    while (TRUE) {
        osRecvMesg(&arg0->dmaQueue, (OSMesg *) &request, OS_MESG_BLOCK);
        completed = NULL;

        if (request->flags & 1) {
            execute_dma_request(request);
            numActiveTransfers++;
            osRecvMesg(&request->piCompletionQueue, (OSMesg *) &completed, OS_MESG_BLOCK);
        } else {
            if (!(request->flags & 0x8000)) {
                execute_dma_request(request);
                numActiveTransfers++;
            }
            osRecvMesg(&request->piCompletionQueue, (OSMesg *) &completed, OS_MESG_NOBLOCK);
        }

        if (completed != NULL) {
            numActiveTransfers--;
            request->size -= request->batchSize;
            if (request->size != 0) {
                request->flags &= ~0x8000;
                request->romAddr += request->batchSize;
                request->ramAddr += request->batchSize;
                if (request->batchSize > request->size) {
                    request->batchSize = request->size;
                }
            } else {
                request->flags |= 0x4000;
            }
        }

        if (request->flags & 0x4000) {
            if (request->requestCompletionQueue != NULL) {
                osSendMesg(request->requestCompletionQueue, (OSMesg) 801, OS_MESG_BLOCK);
            }
            mem_free(arg0->dmaRequests[request->id]);
        }

        if (!(request->flags & 0x4000)) {
            if (request->flags & 1) {
                osJamMesg(&arg0->dmaQueue, (OSMesg) request, OS_MESG_BLOCK);
            } else {
                osSendMesg(&arg0->dmaQueue, (OSMesg) request, OS_MESG_BLOCK);
            }
        } else if (numActiveTransfers == 0) {
            arg0->isDmaBusy = FALSE;
        }
    }
}

s32 sched_start_dma(Scheduler *scheduler, s32 romAddr, s32 ramAddr, s32 size, u16 batchSize, u16 flags,
                    OSMesgQueue *completionQueue) {
    DMARequest *request;
    s32 pad;
    s32 i;
    OSIntMask mask;

    mask = osSetIntMask(OS_IM_NONE);

    for (i = 0; i < 64; i++) {
        if (scheduler->dmaRequests[i] == NULL) {
            break;
        }
    }
    if (i == 64) {
        return 0;
    }

    scheduler->dmaRequests[i] = mem_alloc(&scheduler->dmaRequests[i], sizeof(DMARequest));
    request = (DMARequest *) scheduler->dmaRequests[i]->data;

    request->flags = flags;
    request->batchSize = batchSize ? batchSize : size;
    request->ramAddr = ramAddr;
    request->romAddr = romAddr;
    request->size = size;
    request->id = i;

    osCreateMesgQueue(&request->piCompletionQueue, request->piMesgs, ARRAY_COUNT(request->piMesgs));
    request->requestCompletionQueue = completionQueue;

    scheduler->isDmaBusy = TRUE;
    if (request->flags & 1) {
        osJamMesg(&scheduler->dmaQueue, (OSMesg) request, OS_MESG_BLOCK);
    } else {
        osSendMesg(&scheduler->dmaQueue, (OSMesg) request, OS_MESG_BLOCK);
    }

    osSetIntMask(mask);
    return 1;
}

void execute_dma_request(DMARequest *request) {
    osInvalDCache(request->ramAddr, request->batchSize);
    osInvalICache(request->ramAddr, request->batchSize);

    while (osPiGetStatus() != 0) {}
    osPiStartDma(&request->ioMesg, OS_MESG_PRI_NORMAL, OS_READ, request->romAddr, request->ramAddr, request->batchSize,
                 &request->piCompletionQueue);
    request->flags |= 0x8000;
}

s32 func_80002D28(Scheduler *arg0) {
    return arg0->unk_1494;
}

void func_80002D30(Scheduler *arg0) {
    arg0->unk_1494++;
}

void func_80002D40(Scheduler *arg0) {
    arg0->unk_1494--;
}

void func_80002D50(Scheduler *arg0) {
    s32 pad[2];
    SchedulerSub *sp6C;
    StructD48 *s1;
    u32 s3;
    u32 i;
    u8 *v1;
    s32 s2;
    Struct1950 *s00;
    s32 v02;
    u32 a0;

    while (TRUE) {
        osRecvMesg(&arg0->unk_1CC, (OSMesg *) &sp6C, OS_MESG_BLOCK);

        if (sp6C->unk_0C->index & 0x20000000) {
            sp6C->unk_0C->index &= ~0x30000000;
            arg0->unk_1494--;
        } else if (sp6C->unk_00 & 1) {
            s1 = (StructD48 *) arg0->unk_1374[sp6C->unk_04]->data;
            if (s1->unk_04 < s1->unk_08) {
                s3 = *s1->unk_0C;
                func_8000D568(s1);
                if (s3 < 0x80) {
                    s2 = (*s1->unk_0C + (s3 << 4 << 4)) & 0x3FF;
                    i = (s3 >> 2) + 2;
                    func_8000D568(s1);

                    v1 = s1->unk_10 - s2;
                    while (i--) {
                        *s1->unk_10++ = *v1++;
                    }
                } else if (s3 < 0xA0) {
                    i = s3 & 0x1F;
                    while (i--) {
                        *s1->unk_10++ = *s1->unk_0C;
                        func_8000D568(s1);
                    }
                } else {
                    if (s3 < 0xE0) {
                        i = (s3 & 0x1F) + 2;
                        s2 = *s1->unk_0C;
                        func_8000D568(s1);
                    } else if (s3 < 0xFF) {
                        i = (s3 & 0x1F) + 2;
                        s2 = 0;
                    } else {
                        i = *s1->unk_0C + 2;
                        func_8000D568(s1);
                        s2 = 0;
                    }

                    while (i--) {
                        *s1->unk_10++ = s2;
                    }
                }

                osSendMesg(&arg0->unk_1CC, sp6C, OS_MESG_BLOCK);
            } else {
                sp6C->unk_00 = 0;
                arg0->unk_1494--;
                sp6C->unk_0C->index &= ~0x10000000;
                if (sp6C->unk_08 != NULL) {
                    osSendMesg(sp6C->unk_08, (OSMesg) 802, OS_MESG_BLOCK);
                }
                mem_free(arg0->unk_1374[sp6C->unk_04]);
            }
        } else {
            s00 = (Struct1950 *) arg0->unk_1374[sp6C->unk_04]->data;
            v02 = func_8000DBCC(s00);
            if (v02 != 0x101) {
                if (v02 == 0x100) {
                    func_8000DC48(s00);
                } else {
                    *s00->unk_04++ = v02;
                }
                osSendMesg(&arg0->unk_1CC, sp6C, OS_MESG_BLOCK);
            } else {
                sp6C->unk_00 = 0;
                arg0->unk_1494--;
                sp6C->unk_0C->index &= ~0x10000000;
                if (sp6C->unk_08 != NULL) {
                    osSendMesg(sp6C->unk_08, (OSMesg) 802, OS_MESG_BLOCK);
                }
                mem_free(arg0->unk_1374[sp6C->unk_04]);
            }
        }
    }
}

void func_800030C8(s32 *arg0) {
    s32 mask;

    mask = osSetIntMask(OS_IM_NONE);
    *arg0 |= 0x20000000;
    osSetIntMask(mask);
}

s32 func_80003108(Scheduler *arg0, s32 arg1, NIStruct2 *arg2, s32 arg3, void *arg4, s32 arg5, u8 arg6) {
    s32 i;
    s32 pad[2];
    StructD48 *s0;
    Struct1950 *s1;

    for (i = 0; i < 64; i++) {
        if (arg0->unk_F74[i].unk_00 == 0) {
            break;
        }
    }
    if (i == 64) {
        return 0;
    }

    arg0->unk_F74[i].unk_00 = arg6;
    arg0->unk_F74[i].unk_08 = arg1;
    arg0->unk_F74[i].unk_04 = i;
    arg0->unk_F74[i].unk_0C = arg2;

    arg0->unk_F74[i].unk_0C->index &= ~0x20000000;
    arg0->unk_F74[i].unk_0C->index |= 0x10000000;
    arg0->unk_1494++;

    if (arg6 & 1) {
        arg0->unk_1374[i] = mem_alloc(&arg0->unk_1374[i], sizeof(StructD48));
        s0 = (StructD48 *) arg0->unk_1374[i]->data;
        mem_clear(s0, sizeof(StructD48));
        func_8000D2E4(s0, arg3, arg4, arg5);
        osCreateMesgQueue(&s0->unk_D28, s0->unk_D40, ARRAY_COUNT(s0->unk_D40));
    } else {
        arg0->unk_1374[i] = mem_alloc(&arg0->unk_1374[i], sizeof(Struct1950));
        s1 = (Struct1950 *) arg0->unk_1374[i]->data;
        mem_clear(s1, sizeof(Struct1950));

        s1->unk_00 = arg3;
        s1->unk_08 = 0xD00;
        s1->unk_04 = arg4;
        s1->unk_C24 = 0;
        s1->unk_C28 = 0x80000000;

        func_8000D92C(s1);
        s1->unk_C2C = func_8000DA30(s1);
        func_8000D744(s1);
        osCreateMesgQueue(&s1->unk_1930, s1->unk_1948, ARRAY_COUNT(s1->unk_1948));
    }

    osSendMesg(&arg0->unk_1CC, (OSMesg) &arg0->unk_F74[i], OS_MESG_BLOCK);
}
