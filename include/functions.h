#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

void func_80000AD0(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
void mem_clear(void *arg0, s32 arg1);
void func_80000D1C(s32 romAddr, void *vramAddr, s32 size);
void func_800108F0(ALSynConfig *synConfig, s32 arg1, AudioConfig *arg2);
s32 func_800019E0(Task *);
s32 func_80001BFC(Task *);
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
s32 func_800083BC(Task *);
void func_80009B58(void);
void task_set_flags(TaskManager *, s32, s32, s32);
void task_run_all(TaskManager *);
void func_80011230(void);
HeapChunk *mem_alloc(HeapChunk **, s32);
void func_80004DD4(void);
void func_800063E4(void);
void func_80009C44(void);
void mem_free(HeapChunk *);
Gfx *func_800A7110_30810(s32, Gfx *);
s32 sched_start_dma(Scheduler *scheduler, s32 romAddr, s32 ramAddr, s32 size, u16 batchSize, u16 flags,
                    OSMesgQueue *completionQueue);
s32 func_800077D4(Task *);
s32 func_80006348(Task *);
s32 func_80006AC4(Task *);
s32 func_8000792C(Task *);
s32 func_80007654(Task *);
s32 func_80006D9C(Task *);
void load_overlay(Overlay *arg0);
void func_800A6F50_30650(void);
void func_80011738(u16 arg0);
void func_80001200(void);
void func_80005E8C(u8 *);
void func_80002D40(Scheduler *arg0);
s32 func_80003108(Scheduler *, OSMesgQueue *, NIStruct2 *, s32, void *, s32, u8);
void func_80002D30(Scheduler *arg0);
void func_8000D568(StructD48 *);
void func_8000D2E4(StructD48 *, u32, u8 *, s32);

void func_8000D744(HuffmanTree *);
void huffman_read_frequencies(HuffmanTree *);
s32 huffman_build_tree(HuffmanTree *);
s32 huffman_get_char(HuffmanTree *);
void func_8000DC48(HuffmanTree *);

#endif
