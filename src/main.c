#include "common.h"

typedef struct Struct1 {
    /* 0x00 */ s16 unk_00;
    /* 0x00 */ s16 unk_02;
} Struct1; // size = 4

/* .bss */
OSMesgQueue D_8002FA50;
Struct1 D_8002FA68;
OSThread D_8002FA70;
OSThread D_8002FC20;
u8 D_8002FDD0[0x2000];
u8 D_80031DD0[0x2000];
u8 D_80033DD0[0x2000];
OSMesgQueue D_80035DD0;
OSMesg D_80035DE8[100];
OSMesgQueue D_80035F78;
OSMesg D_80035F90[1];
OSMesg D_80035F98[8];

/* .data */
s32 D_80027730[2] = { 0, 0 };

ScTask D_80027738[2] = {
    { 0,
      0,
      0x40,
      D_80100000[0],
      { {
          M_GFXTASK,
          0,
          rspbootTextStart,
          0,
          gspFast3DTextStart,
          SP_UCODE_SIZE,
          gspFast3DDataStart,
          SP_UCODE_DATA_SIZE,
          D_8004F2C0,
          0x400,
          D_80045270,
          NULL,
          NULL,
          NULL,
          D_80044270,
          0xC00,
      } },
      &D_8002FA50,
      &D_8002FA68.unk_00 },
    { 0,
      0,
      0x40,
      D_80100000[1],
      { {
          M_GFXTASK,
          0,
          rspbootTextStart,
          0,
          gspFast3DTextStart,
          SP_UCODE_SIZE,
          gspFast3DDataStart,
          SP_UCODE_DATA_SIZE,
          D_8004F2C0,
          0x400,
          D_80045270,
          NULL,
          NULL,
          NULL,
          D_80044270,
          0xC00,
      } },
      &D_8002FA50,
      &D_8002FA68.unk_02 },
};

s32 D_800277E8[] = { 3, 2, 0, 1 };
s32 D_800277F8[] = { 0xC00, 0x1500, 0x800, 0x800 };
s32 D_80027808[] = { 0, 0 };

void func_800004BC(void *);
void func_80000550(void *);
void func_80000DEC(void);

s32 func_800012BC(s32);
s32 func_800012E0(s32);
void func_80001820(void);

void main(void) {
    osInitialize();
    osCreateThread(&D_8002FA70, 1, &func_800004BC, 0, D_80031DD0 + sizeof(D_80031DD0), 20);
    osStartThread(&D_8002FA70);
}

void func_800004BC(void *arg) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_80035DD0, &D_80035DE8, ARRAY_COUNT(D_80035DE8));
    osCreateThread(&D_8002FC20, 3, &func_80000550, arg, D_80033DD0 + sizeof(D_80033DD0), 30);
    osStartThread(&D_8002FC20);
    osSetThreadPri(NULL, OS_PRIORITY_IDLE);
    while (TRUE) {}
}

void func_80000550(void *arg) {
    ScClient sp54;
    s16 *sp50;

    sp50 = 0;
    D_8002FA68.unk_00 = 2;
    D_8002FA68.unk_02 = 2;

    osCreateMesgQueue(&D_80035F78, D_80035F90, ARRAY_COUNT(D_80035F90));
    osCreateMesgQueue(&D_8002FA50, D_80035F98, ARRAY_COUNT(D_80035F98));
    sched_init(&gScheduler, OS_VI_NTSC_LAN1, 1);
    sched_register_client(&gScheduler, &sp54, &D_8002FA50, 13);
    D_80037458 = func_8000213C(&gScheduler);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
    func_80000DEC();
    func_80006940();
    func_80004C70();
    func_80011230();

    while (TRUE) {
        osRecvMesg(&D_8002FA50, (OSMesg *) &sp50, OS_MESG_BLOCK);

        switch (*sp50) {
            case 1:
                D_80044254->frameCounter++;
                if (D_80044254->unk_76C78 == 0) {
                    if (func_80002888(&gScheduler) < 2U) {
                        func_8000C864(D_80044260);
                    }
                } else {
                    D_80044254->unk_76C78--;
                }
                break;
            case 2:
                func_80002928(&gScheduler);
                break;
            case 4:
                break;
        }
    }
}

void func_80000750(void) {
    gSPSegment(D_80044258++, 0, 0x00000000);
    gSPSegment(D_80044258++, 2, VIRTUAL_TO_PHYSICAL(D_80100000[D_80044254->cfbIdx]));
}

void func_800007D4(void) {
    gSPDisplayList(D_80044258++, D_80028790);
}

#ifdef NON_EQUIVALENT
void func_80000800(void) {
    ScTask *task;

    gDPFullSync(D_80044258++);
    gSPEndDisplayList(D_80044258++);
    osWritebackDCache(&D_80044254->unk_00[D_80044254->cfbIdx], sizeof(Struct5));

    task = &D_80027738[func_80002144(&gScheduler)];
    task->osTask.t.data_ptr = D_80044254->unk_00[D_80044254->cfbIdx].unk_00;
    task->osTask.t.data_size = (D_80044258 - D_80044254->unk_00[D_80044254->cfbIdx].unk_00) * sizeof(Gfx);
    task->osTask.t.ucode_boot_size = (u32) rspbootTextEnd - (u32) rspbootTextStart;
    task->osTask.t.output_buff = D_80045270;
    task->osTask.t.output_buff_size = D_80045270 + sizeof(D_80045270);
    task->unk_08 = 0x40;

    func_80002890(&gScheduler, task);
}
#else
void func_80000800(void);
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80000800.s")
#endif

void func_80000954(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_FILL);
    gDPSetColorImage(D_80044258++, G_IM_FMT_RGBA, D_80044254->bitDepth, SCREEN_WIDTH,
                     VIRTUAL_TO_PHYSICAL(D_80100000[D_80044254->cfbIdx]));
    gDPSetFillColor(D_80044258++,
                    (GPACK_RGBA5551(arg0, arg1, arg2, arg3) << 16) | GPACK_RGBA5551(arg0, arg1, arg2, arg3));
    gDPFillRectangle(D_80044258++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_1CYCLE);
}

void func_80000AD0(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_FILL);
    gDPSetColorImage(D_80044258++, G_IM_FMT_RGBA, D_80044254->bitDepth, SCREEN_WIDTH,
                     VIRTUAL_TO_PHYSICAL(D_80100000[D_80044254->cfbIdx]));
    gDPSetFillColor(D_80044258++,
                    (GPACK_RGBA5551(arg0, arg1, arg2, arg3) << 16) | GPACK_RGBA5551(arg0, arg1, arg2, arg3));
    gDPFillRectangle(D_80044258++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_1CYCLE);
}

void func_80000C4C(void) {
    gDPSetColorImage(D_80044258++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, D_3D6500);
    gDPSetDepthImage(D_80044258++, D_3D6500);
    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_FILL);
    gDPSetFillColor(D_80044258++, GPACK_ZDZ(G_MAXFBZ, 0) << 16 | GPACK_ZDZ(G_MAXFBZ, 0));
    gDPFillRectangle(D_80044258++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    gDPPipeSync(D_80044258++);
}

void func_80000D1C(s32 romAddr, void *vramAddr, s32 size) {
    OSMesg sp34 = 0;

    osWritebackDCache(vramAddr, size);
    osInvalDCache(vramAddr, size);
    osInvalICache(vramAddr, size);

    while (osPiGetStatus() != 0) {}
    osPiStartDma(&D_80037460, 0, OS_READ, romAddr, vramAddr, size, &D_80035F78);
    while (sp34 == 0) {
        osRecvMesg(&D_80035F78, &sp34, OS_MESG_NOBLOCK);
    }
}

void func_80000DEC(void) {
    mem_clear(D_8014B000, 0x2B0D00);
    D_80044268 = D_8014B000;
    D_80044230.next = NULL;
    D_8002A2D0 = &D_80044230;
    D_80044240 = heap_alloc(&D_80044240, sizeof(Struct4));
    D_80044248 = heap_alloc(&D_80044248, sizeof(Struct7));
    D_8004424C = heap_alloc(&D_8004424C, sizeof(Struct7));
    mem_clear(D_80044240->data, sizeof(Struct4));
    mem_clear(D_80044248->data, sizeof(Struct7));
    mem_clear(D_8004424C->data, sizeof(Struct7));
    D_80044254 = D_80044240->data;
    func_80009B58();
    D_80044251 = 0;
    D_80044254->bitDepth = 2;
    D_80044250 = 0;

    func_8000C4E0(D_80044260 = D_80044248->data, func_80001BFC, &D_80044250);
    func_8000C4E0(D_80044264 = D_8004424C->data, func_800083BC, NULL);

    func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 250, func_800012BC, &D_80044250), 0x8000, 1);
    func_8000C54C(D_80044260, 200, func_800019E0, &D_80044250);
    func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 20, func_800012E0, &D_80044250), 0x8000, 1);
    func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 5, func_80001820, NULL), 0x8000, 1);

    osUnmapTLBAll();

    D_80044254->unk_76C80 = 0;
    D_80044254->unk_76C84 = 0;
    D_80044254->unk_76C88 = 0;
}

#ifdef NON_EQUIVALENT
void mem_clear(u8 *arg0, s32 arg1) {
    s32 a2;
    u8 *v0;
    u64 *v1;

    v0 = arg0;
    if ((s32) v0 & 7) {
        a2 = 8 - ((s32) v0 & 7);
        arg1 -= a2;
        while (a2) {
            *v0++ = 0;
            a2--;
        }
    }

    v1 = v0;
    a2 = (arg1 & ~7) >> 3;
    while (a2) {
        *v1++ = 0;
        a2--;
    }

    v0 = v1;
    a2 = arg1 & 7;
    while (a2) {
        *v0++ = 0;
        a2--;
    }
}
#else
void mem_clear(void *arg0, s32 arg1);
#pragma GLOBAL_ASM("asm/nonmatchings/main/mem_clear.s")
#endif

void func_80001188(u8 *arg0, u8 *arg1, s32 arg2) {
    while (arg2--) {
        *arg1++ = *arg0++;
    }
}

void func_800011B8(u64 *arg0, u64 *arg1, s32 arg2) {
    arg2 = ALIGN_16(arg2) / sizeof(u64);

    while (arg2--) {
        *arg1++ = *arg0++;
    }
}

void func_80001200(void) {
    func_80003CBC();
    func_80006940();
    func_80006200();
}

void func_80001230(void) {
    func_80000954(D_80044254->unk_76C80, D_80044254->unk_76C84, D_80044254->unk_76C88, 1);
}

void func_8000126C(Mtx *m, float r, float p, float h, float s, float x, float y, float z) {
    guPosition(m, r, p, h, s, x, y, z);
}

// TODO: argument type
s32 func_800012BC(s32 arg0) {
    func_80004DD4();
    return 1;
}
// TODO: argument type
s32 func_800012E0(s32 arg0) {
    s32 a0;
    s32 i;

    a0 = 0;
    for (i = 0; i < 4; i++) {
        D_80044254->unk_00[D_80044254->cfbIdx].unk_1C810[i] = &D_80044254->unk_00[D_80044254->cfbIdx].unk_4000[a0];
        a0 += D_800277F8[i];
    }

    if (!(D_80044254->flags & 0x8000)) {
        func_800063E4();
        func_80009C44();
    }

    if (D_80044254->unk_757F0 != NULL) {
        if (D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840 == NULL) {
            D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840 =
                heap_alloc(&D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840, 0x2000 * sizeof(Gfx));
        }
        D_80044258 = (Gfx *) D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840->data;

        func_800007D4();
        D_80044254->unk_757F0();

        gDPPipeSync(D_80044258++);
        gSPEndDisplayList(D_80044258++);
    } else {
        if (D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840 != NULL) {
            func_8000C28C(D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840);
        }
    }

    D_80044258 = D_80044254->unk_00[D_80044254->cfbIdx].unk_00;
    func_80000750();
    func_800007D4();
    if (D_80044254->flags & 1) {
        func_80000C4C();
    }
    func_80001230();

    if (!(D_80044254->flags & 0x8000)) {
        for (i = 0; i < 4; i++) {
            if (D_80044254->unk_39E20[D_800277E8[i]].unk_00 != 0) {
                gSPDisplayList(D_80044258++, D_80044254->unk_00[D_80044254->cfbIdx].unk_1C820[D_800277E8[i]]);
                gSPDisplayList(D_80044258++, D_80044254->unk_00[D_80044254->cfbIdx].unk_1C830[D_800277E8[i]]);
                D_80044254->unk_00[D_80044254->cfbIdx].unk_1C800[i] = 0;
            }
        }
    } else {
        D_80044258 = func_800A7110(D_80044254->cfbIdx, D_80044258);
    }

    if (D_80044254->unk_757F0 != NULL && D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840 != NULL) {
        gSPDisplayList(D_80044258++, (Gfx *) D_80044254->unk_00[D_80044254->cfbIdx].unk_1C840->data);
    }

    func_80000800();
    D_80044254->cfbIdx ^= 1;
    return 1;
}

// split?

#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80001730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main/func_800017CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main/func_800017F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80001820.s")
