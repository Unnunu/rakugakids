#include "common.h"

typedef struct VoiceState {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ char unk_0F[5];
    /* 0x14 */ ALWaveTable *unk_14;
    /* 0x18 */ char unk_18[0xA2 - 0x18];
    /* 0xA2 */ s16 unk_A2[7];
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ s16 unk_B4;
    /* 0xB6 */ s16 unk_B6;
    /* 0xB8 */ u8 unk_B8[3];
    /* 0xBB */ s8 unk_BB[3];
    /* 0xBE */ u8 unk_BE[26];
} VoiceState; // size = 0xD8

typedef struct AudioStruct1 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
} AudioStruct1; // size = 6

typedef struct AudioStruct2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} AudioStruct2; // size = 4

typedef struct AudioStruct3 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
} AudioStruct3; // size = 4

extern s32 D_8002A450[];
extern s32 D_8002A45C[];
extern u8 *D_8002A468[];
extern s32 D_8002A484[];
extern AudioStruct2 D_8002A644[];

extern u8 D_80055430;
extern u8 D_80055431;
extern ALPlayer D_80055438;
extern ALHeap D_80055450;
extern ALBankFile *D_80055460[3];
extern u8 D_80055470[0x35000];
extern u8 D_8008A470;
extern u8 D_8008A471;
extern u16 D_8008A472;
extern s8 D_8008A475;
extern s8 D_8008A476;
extern s8 D_8008A477;
extern s8 D_8008A478;
extern u8 D_8008A47B;
extern u8 D_8008A47E;
extern u8 D_8008A488[];
extern AudioStruct1 D_8008A4A8[];
extern u8 D_8008A4D8;
extern s8 D_8008A4D9;
extern u8 D_8008A4DA;
extern s32 D_8008A4E0[];
extern u16 D_8008A504;
extern ALVoice D_8008A548[];
extern VoiceState *D_8008A70C;
extern u8 D_8008A710;
extern AudioStruct3 D_8008A718[];
extern u8 D_8008A728;
extern ALFxRef D_8008A760;
extern u8 D_8008A780[];
extern VoiceState D_8009C780[];

void func_80011424(ALPlayer *);
ALMicroTime func_800114C0(void *);
void func_800115BC(void);
void func_80012C50(s32, u8, s32);
void func_800129BC(void);
void func_80011CC4(void);
void func_80011ECC(void);
void func_80011B98(void);
void func_800138A0(void);
void func_80013068(void);
void func_800117F0(u16 arg0, u8 arg1, u8 arg2);

#ifdef NON_EQUIVALENT
void func_80011230(void) {
    ALSynConfig sp7C;
    AudioConfig sp70;
    u32 i, j;
    s32 s1;
    s32 s3;
    u8 *ptr;

    for (i = 0; i < 0x100000; i++) {}

    alHeapInit(&D_80055450, D_80055470, sizeof(D_80055470));

    s3 = 0;
    for (j = 0; j < 3; j++) {
        s1 = D_8002A45C[j] - D_8002A450[j];
        D_80055460[j] = ptr = D_8008A780 + s3;

        // clang-format off
        for (i = 0; i < s1; i++) { ptr[i] = 0; }
        // clang-format on
        func_80000D1C(D_8002A450[j], D_80055460[j], s1);
        s3 += s1;
    }

    for (j = 0; j < 3; j++) {
        alBnkfNew(D_80055460[j], D_8002A468[j]);
    }

    sp7C.maxVVoices = 16;
    sp7C.maxPVoices = 16;
    sp7C.maxUpdates = 160;
    sp7C.dmaproc = NULL;
    sp7C.outputRate = 0;
    sp7C.heap = &D_80055450;
    sp7C.fxType = AL_FX_CUSTOM;
    sp7C.params = D_8002A484;

    sp70.frequency = 0xAC44;
    sp70.freqMultiplier = 1;
    sp70.maxCommands = 0x1000;

    func_800108F0(&sp7C, 0x50, &sp70);
    func_80011424(&D_80055438);

    for (i = 0; i < 0x100000; i++) {}
}
#else
void func_80011230(void);
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80011230.s")
#endif

#ifdef NON_EQUIVALENT
void func_80011424(ALPlayer *player) {
    D_8008A470 = 8;
    D_8008A4D9 = 0;
    D_8008A478 = 0;
    D_8008A475 = 0;
    D_8008A4DA = 0;
    D_8008A472 = 0;
    D_8008A477 = D_8008A476 = 0;

    player->next = NULL;
    player->handler = func_800114C0;
    player->clientData = player;
    alSynAddPlayer(&alGlobals->drvr, player);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80011424.s")
#endif

ALMicroTime func_800114C0(void *arg0) {
    u8 temp_v0;

    temp_v0 = D_8008A470;
    if (D_8008A470 != 0) {
        if (D_8008A470 == 8) {
            func_800115BC();
        }
        D_8008A470--;
    } else {
        if (D_8008A504 != 0) {
            func_800129BC();
        }
        if (D_8008A710 != 0) {
            func_80011CC4();
        }
        if (D_8008A728 != 0) {
            func_80011ECC();
        }
        if (D_8008A471 == 0) {
            func_80011B98();
        }
        func_800138A0();
        D_8008A472 += 1;
        if (D_80055431 != 0) {
            D_80055431 = 0;
            func_80012C50(1, D_80055430, 0);
        }
    }
    return 5000;
}

void func_800115BC(void) {
    ALVoiceConfig sp70;
    s32 i;
    ALVoice *v;
    ALBank *bank;
    ALInstrument *inst;
    ALSound *sound;

    for (i = 0; i < 16; i++) {
        sp70.priority = 10;
        sp70.fxBus = 0;
        sp70.unityPitch = 0;
        alSynAllocVoice(&alGlobals->drvr, &D_8008A548[i], &sp70);

        D_8008A70C = &D_8009C780[i];
        D_8008A70C->unk_0C = D_8008A70C->unk_0D = 0;
        bank = D_80055460[D_8008A70C->unk_0C]->bankArray[0];

        inst = bank->instArray[D_8008A70C->unk_0D];
        sound = inst->soundArray[0];
        D_8008A70C->unk_14 = sound->wavetable;
        D_8008A70C->unk_B0 = 1.0f;
        D_8008A70C->unk_B4 = 0;
        D_8008A70C->unk_B6 = 0;
        D_8008A70C->unk_0E = 1;

        alSynStartVoiceParams(&alGlobals->drvr, &D_8008A548[i], D_8008A70C->unk_14, 1.0f, 0, AL_PAN_CENTER,
                              AL_DEFAULT_FXMIX, 0);
    }

    func_80013068();
    D_8008A760 = alSynGetFXRef(&alGlobals->drvr, 0, 0);
}

void func_80011738(u16 arg0) {
    func_800117F0(arg0, 0, 0);
}

void func_80011764(u16 arg0) {
    func_800117F0(arg0, 0, 0);
}

void func_80011790(u16 arg0, u8 arg1) {
    func_800117F0(arg0, arg1, 0);
}

void func_800117C0(u16 arg0, u8 arg1) {
    func_800117F0(arg0, 0, arg1);
}

void func_800117F0(u16 arg0, u8 arg1, u8 arg2) {
    u32 v1;
    s32 i;
    s32 a3;

    if (arg0) {
        D_8008A471 = 255;

        if (!arg1 || arg1 > 127) {
            v1 = arg0;
        } else {
            v1 = arg0 + (arg1 << 16);
        }

        if (arg2 != 0) {
            v1 |= arg2 << 24;
        }

        if (D_8008A4DA < 8) {
            if (D_8008A4DA != 0) {
                for (i = 0; i < D_8008A4DA; i++) {
                    if ((u32) (D_8008A4E0[i] & 0xFFFF) == arg0) {
                        D_8008A471 = 0;
                        return;
                    }
                }
            }

            D_8008A4E0[D_8008A4DA] = v1;
            D_8008A4DA++;
        }

        D_8008A471 = 0;
    }
}

void func_800118C8(u16 arg0, u8 arg1, s16 arg2) {
    if (D_8008A4D8 < 8 && arg0 != 0 && arg1 < 3) {
        D_8008A4A8[D_8008A4D8].unk_00 = arg0;
        D_8008A4A8[D_8008A4D8].unk_02 = arg2;
        D_8008A4A8[D_8008A4D8].unk_04 = arg1;
        D_8008A4D8++;
        D_8008A471 = 0;
    }
}

s32 func_80011940(u8 arg0, u8 arg1) {
    s32 a0;
    s32 v1;

    v1 = D_8008A70C->unk_B8[arg1];
    if (v1 != 0) {
        if (arg1 == 0) {
            a0 = D_8008A70C->unk_BB[arg1] << 8;
        } else {
            a0 = D_8008A70C->unk_BB[arg1];
        }
        a0 += D_8008A4A8[arg0].unk_02 * v1 / 10;

        return a0;
    } else {
        return D_8008A4A8[arg0].unk_02;
    }
}

void func_800119D8(s32 arg0) {
    u8 s3;
    s32 i;
    AudioStruct2 *s0;
    s32 v0;
    s32 v1;

    s3 = D_8008A4A8[arg0].unk_04;

    for (i = 0; i < 16; i++) {
        D_8008A70C = &D_8009C780[i];
        if ((D_8008A70C->unk_00 & 0x7FFF) == D_8008A4A8[arg0].unk_00) {
            s0 = &D_8002A644[s3];

            v0 = func_80011940(arg0, s3);
            v1 = v0;
            if (v0 < s0->unk_00) {
                v1 = s0->unk_00;
            } else if (v0 > s0->unk_02) {
                v1 = s0->unk_02;
            }

            if (D_8008A70C->unk_A2[s3] != (s16) v1) {
                D_8008A70C->unk_A2[s3] = v1;
            }
        }
    }
}

void func_80011AF4(u8 arg0, u8 arg1) {
    if (arg1 > 20) {
        arg1 = 20;
    }
    if (arg0 < 2) {
        D_8008A488[arg0] = arg1;
        return;
    } else {
        D_8008A488[0] = arg1;
        D_8008A488[1] = arg1;
    }
}

void func_80011B44(void) {
    D_8008A488[0] = D_8008A488[1] = 0;
}

s32 func_80011B58(void) {
    s32 var_v1;

    var_v1 = D_8008A47B + D_8008A47E;
    if (var_v1 == 0 && D_8009C780[0].unk_00 != 0 && D_8009C780[0].unk_00 < 0x100) {
        var_v1 = -1;
    }
    return var_v1;
}

extern s32 D_8008A500;

typedef void (*AudioFunc1)(void);
extern AudioFunc1 D_8002A650[];

void func_80012830(void);
void func_80012458(s32);
void func_8001377C(void);

void func_80011B98(void) {
    s32 i;
    u16 v0;

    i = 0;
    while (D_8008A4DA != 0) {
        D_8008A500 = D_8008A4E0[i++];
        v0 = D_8008A500 & 0xFFFF;

        D_8008A4DA--;

        if (v0 < 0x100) {
            if (v0 < 0x10) {
                D_8002A650[v0 - 1]();
            } else {
                func_80012830();
            }
        } else {

            if (v0 < 0x8000) {
                func_80012458(0);
            } else {
                func_8001377C();
            }
        }
    }

    i = 0;
    while (D_8008A4D8 != 0) {
        func_800119D8(i);
        i++;
        D_8008A4D8--;
    }
}

#if 0
void func_80011CC4(void) {
    AudioStruct3 *v0;

    while (D_8008A710 != 0) {
        v0 = &D_8008A718[D_8008A710--];
    }
}
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80011CC4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80011ECC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012314.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012458.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800129BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012A98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012B60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012C50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012D54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001310C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800131C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013270.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001336C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013484.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013508.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013590.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001366C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800136F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001371C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013734.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001377C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013800.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800138A0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013BF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80013F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001437C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014498.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_8001454C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_800145F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014708.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014A18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014B00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014B6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014BBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014C00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80014C4C.s")
