#include "common.h"

typedef struct NIFileEntry {
    /* 0x00 */ u32 romStart;
    /* 0x04 */ u32 romEnd;
} NIFileEntry; // size = 8

typedef struct NITable {
    /* 0x00 */ char signature[0x10];
    /* 0x10 */ NIFileEntry records[1];
} NITable; // size >= 0x18

typedef struct NiMesgQueue {
    /* 0x00 */ OSMesgQueue queue;
    /* 0x18 */ OSMesg mesgs[1];
} NiMesgQueue; // size = 0x1C

extern NITable D_80027958;

s32 func_800061AC(Task *task);

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005F64.s")

void func_80005FA8(NIStruct2 *arg0, void *arg1) {
    NiMesgQueue *niQueue;
    s32 romStart;
    void *ramAddr;
    s32 size;
    s32 romEnd;
    s32 fileFlags;
    Task *task;

    romEnd = D_80027958.records[(arg0->index & 0xFFFFFF) - 1].romEnd;
    romStart = D_80027958.records[(arg0->index & 0xFFFFFF) - 1].romStart;
    fileFlags = romStart & 0xC0000000;
    romStart = romStart & 0x3FFFFFFF;
    size = arg0->size;

    if (arg0->size == 0) {
        while (TRUE) {}
    }

    if (arg0->index == 0 || (arg0->index & 0x10000000) && arg1 == NULL) {
        return;
    }

    if (arg1 == NULL) {
        arg0->unk_08 = mem_alloc(&arg0->unk_08, size);
        ramAddr = arg0->unk_08->data;
    } else {
        ramAddr = arg1;
    }

    if (romEnd == romStart) {
        return;
    }

    if (fileFlags != 0) {
        if (fileFlags == 0x40000000) {
            func_80003108(&gScheduler, 0, arg0, romStart, ramAddr, romEnd - romStart, 2);
        }
        if (fileFlags == 0x80000000) {
            func_80003108(&gScheduler, 0, arg0, romStart, ramAddr, romEnd - romStart, 1);
        }
    } else {
        func_80002D30(&gScheduler);
        task = &D_80044260->tasks[task_create(D_80044260, 10, func_800061AC, NULL)];
        task->unk_08 = mem_alloc(&task->unk_08, sizeof(NiMesgQueue));
        niQueue = (NiMesgQueue *) task->unk_08->data;
        osCreateMesgQueue(&niQueue->queue, niQueue->mesgs, ARRAY_COUNT(niQueue->mesgs));
        task->privData = arg0;
        sched_start_dma(&gScheduler, romStart, ramAddr, romEnd - romStart, 0, 0, &niQueue->queue);
    }
}

s32 func_800061AC(Task *task) {
    NiMesgQueue *niQueue;
    s32 pad;
    OSMesg sp1C;

    sp1C = NULL;
    niQueue = (NiMesgQueue *) task->unk_08->data;
    osRecvMesg(&niQueue->queue, &sp1C, OS_MESG_NOBLOCK);

    if (sp1C != NULL) {
        func_80002D40(&gScheduler);
        return TASK_DONE;
    }
    return TASK_CONTINUE;
}
