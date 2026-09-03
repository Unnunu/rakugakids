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
s32 func_80005F64(Task *task);
s32 func_80005F14(Task *task);

u8 *func_8000C930(s32, u8 *);
u8 *func_8000D2A0(s32, u8 *, s32);

#ifdef NON_MATCHING
u8 *func_80005D60(u32 fileId, u8 *buffer) {
    u8 *end;
    u32 romStart;
    u32 romEnd;
    u32 fileFlags;

    end = NULL;
    romStart = D_80027958.records[fileId - 1].romStart;
    romEnd = D_80027958.records[fileId - 1].romEnd;
    fileFlags = romStart & 0xC0000000;
    romStart &= 0x3FFFFFFF;

    if (fileId == 0) {
        return NULL;
    }

    if (romEnd != romStart) {
        if (fileFlags != 0) {
            if (fileFlags == 0x40000000) {
                end = func_8000C930(romStart, buffer);
            }
            if (fileFlags == 0x80000000) {
                end = func_8000D2A0(romStart, buffer, romEnd - romStart);
            }
        } else {
            dma_read(romStart, buffer, romEnd - romStart);
            end = buffer + romEnd - romStart;
        }
    }

    return end;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/asset/func_80005D60.s")
#endif

void asset_unload(Asset *asset) {
    if (asset != NULL) {
        mem_free(asset->data);
        asset->fileId &= ~0x10000000;
    }
}

void asset_load(Asset *asset) {
    if (!(asset->fileId & 0x10000000)) {
        asset->fileId |= 0x10000000;
        task_create(D_80044260, 10, func_80005F14, asset);
    }
}

void asset_load_to(Asset *asset, HeapChunk *arg1) {
    asset->data = arg1;
    task_create(D_80044260, 10, func_80005F64, asset);
}

s32 func_80005F14(Task *task) {
    Asset *asset;

    asset = task->privData;
    asset->data = mem_alloc(&asset->data, asset->uncompressedSize);
    func_80005D60(asset->fileId & 0xFFFFFF, asset->data->data);
    return TASK_DONE;
}

s32 func_80005F64(Task *task) {
    Asset *asset;

    asset = (Asset *) task->privData;
    func_80005D60(asset->fileId & 0xFFFFFF, asset->data); // @BUG?
    asset->data = NULL;
    return TASK_DONE;
}

void asset_load_async(Asset *asset, void *arg1) {
    NiMesgQueue *niQueue;
    s32 romStart;
    void *ramAddr;
    s32 size;
    s32 romEnd;
    s32 fileFlags;
    Task *task;

    romEnd = D_80027958.records[(asset->fileId & 0xFFFFFF) - 1].romEnd;
    romStart = D_80027958.records[(asset->fileId & 0xFFFFFF) - 1].romStart;
    fileFlags = romStart & 0xC0000000;
    romStart = romStart & 0x3FFFFFFF;
    size = asset->uncompressedSize;

    if (asset->uncompressedSize == 0) {
        while (TRUE) {}
    }

    if (asset->fileId == 0 || (asset->fileId & 0x10000000) && arg1 == NULL) {
        return;
    }

    if (arg1 == NULL) {
        asset->data = mem_alloc(&asset->data, size);
        ramAddr = asset->data->data;
    } else {
        ramAddr = arg1;
    }

    if (romEnd == romStart) {
        return;
    }

    if (fileFlags != 0) {
        if (fileFlags == 0x40000000) {
            func_80003108(&gScheduler, NULL, asset, romStart, ramAddr, romEnd - romStart, 2);
        }
        if (fileFlags == 0x80000000) {
            func_80003108(&gScheduler, NULL, asset, romStart, ramAddr, romEnd - romStart, 1);
        }
    } else {
        func_80002D30(&gScheduler);
        task = &D_80044260->tasks[task_create(D_80044260, 10, func_800061AC, NULL)];
        task->unk_08 = mem_alloc(&task->unk_08, sizeof(NiMesgQueue));
        niQueue = (NiMesgQueue *) task->unk_08->data;
        osCreateMesgQueue(&niQueue->queue, niQueue->mesgs, ARRAY_COUNT(niQueue->mesgs));
        task->privData = asset;
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
