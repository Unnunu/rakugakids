#include "common.h"
#include "task.h"

void task_manager_init(TaskManager *tm, s32 (*func)(Task *), void *privData) {
    u32 i;

    for (i = 0; i < NUM_TASKS; i++) {
        tm->freeIds[i] = NUM_TASKS - i - 1;
    }
    tm->numFreeTasks = NUM_TASKS;
    tm->numActiveTasks = 0;

    tm->rootTask.next = &tm->rootTask;
    tm->rootTask.prev = &tm->rootTask;

    tm->rootTask.func = func;
    tm->rootTask.privData = privData;
    tm->rootTask.flags = TASK_FLAG_UNPAUSABLE | TASK_FLAG_10000 | TASK_FLAG_LAST;
    tm->rootTask.priority = 0;
}

#ifdef NON_EQUIVALENT
s32 task_create(TaskManager *arg0, u8 priority, s32 (*func)(Task *), void *privData) {
    s32 t5;
    s32 i;
    Task *v1;
    Task *t1;
    Task *t0;
    u8 *tmp;

    // tmp = &arg0->numFreeTasks;

    if (arg0->numFreeTasks <= 0) {
        return -1;
    }

    t5 = arg0->freeIds[arg0->numFreeTasks - 1];
    arg0->tasks[t5].taskId = t5;
    arg0->freeIds[arg0->numFreeTasks - 1] = 0;
    arg0->numFreeTasks--;

    v1 = &arg0->tasks[t5];
    v1->func = func;
    v1->privData = privData;
    v1->priority = priority;
    v1->flags = 0;

    t0 = &arg0->rootTask;
    t1 = arg0->rootTask.next;
    for (i = 0; i < arg0->numActiveTasks; i++) {
        if (t1->priority > priority) {
            v1->next = t0->next;
            v1->prev = t0;
            t0->next = v1;
            t1->prev = v1;
            break;
        }

        t0 = t1;
        t1 = t1->next;
    }

    arg0->numActiveTasks++;
    return v1->taskId;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/task/task_create.s")
#endif

void task_set_priority(TaskManager *tm, u8 priority, Task *task) {
    s32 i;
    Task *currTask;
    Task *prevTask;

    task->prev->next = task->next;
    task->next->prev = task->prev;

    prevTask = &tm->rootTask;
    currTask = tm->rootTask.next;
    for (i = 0; i <= tm->numActiveTasks; i++) {
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

void task_delete(TaskManager *tm, Task *task) {
    tm->numFreeTasks++;
    tm->freeIds[tm->numFreeTasks - 1] = task->taskId;

    task->prev->next = task->next;
    task->next->prev = task->prev;
    task->prev = NULL;
    task->func = NULL;

    task->privData = NULL;
    task->taskId = 0;
    task->flags = 0;
    mem_free(task->unk_08);
    tm->numActiveTasks--;
}

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C728.s")

void func_8000C758(TaskManager *tm, u8 taskId) {
    Task *task;

    task = &tm->tasks[taskId];
    task->flags |= TASK_FLAG_DELETE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C7CC.s")

void task_set_flags(TaskManager *tm, s32 taskId, s32 flags, s32 state) {
    Task *task;

    task = &tm->tasks[taskId];

    if (state) {
        if (task->flags & TASK_FLAG_UNPAUSABLE) {
            flags &= ~TASK_FLAG_PAUSED;
        }
        task->flags |= flags;
    } else {
        task->flags &= ~flags;
    }
}

void task_run_all(TaskManager *tm) {
    Task *task;

    task = &tm->rootTask;

    do {
        do {
            if (tm) {} // required to match
            task = task->next;
        } while (task->flags & TASK_FLAG_PAUSED);

        if ((task->flags & TASK_FLAG_DELETE) || task->func(task) == TASK_DONE) {
            task_delete(tm, task);
        }
    } while (!(task->flags & TASK_FLAG_LAST));
}

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000C9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000CFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/task/func_8000D208.s")
