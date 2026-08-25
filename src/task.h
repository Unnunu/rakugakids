#ifndef TASK_H
#define TASK_H

#define NUM_TASKS 0xE0

enum TaskFlags {
    TASK_FLAG_UNPAUSABLE = 0x8000,
    TASK_FLAG_10000 = 0x10000,
    TASK_FLAG_LAST = 0x20000,
    TASK_FLAG_DELETE = 0x40000,
    TASK_FLAG_PAUSED = 0x80000
};

enum TaskStates { TASK_DONE = 0, TASK_CONTINUE = 1 };

struct HeapChunk;

typedef struct Task {
    /* 0x00 */ s32 (*func)(struct Task *);
    /* 0x00 */ void *privData;
    /* 0x08 */ struct HeapChunk *unk_08;
    /* 0x0C */ s32 flags;
    /* 0x10 */ struct Task *next;
    /* 0x14 */ struct Task *prev;
    /* 0x18 */ u16 taskId;
    /* 0x1A */ u16 priority;
} Task; // size = 0x1C

typedef struct TaskManager {
    /* 0x0000 */ Task rootTask;
    /* 0x001C */ Task tasks[NUM_TASKS];
    /* 0x189C */ u8 numFreeTasks;
    /* 0x189D */ u8 freeIds[NUM_TASKS];
    /* 0x197D */ u8 numActiveTasks;
} TaskManager; // size = 0x1980

void task_manager_init(TaskManager *tm, s32 (*func)(Task *), void *privData);
s32 task_create(TaskManager *tm, u8 priority, s32 (*func)(Task *), void *privData);
void task_set_priority(TaskManager *tm, u8 priority, Task *task);
void task_delete(TaskManager *tm, Task *task);
void task_set_flags(TaskManager *tm, s32 taskId, s32 flags, s32 state);
void task_run_all(TaskManager *tm);

#endif
