#include "common.h"

void func_8000C4E0(TaskManager *arg0, void (*arg1)(void), u8 *arg2) {
    u32 i;

    for (i = 0; i < 0xE0; i++) {
        arg0->unk_189D[i] = 0xDF - i;
    }
    arg0->unk_189C = 0xE0;
    arg0->numTasks = 0;

    arg0->unk_00.next = arg0;
    arg0->unk_00.prev = arg0;

    arg0->unk_00.unk_00 = arg1;
    arg0->unk_00.unk_04 = arg2;
    arg0->unk_00.unk_0C = 0x38000;
    arg0->unk_00.priority = 0;
}

#ifdef NON_EQUIVALENT
s32 func_8000C54C(TaskManager *arg0, u8 arg1, void (*arg2)(s32), u8 *arg3) {
    s32 t5;
    s32 i;
    Task *v1;
    Task *t1;
    Task *t0;
    u8 *tmp;

    tmp = &arg0->unk_189C;

    if (arg0->unk_189C <= 0) {
        return -1;
    }

    t5 = arg0->unk_189D[*tmp - 1];
    arg0->unk_1C[t5].unk_18 = t5;
    arg0->unk_189D[arg0->unk_189C - 1] = 0;
    arg0->unk_189C--;

    v1 = &arg0->unk_1C[t5];
    v1->unk_00 = arg2;
    v1->unk_04 = arg3;
    v1->priority = arg1;
    v1->unk_0C = 0;

    t0 = &arg0->unk_00;
    t1 = arg0->unk_00.next;
    for (i = 0; i < arg0->numTasks; i++) {
        if (t1->priority > arg1) {
            v1->next = t0->next;
            v1->prev = t0;
            t0->next = v1;
            t1->prev = v1;
            break;
        }

        t0 = t1;
        t1 = t1->next;
    }

    arg0->numTasks++;
    return v1->unk_18;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C54C.s")
#endif

void func_8000C628(TaskManager *tm, u8 priority, Task *task) {
    s32 i;
    Task *currTask;
    Task *prevTask;

    task->prev->next = task->next;
    task->next->prev = task->prev;

    prevTask = &tm->unk_00;
    currTask = tm->unk_00.next;
    for (i = 0; i <= tm->numTasks; i++) {
        if (currTask->priority < priority) {
            task->next = prevTask->next;
            task->prev = prevTask;
            prevTask->next = task;
            currTask->prev = task;
            break;
        }
        prevTask = currTask;
        currTask = currTask->next;
    }
}

void func_8000C6A8(TaskManager *tm, Task *task) {
    tm->unk_189C++;
    tm->unk_189D[tm->unk_189C - 1] = task->unk_18;

    task->prev->next = task->next;
    task->next->prev = task->prev;
    task->prev = NULL;
    task->unk_00 = NULL;
    task->unk_04 = NULL;
    task->unk_18 = 0;
    task->unk_0C = 0;
    func_8000C28C(task->unk_08);
    tm->numTasks -= 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000D208.s")
