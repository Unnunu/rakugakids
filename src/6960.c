#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005D60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005E8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005ED8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005F64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/6960/func_80005FA8.s")

s32 func_800061AC(Task *task) {
    OSMesgQueue *queue;
    s32 pad;
    OSMesg sp1C;

    sp1C = NULL;
    queue = (OSMesgQueue *) task->unk_08->data;
    osRecvMesg(queue, &sp1C, OS_MESG_NOBLOCK);

    if (sp1C != NULL) {
        func_80002D40(&gScheduler);
        return TASK_DONE;
    }
    return TASK_CONTINUE;
}
