#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void func_80000AD0(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void mem_clear(void *arg0, s32 arg1);
void func_80000D1C(s32 romAddr, void *vramAddr, s32 size);
void func_800108F0(ALSynConfig *synConfig, s32 arg1, AudioConfig *arg2);
s32 func_800019E0(s32);
s32 func_80001BFC(s32);
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
void func_8000C4E0(TaskManager *, void (*)(void), u8 *);
s32 func_8000C54C(TaskManager *, u8, void (*)(s32), u8 *);
void func_8000C7FC(TaskManager *, s32, s32, s32);
void func_8000C864(TaskManager *);
void func_80011230(void);
HeapChunk *heap_alloc(HeapChunk **, s32);
void func_80004DD4(void);
void func_800063E4(void);
void func_80009C44(void);
void func_8000C28C(HeapChunk *);
Gfx *func_800A7110_30810(s32, Gfx *);
void func_80002B64(Scheduler *, s32, s32, s32, s32, s32, OSMesgQueue *);
void func_800077D4(s32);
void func_80006348(s32);
s32 func_80001A5C(s32);
void func_80006AC4(s32);
void func_8000792C(s32);
void func_80007654(s32);
void func_80006D9C(s32);
s32 func_80001AB8(s32);
s32 func_80001BD0(s32);
void load_overlay(Overlay *arg0);
void func_800A6F50_30650(void);
void func_80011738(u16 arg0);
void func_80001200(void);
void func_80005E8C(u8 *);

#endif
