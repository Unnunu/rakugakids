#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void mem_clear(void *arg0, s32 arg1);
void func_80000D1C(s32 romAddr, void *vramAddr, s32 size);
void func_800108F0(ALSynConfig *synConfig, s32 arg1, AudioConfig *arg2);
void func_800019E0(void);
void func_80001BFC(void); // TODO: wrong signature
void sched_init(Scheduler *, u8, u8);
OSMesgQueue *func_80002134(Scheduler *arg0);
OSMesgQueue *func_8000213C(Scheduler *);
s32 func_80002144(Scheduler *);
void sched_register_client(Scheduler *, ScClient *, OSMesgQueue *, s32);
s32 func_80002888(Scheduler *);
void func_80002890(Scheduler *, ScTask *);
void func_80002928(Scheduler *);
void func_80003CBC(void);
void func_80004C70(void);
void func_80006200(void);
void func_80006940(void);
void func_800083BC(void); // TODO: wrong signature
void func_80009B58(void);
void func_8000C4E0(Struct7 *, void (*)(void), u8 *);
s32 func_8000C54C(Struct7 *, s32, void (*)(void), u8 *);
void func_8000C7FC(Struct7 *, s32, s32, s32);
void func_8000C864(Struct7 *);
void func_80011230(void);
HeapChunk *heap_alloc(HeapChunk **, s32);

#endif
