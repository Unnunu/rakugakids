#include "common.h"

typedef struct ChanState {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x08 */ u8 *unk_08;
    /* 0x0C */ u8 unk_0C;
    /* 0x0D */ u8 unk_0D;
    /* 0x0E */ u8 unk_0E;
    /* 0x0F */ u8 unk_0F;
    /* 0x10 */ u8 unk_10;
    /* 0x14 */ ALWaveTable *unk_14;
    /* 0x18 */ u16 unk_18;
    /* 0x1A */ u16 unk_1A;
    /* 0x1C */ u8 unk_1C;
    /* 0x1D */ u8 unk_1D;
    /* 0x1E */ u8 unk_1E;
    /* 0x1F */ u8 unk_1F;
    /* 0x20 */ u8 unk_20;
    /* 0x21 */ u8 unk_21;
    /* 0x22 */ u8 unk_22;
    /* 0x23 */ u8 unk_23;
    /* 0x24 */ u8 unk_24;
    /* 0x25 */ u8 unk_25;
    /* 0x26 */ char unk_26[2];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s16 unk_2C;
    /* 0x2E */ s16 unk_2E;
    /* 0x30 */ s16 unk_30;
    /* 0x32 */ s16 unk_32;
    /* 0x34 */ s16 unk_34;
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ u16 unk_38;
    /* 0x3A */ u16 unk_3A;
    /* 0x3C */ u16 unk_3C;
    /* 0x3E */ u16 unk_3E;
    /* 0x40 */ s16 unk_40;
    /* 0x42 */ s16 unk_42;
    /* 0x44 */ u8 unk_44;
    /* 0x45 */ u8 unk_45;
    /* 0x46 */ u8 unk_46;
    /* 0x47 */ u8 unk_47;
    /* 0x48 */ u8 unk_48;
    /* 0x49 */ u8 unk_49;
    /* 0x4A */ u16 unk_4A;
    /* 0x4C */ u16 unk_4C;
    /* 0x4E */ u16 unk_4E;
    /* 0x50 */ u16 unk_50;
    /* 0x52 */ u16 unk_52;
    /* 0x54 */ u16 unk_54;
    /* 0x56 */ u16 unk_56;
    /* 0x58 */ u16 unk_58;
    /* 0x5A */ u8 unk_5A;
    /* 0x5B */ u8 unk_5B;
    /* 0x5C */ char unk_5C[0x7D - 0x5C];
    /* 0x7D */ u8 unk_7D;
    /* 0x7E */ char unk_7E[0x84 - 0x7E];
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s16 unk_88;
    /* 0x8A */ s16 unk_8A;
    /* 0x8C */ char unk_8C[0x92 - 0x8C];
    /* 0x92 */ u8 unk_92;
    /* 0x93 */ char unk_93[0x9A - 0x93];
    /* 0x9A */ u16 unk_9A;
    /* 0x9C */ u8 unk_9C;
    /* 0x9D */ u8 unk_9D;
    /* 0x9E */ u8 unk_9E;
    /* 0x9F */ u8 unk_9F;
    /* 0xA0 */ u8 unk_A0;
    /* 0xA1 */ u8 unk_A1;
    /* 0xA2 */ s16 unk_A2[3];
    /* 0xA8 */ s16 unk_A8[3];
    /* 0xAE */ s16 unk_AE;
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ s16 unk_B4;
    /* 0xB6 */ u16 unk_B6;
    /* 0xB8 */ u8 unk_B8[3];
    /* 0xBB */ s8 unk_BB[3];
    /* 0xBE */ u8 unk_BE;
    /* 0xBF */ u8 unk_BF;
    /* 0xC0 */ s16 unk_C0[3];
    /* 0xC6 */ s16 unk_C6[3];
    /* 0xCC */ s16 unk_CC[3];
    /* 0xD2 */ u8 unk_D2[3];
    /* 0xD5 */ u8 unk_D5;
    /* 0xD6 */ u8 unk_D6;
    /* 0xD7 */ u8 unk_D7;
} ChanState; // size = 0xD8

typedef struct AudioStruct1 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
} AudioStruct1; // size = 6

typedef struct AudioStruct2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} AudioStruct2; // size = 4

typedef struct AudioStruct3Sub {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
} AudioStruct3Sub; // size = ?

typedef struct AudioStruct3 {
    /* 0x00 */ u16 unk_00;
    /* 0x04 */ AudioStruct3Sub *unk_04;
} AudioStruct3; // size = 8

typedef struct AudioStruct5 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
} AudioStruct5; // size = 4

typedef struct AudioStruct7 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s32 unk_04;
} AudioStruct7; // size = 8

typedef struct AudioStruct8 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ u16 **unk_08;
    /* 0x0C */ s16 unk_0C[3];
} AudioStruct8; // size = ?

typedef struct AudioStruct9 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ s16 unk_04;
} AudioStruct9; // size = 6

typedef struct AudioStructA {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 *unk_04;
} AudioStructA; // size = 8

typedef void (*AudioFunc1)(void);

/* .data */

extern s32 D_8002A450[];
extern s32 D_8002A45C[];
extern u8 *D_8002A468[];
extern AudioStructA *D_8002A474[];
extern u8 D_8002A480;
extern s32 D_8002A484[];
extern u32 D_8002A4AC[];
extern u32 D_8002A578[];
extern AudioStruct2 D_8002A644[];
extern AudioFunc1 D_8002A650[];
extern u8 D_8002A688[];
extern AudioFunc1 D_8002A690[];
extern s16 D_8002A750[];
extern f32 D_8002A758[];
extern u8 D_8002B0D0[];
extern u8 D_8002B0D8[][4];
extern AudioStruct5 D_8002B0F8[];
extern AudioStruct7 D_8002B1C0[];

/* .bss */

extern u8 D_80055430;
extern u8 D_80055431;
extern ALPlayer D_80055438;
extern ALHeap D_80055450;
extern ALBankFile *D_80055460[3];
extern u8 D_80055470[0x35000];
extern u8 D_8008A470;
extern u8 D_8008A471;
extern u16 D_8008A472;
extern u8 D_8008A474;
extern u8 D_8008A475;
extern s8 D_8008A476;
extern s8 D_8008A477;
extern u8 D_8008A478;
extern u8 D_8008A479;
extern u8 D_8008A47A;
extern u8 D_8008A47B;
extern u8 D_8008A47C;
extern u8 D_8008A47D;
extern u8 D_8008A47E;
extern u16 D_8008A480;
extern u8 D_8008A482;
extern s8 D_8008A483;
extern u8 D_8008A484;
extern u8 D_8008A485[];
extern u16 D_8008A486[];
extern u8 D_8008A488[];
extern AudioStruct8 D_8008A490;
extern AudioStruct1 D_8008A4A8[];
extern u8 D_8008A4D8;
extern u8 D_8008A4D9;
extern u8 D_8008A4DA;
extern s32 D_8008A4E0[];
extern u32 D_8008A500;
extern u16 D_8008A504;
extern u8 D_8008A506;
extern u16 *D_8008A508[];
extern ALVoice D_8008A548[];
extern u8 *D_8008A708;
extern ChanState *D_8008A70C;
extern u8 D_8008A710;
extern AudioStruct3 D_8008A718[];
extern u8 D_8008A728;
extern AudioStruct9 D_8008A730[];
extern ALFxRef D_8008A760;
extern u8 D_8008A780[];
extern ChanState D_8009C780[];
extern u8 D_8009CFF4;
extern u8 D_8009D500[];

void func_80011424(ALPlayer *);
ALMicroTime func_800114C0(void *);
void func_800115BC(void);
void func_800117F0(u16 arg0, u8 arg1, u8 arg2);
void func_80011B98(void);
void func_80011CC4(void);
void func_80011ECC(void);
void func_80012008(u32);
void func_80012314(s32 arg0, s32 arg1);
void func_80012458(s32);
u8 func_80012728(u8 arg0);
void func_80012830(void);
void func_800129BC(void);
void func_80012C50(u8, u16, u8);
void func_80012D54(s32);
void func_80013068(void);
void func_8001310C(void);
void func_800131C4(s32);
void func_80013590(u8);
void func_8001377C(void);
void func_800138A0(void);
void func_80013BF4(void);
void func_80013F70(void);
void func_8001437C(void);
void func_80014498(void);
void func_8001454C(void);
void func_800145F8(void);
void func_80014708(void);
s32 func_80014A18(s32 arg0, u8 arg1, u8 arg2);
void func_80014A74(void);
void func_80014B00(void);
void func_80014B6C(void);
void func_80014BBC(void);
void func_80014C00(void);
void func_80014C4C(void);
void func_80014DB8(void);
void func_80015070(void);
void func_80015208(void);
void func_80015690(void);
void func_80015900(void);
void func_80015958(void);
void func_800159D4(void);
void func_80015C10(void);
void func_80015D84(void);
void func_80015E64(void);
void func_80015EFC(void);
void func_80015FD0(void);
void func_80016AA0(u8);

#ifdef NON_MATCHING
void func_80011230(void) {
    ALSynConfig sp7C;
    AudioConfig sp70;
    u32 i, j;
    s32 s1;
    s32 s3;
    s32 a3;
    u8 *ptr;

    for (i = 0; i < 0x100000; i++) {}

    alHeapInit(&D_80055450, D_80055470, sizeof(D_80055470));

    s3 = 0;
    for (j = 0; j < 3; j++) {
        s1 = D_8002A45C[j] - D_8002A450[j];
        a3 = D_8002A450[j];
        ptr = D_80055460[j] = D_8008A780 + s3;

        // clang-format off
        for (i = 0; i < s1; i++) { ptr[i] = 0; }
        // clang-format on
        dma_read(a3, D_80055460[j], s1);
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

    sp70.frequency = 44100;
    sp70.freqMultiplier = 1;
    sp70.maxCommands = 0x1000;

    func_800108F0(&sp7C, 80, &sp70);
    func_80011424(&D_80055438);

    for (i = 0; i < 0x100000; i++) {}
}
#else
void func_80011230(void);
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80011230.s")
#endif

void func_80011424(ALPlayer *player) {
    D_8008A470 = 8;
    D_8008A472 = D_8008A4DA = D_8008A475 = D_8008A478 = D_8008A4D9 = 0;
    D_8008A477 = D_8008A476 = 0;

    player->next = NULL;
    player->handler = func_800114C0;
    player->clientData = player;
    alSynAddPlayer(&alGlobals->drvr, player);
}

ALMicroTime func_800114C0(void *arg0) {
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
        D_8008A472++;
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

void func_80011CC4(void) {
    AudioStruct3Sub *sub;
    s16 val1, val2, val3;
    s16 temp1;
    s16 temp2;
    s16 temp3;
    u16 temp0;

    while (D_8008A710) {
        D_8008A710--;

        temp0 = D_8008A718[D_8008A710].unk_00;
        sub = D_8008A718[D_8008A710].unk_04;

        temp1 = temp0 >> 3;
        temp2 = temp1 >> 3;
        temp3 = temp2 >> 3;

        val1 = temp1 & 0x3FFF;
        val2 = temp2 & 0xFF;
        val3 = temp3 & 0x7F;

        if (sub->unk_02) {
            s16 v0 = sub->unk_02 << 8;
            while (val1 > v0) {
                val1 >>= 1;
            }
        } else {
            val1 = 0;
        }

        if (sub->unk_03) {
            while (val2 > sub->unk_03) {
                val2 >>= 1;
            }
        } else {
            val2 = 0;
        }

        if (sub->unk_04) {
            while (val3 > sub->unk_04) {
                val3 >>= 1;
            }
        } else {
            val3 = 0;
        }

        if (temp0 & 1) {
            val1 = -val1;
        }
        if (temp0 & 2) {
            val2 = -val2;
        }
        if (temp0 & 4) {
            val3 = -val3;
        }
        D_8008A500 = sub->unk_00;
        D_8008A490.unk_0C[0] = val1;
        D_8008A490.unk_0C[1] = val2;
        D_8008A490.unk_0C[2] = val3;

        if (D_8008A500 >= 0x100) {
            func_80012458(1);
        }
    }
}

void func_80011ECC(void) {
    u32 a1;

    while (D_8008A728) {
        D_8008A728--;
        a1 = D_8008A730[D_8008A728].unk_00;
        switch (D_8008A730[D_8008A728].unk_02) {
            case 0:
                D_8008A500 = a1;
                if (a1 < 0x100) {
                    if (a1 < 0x10) {
                        D_8002A650[a1 - 1]();
                    } else {
                        func_80012830();
                    }
                } else {
                    func_80012458(0);
                }
                break;
            case 1:
                func_80012008(a1);
                break;
            case 2:
                func_80012314(0, a1);
                break;
            case 3:
                func_80012314(1, a1);
                break;
            case 4:
                func_80012314(2, a1);
                break;
        }
    }
}

void func_80012008(u32 arg0) {
    s32 i;

    if (D_8008A730[D_8008A728].unk_03 != 0) {
        for (i = 0; i < 16; i++) {
            D_8008A70C = &D_8009C780[i];
            if ((D_8008A70C->unk_00 & 0x7FFF) == arg0) {
                D_8008A70C->unk_BE = 0xFF;
                D_8008A70C->unk_BF = 0x100 / D_8008A730[D_8008A728].unk_03;
                if (D_8008A70C->unk_BF == 0) {
                    D_8008A70C->unk_BF = 1;
                }
            }
        }
    } else {
        if (arg0 < 0x100) {
            if (arg0 == (D_8009C780->unk_00 & 0x7FFF)) {
                func_8001310C();
            }
        } else {
            for (i = 0; i < 16; i++) {
                if (arg0 == (D_8009C780[i].unk_00 & 0x7FFF)) {
                    func_800131C4(i);
                }
            }
        }
    }
}

void func_80012314(s32 arg0, s32 arg1) {
    s32 v0;
    s32 a2;
    s32 i;
    s32 temp;

    v0 = D_8008A730[D_8008A728].unk_03;
    a2 = D_8008A730[D_8008A728].unk_04;

    for (i = 0; i < 16; i++) {
        D_8008A70C = &D_8009C780[i];
        if ((D_8008A70C->unk_00 & 0x7FFF) == arg1) {
            if (D_8008A70C->unk_C6[arg0] != a2) {
                temp = (a2 - D_8008A70C->unk_C6[arg0]);
                temp /= v0;
                D_8008A70C->unk_D2[arg0] = v0;
                D_8008A70C->unk_C0[arg0] = a2;
                D_8008A70C->unk_CC[arg0] = temp;
            }
        }
    }
}

#ifdef NON_EQUIVALENT
void func_80012458(s32 arg0) {
    u16 v0;
    AudioStructA *t1;
    AudioStructA *v;
    AudioStructA *vv;
    u8 a3;
    s32 i;

    v0 = D_8008A500 & 0x7FFF;

    if (v0 >= 0x200) {
        if (v0 >= 0x37B) {
            return;
        }
        v = D_8002A474[(v0 >> 8) - 1];
        t1 = v + (v0 & 0xFF);

        D_8008A490.unk_02 = t1->unk_00;
        D_8008A490.unk_02 &= 0x1F;

        a3 = t1->unk_01;
        D_8008A490.unk_03 = a3 & 0xF;
        a3 = a3 >> 4;

        if (a3 == 0) {
            for (i = 10; i < 16; i++) {
                if ((D_8009C780[i].unk_00 & 0x7FFF) == v0) {
                    a3 = i;
                    break;
                }
            }
            if (a3 == 0) {
                a3 = func_80012728(1);
            }
        }

        if (arg0 != 0) {
            if (D_8009C780[a3].unk_04 >= D_8008A490.unk_02) {
                return;
            }
        } else {
            if (D_8009C780[a3].unk_04 > D_8008A490.unk_02) {
                return;
            }
        }
        D_8008A490.unk_01 = a3;
        D_8008A490.unk_00 = 1;
        D_8008A490.unk_08 = D_8008A508;
        *D_8008A490.unk_08 = t1->unk_04;
    } else {
        if (v0 >= 0x12F) {
            return;
        }

        v = D_8002A474[(v0 >> 8) - 1];
        t1 = &v[v0 & 0xFF];

        a3 = t1->unk_00;
        D_8008A490.unk_02 = a3 & 0x1F;
        D_8008A490.unk_00 = (a3 >> 5) + 1;

        a3 = t1->unk_01;
        D_8008A490.unk_03 = a3 & 0xF;
        a3 = a3 >> 4;

        if (D_8008A490.unk_00 == 2) {
            if (a3 == 0) {
                for (i = 14; i >= 10; i -= 2) {
                    if ((D_8009C780[i].unk_00 & 0x7FFF) == v0) {
                        a3 = i;
                        break;
                    }
                }
                if (a3 == 0) {
                    a3 = func_80012728(2);
                }
            }

            if (D_8009C780[a3].unk_04 > D_8008A490.unk_02 || D_8009C780[a3 + 1].unk_04 > D_8008A490.unk_02) {
                return;
            }
        }

        D_8008A490.unk_01 = a3;
        D_8008A490.unk_08 = t1->unk_04;
    }

    D_8008A490.unk_04 = 6;
    func_80012D54(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012458.s")
#endif

void func_80012B60(void);
void func_8000DF24(u32, void *, u32);
void func_80012A98(u16 arg0, u8 arg1);

u8 func_80012728(u8 arg0) {
    u8 v1;
    u8 i;
    u8 v0;
    u8 a3;

    v1 = 14;

    if (arg0 == 1) {
        v1 = 10;
        v0 = D_8009CFF4;
        for (i = 11; i < 16; i++) {
            if (v0 >= D_8009C780[i].unk_04) {
                v1 = i;
                v0 = D_8009C780[i].unk_04;
            }
        }
    } else {
        v0 = 255;
        for (i = 14; i >= 10; i -= 2) {
            a3 = i;
            if (D_8009C780[i].unk_04 < D_8009C780[i + 1].unk_04) {
                a3++;
            }

            if (v0 >= D_8009C780[a3].unk_04) {
                v1 = i;
                v0 = D_8009C780[a3].unk_04;
            }
        }
    }

    return v1;
}

void func_80012830(void) {
    u16 a3;
    u8 tmp;

    a3 = D_8008A500 & 0x7FFF;

    if (D_8002B0F8[a3 - 16].unk_02 == 0 || D_8002B0F8[a3 - 16].unk_02 != D_8002A480) {
        if (D_8008A47E) {
            func_80013068();
        } else {
            func_8001310C();
        }
    }

    if (a3 < 0xC0) {
        if (a3 < 0x43) {
            tmp = D_8002B0F8[a3 - 16].unk_02;
            if (tmp != 0) {
                if (tmp != D_8002A480) {
                    D_8008A504 = a3;
                    D_8008A506 = 4;
                } else {
                    func_80012C50(0, a3, 5);
                }
            } else {
                if (a3 != D_8008A4D9) {
                    D_8008A504 = a3;
                    D_8008A506 = 4;
                } else {
                    func_80012A98(a3, 6);
                }
            }
        }
    } else if (a3 < 0xC1) {
        a3 -= 0xC0;
        D_8008A490.unk_00 = D_8002B1C0[a3].unk_00;
        D_8008A490.unk_03 = D_8002B1C0[a3].unk_01;
        D_8008A490.unk_08 = D_8002B1C0[a3].unk_04;
        D_8008A490.unk_01 = 0;
        D_8008A490.unk_02 = 30;
        D_8008A490.unk_04 = 6;

        func_80012D54(0);
    }
}

void func_800129BC(void) {
    u16 tmp;

    if (--D_8008A506) {
        return;
    }

    if (D_80044251) {
        D_8008A506 = 1;
        return;
    }

    tmp = D_8008A504 - 16;
    D_8008A4D9 = D_8008A504;
    D_8002A480 = D_8002B0F8[tmp].unk_02;

    if (D_8002A480) {
        func_80012B60();
        return;
    }

    func_8000DF24(D_8002A4AC[tmp], D_8009D500, D_8002A578[tmp] - D_8002A4AC[tmp]);
    func_80012A98(D_8008A504, 5);
    D_8008A504 = 0;
}

void func_80012A98(u16 arg0, u8 arg1) {
    u16 tmp;
    s32 i;
    u16 *tmp2;

    tmp = arg0 - 16;
    tmp2 = D_8009D500;

    D_8008A490.unk_00 = D_8002B0F8[tmp].unk_00;
    D_8008A490.unk_03 = D_8002B0F8[tmp].unk_01;
    D_8008A490.unk_08 = D_8008A508;

    for (i = 0; i < D_8008A490.unk_00; i++) {
        D_8008A508[i] = (u16 *) ((u32) (D_8009D500) + tmp2[i]);
    }

    D_8008A500 = arg0;
    D_8008A490.unk_01 = 0;
    D_8008A490.unk_02 = 30;
    D_8008A490.unk_04 = arg1;
    func_80012D54(0);
}

void func_80012B60(void) {
    s32 i;
    u16 v1;
    u8 *tmp;
    s32 v2;
    u8 *ptr;
    s32 size;

    v2 = D_8002A480 - 1;
    tmp = D_8002B0D8[v2];
    ptr = D_8009D500;
    for (i = 0; i < D_8002B0D0[v2]; i++, ptr += 0x1800) {
        v1 = tmp[i] - 16;
        size = D_8002A578[v1] - D_8002A4AC[v1];
        func_8000DF24(D_8002A4AC[v1], ptr, size);
    }

    func_80012C50(0, D_8008A504, 5);
    D_8008A504 = 0;
}

void func_80012C50(u8 arg0, u16 arg1, u8 arg2) {
    u16 tmp;
    u16 *a0;
    s32 i;

    D_80055430 = arg1;
    if (arg0 || D_8009C780->unk_00 == 0) {
        tmp = arg1 - 16;
        D_8008A490.unk_00 = D_8002B0F8[tmp].unk_00;
        D_8008A490.unk_03 = D_8002B0F8[tmp].unk_01;
        D_8008A490.unk_08 = D_8008A508;

        a0 = D_8009D500 + D_8002B0F8[tmp].unk_03 * 0x1800;
        for (i = 0; i < D_8008A490.unk_00; i++) {
            D_8008A508[i] = (u32) a0 + a0[i];
        }
        D_8008A500 = arg1;
        D_8008A490.unk_01 = 0;
        D_8008A490.unk_02 = 30;
        D_8008A490.unk_04 = arg2;
        func_80012D54(0);
    }
}

#ifdef NON_EQUIVALENT
void func_80012D54(s32 arg0) {
    s32 v0;
    s32 i;
    s32 j;
    ChanState *s0;
    u8 **v1;

    if (arg0 == 0) {
        D_8008A490.unk_0C[0] = 0;
        D_8008A490.unk_0C[1] = 0;
        D_8008A490.unk_0C[2] = 0;
    }

    v0 = ((D_8008A500 & 0x7FFF) < 0x100) ? 0 : 1;
    v1 = D_8008A490.unk_08;

    for (i = 0; i < D_8008A490.unk_00; i++) {
        s0 = D_8009C780 + D_8008A490.unk_01 + i;

        if (s0->unk_10 != D_8008A488[v0]) {
            s0->unk_10 = D_8008A488[v0];
            alSynSetFXMix(&alGlobals->drvr, &D_8008A548[D_8008A490.unk_01 + i], s0->unk_10);
        }

        if (v0 != 0 && s0->unk_0E != 0) {
            alSynSetVol(&alGlobals->drvr, &D_8008A548[D_8008A490.unk_01 + i], 0, 5000);
            s0->unk_0F = 2;
        }

        s0->unk_05 = D_8008A490.unk_04;
        s0->unk_00 = D_8008A500;
        s0->unk_04 = D_8008A490.unk_02;
        s0->unk_0C = D_8008A490.unk_03;

        s0->unk_08 = v1[i];

        s0->unk_18 = 0x8000;
        s0->unk_1A = 0x80;

        s0->unk_21 = s0->unk_22 = 1;

        s0->unk_38 = 0;

        s0->unk_9E = 0;
        s0->unk_1D = 0;
        s0->unk_47 = s0->unk_5B = 0;
        s0->unk_58 = 0;
        s0->unk_2E = s0->unk_30 = 0;
        s0->unk_32 = s0->unk_34 = 0;
        s0->unk_40 = s0->unk_42 = 0;
        s0->unk_7D = s0->unk_8A = 0;
        s0->unk_9A = s0->unk_92 = 0;

        for (j = 0; j < 3; j++) {
            s0->unk_A2[j] = s0->unk_A8[j] = D_8008A490.unk_0C[j];
        }

        for (j = 0; j < 3; j++) {
            s0->unk_B8[j] = 0;
            s0->unk_BB[j] = 0;
        }
        s0->unk_BE = 0;

        for (j = 0; j < 3; j++) {
            s0->unk_C6[j] = 0;
            s0->unk_D2[j] = 0;
        }
        s0->unk_D5 = 0;
    }

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == (D_8008A500 & 0x7FFF)) {
            D_8008A486[i] = D_8008A485[i] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/11E30/func_80012D54.s")
#endif

void func_80013068(void) {
    s32 i;

    D_8008A710 = 0;
    D_8008A728 = 0;
    D_8008A4D8 = 0;
    D_8008A47E = 0;
    D_8008A488[0] = D_8008A488[1] = 0;

    for (i = 0; i < 16; i++) {
        D_8009C780[i].unk_00 = 0x10;
    }

    func_8001310C();

    for (i = 0; i < 1; i++) {
        D_8008A486[i] = D_8008A485[i] = 0;
    }
}

void func_8001310C(void) {
    s32 i;
    u32 v0;

    D_80055431 = 0;
    D_8008A504 = 0;
    D_8008A506 = 0;

    D_8008A47B = D_8008A482 = D_8008A480 = 0;
    D_8008A483 = D_8008A484 = 0;

    for (i = 0; i < 16; i++) {
        v0 = D_8009C780[i].unk_00 & 0x7FFF;
        if (v0 >= 0x10 && v0 < 0x100) {
            func_800131C4(i);
        }
    }
}

void func_800131C4(s32 arg0) {
    D_8008A70C = &D_8009C780[arg0];
    D_8008A70C->unk_00 = 0;
    D_8008A70C->unk_04 = 0;
    if (D_8008A70C->unk_0E != 0) {
        D_8008A70C->unk_0F = 2;
        D_8008A70C->unk_B4 = 0;
        D_8008A70C->unk_B6 = 0;
        alSynSetVol(&alGlobals->drvr, &D_8008A548[arg0], 0, 5000);
    }
}

void func_80013270(void) {
    s32 i;
    u32 v1;

    if (D_8008A475 == 0) {
        D_8008A475++;

        for (i = 0; i < 16; i++) {
            D_8008A70C = &D_8009C780[i];
            v1 = D_8008A70C->unk_00 & 0x7FFF;
            if (v1 >= 0x10 && v1 < 0x100 && D_8008A70C->unk_0E != 0) {
                D_8008A70C->unk_0F = 2;
                alSynSetVol(&alGlobals->drvr, &D_8008A548[i], 0, 5000);
            }
        }
    }
}

void func_8001336C(void) {
    s32 i;
    u32 v1;

    if (D_8008A475 != 0) {
        D_8008A475 = 0;

        for (i = 0; i < 16; i++) {
            D_8008A70C = &D_8009C780[i];
            v1 = D_8008A70C->unk_00 & 0x7FFF;
            if (v1 >= 0x10 && v1 < 0x100) {
                D_8008A70C->unk_06 |= 1;
                if (D_8008A70C->unk_0E != 0) {
                    D_8008A70C->unk_0F = 0;
                    alSynStopVoice(&alGlobals->drvr, &D_8008A548[i]);
                }

                D_8008A70C->unk_0E = 1;
                alSynStartVoice(&alGlobals->drvr, &D_8008A548[i], D_8008A70C->unk_14);
            }
        }
    }
}

void func_80013484(void) {
    s32 i;

    if (D_8008A478 != 0) {
        D_8008A478 = 0;

        for (i = 0; i < 16; i++) {
            D_8008A70C = &D_8009C780[i];
            if (D_8008A70C->unk_00 != 0) {
                func_80013590(i);
            }
        }
    }
}

void func_80013508(void) {
    s32 i;

    if (D_8008A478 == 0) {
        D_8008A478 = 1;

        for (i = 0; i < 16; i++) {
            D_8008A70C = &D_8009C780[i];
            if (D_8008A70C->unk_00 != 0) {
                func_80013590(i);
            }
        }
    }
}

void func_80013590(u8 arg0) {
    s16 pan;

    D_8008A70C->unk_06 |= 1;

    if (D_8008A478) {
        pan = AL_PAN_CENTER;
    } else {
        pan = ((D_8008A70C->unk_58 >> 8) & 0x7F);
        pan += D_8008A70C->unk_A8[2];
        if (D_8008A70C->unk_C6[2] != 0) {
            pan += D_8008A70C->unk_C6[2] / 256;
        }

        if (pan < AL_PAN_LEFT) {
            pan = AL_PAN_LEFT;
        } else if (pan > AL_PAN_RIGHT) {
            pan = AL_PAN_RIGHT;
        }
    }

    alSynSetPan(&alGlobals->drvr, &D_8008A548[arg0], pan);
}

void func_8001366C(void) {
    if (D_8008A500 != 10) {
        if (D_8008A47B == 0) {
            D_8008A47B = 255;
        }
        D_8008A47A = D_8008A479 = D_8002A688[D_8008A500 - 7]; // No idea where is the start of the array
    } else {
        if (D_8008A47E == 0) {
            D_8008A47E = 255;
        }
        D_8008A47D = D_8008A47C = D_8002A688[D_8008A500 - 7]; // No idea where is the start of the array
    }
}

void func_800136F8(void) {
    if (D_8008A480 < 0x100) {
        D_8008A482 = 0x10;
    }
}

void func_8001371C(void) {
    D_8008A482 = D_8008A480 = 0;
}

void func_80013734(void) {
    if (D_8008A484 == 0) {
        D_8008A483 = -1;
    }
}

void func_80013758(void) {
    if (D_8008A484 != 0) {
        D_8008A483 = 1;
    }
}

void func_8001377C(void) {
    s32 i, j;

    D_8008A500 &= 0x7FFF;

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == D_8008A500) {
            return;
        }
    }

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == 0) {
            D_8008A486[i] = D_8008A500;
            D_8008A485[i] = 255;
            break;
        }
    }
}

void func_80013800(u16 arg0) {
    s32 i;

    for (i = 0; i < 16; i++) {
        if (D_8008A486[arg0] == (D_8009C780[i].unk_00 & 0x7FFF)) {
            func_800131C4(i);
        }
    }

    D_8008A486[arg0] = D_8008A485[arg0] = 0;
}

void func_800138A0(void) {
    s32 i;

    if (D_8008A47E != 0 && D_8008A475 == 0 && !(D_8008A472 & 3)) {
        if (--D_8008A47D == 0) {
            D_8008A47D = D_8008A47C;
            D_8008A47E -= 4;
            if (D_8008A47E < 0x10) {
                func_80013068();
            }
        }
    }

    if (D_8008A47B != 0 && D_8008A475 == 0 && !(D_8008A472 & 3)) {
        if (--D_8008A47A == 0) {
            D_8008A47A = D_8008A479;
            D_8008A47B -= 4;
            if (D_8008A47B < 0x10) {
                func_8001310C();
            }
        }
    }

    if (D_8008A475 == 0 && !(D_8008A472 & 1)) {
        for (i = 0; i < 1; i++) {
            if (D_8008A486[i] != 0) {
                D_8008A485[i] -= 4;
                if (D_8008A485[i] < 16) {
                    func_80013800(i);
                }
            }
        }
    }

    if (D_8008A482 != 0 && D_8008A475 == 0 && !(D_8008A472 & 7)) {
        D_8008A482--;
        D_8008A480++;
    }

    if (D_8008A483 != 0 && !(D_8008A472 & 1)) {
        D_8008A484 += D_8008A483;
        if (D_8008A484 == 0xA0 || D_8008A484 == 0) {
            D_8008A483 = 0;
        }
    }

    for (D_8008A474 = 0; D_8008A474 < 16; D_8008A474++) {
        D_8008A70C = &D_8009C780[D_8008A474];

        if (D_8008A70C->unk_0F != 0) {
            D_8008A70C->unk_0F--;
            if (D_8008A70C->unk_0F == 0 && D_8008A70C->unk_0E != 0) {
                D_8008A70C->unk_0E = 0;
                alSynStopVoice(&alGlobals->drvr, &D_8008A548[D_8008A474]);
            }
        }

        if (D_8008A70C->unk_00 != 0) {
            if (D_8008A70C->unk_05 != 0) {
                D_8008A70C->unk_05--;
            } else if ((D_8008A70C->unk_00 & 0x7FFF) < 0x100) {
                if (D_8008A475 == 0) {
                    D_8008A70C->unk_1A += D_8008A480;
                    func_80013BF4();
                }
            } else {
                func_80013BF4();
            }
        }
    }
}

void func_80013BF4(void) {
    s32 i;
    s16 a;

    if (!(D_8008A472 & 3)) {
        for (i = 0; i < 3; i++) {
            if (D_8008A70C->unk_A2[i] != D_8008A70C->unk_A8[i]) {
                if (D_8008A70C->unk_A8[i] < D_8008A70C->unk_A2[i]) {
                    D_8008A70C->unk_A8[i] += D_8002A750[i];
                    if (D_8008A70C->unk_A8[i] > D_8008A70C->unk_A2[i]) {
                        D_8008A70C->unk_A8[i] = D_8008A70C->unk_A2[i];
                    }
                } else {
                    D_8008A70C->unk_A8[i] -= D_8002A750[i];
                    if (D_8008A70C->unk_A8[i] < D_8008A70C->unk_A2[i]) {
                        D_8008A70C->unk_A8[i] = D_8008A70C->unk_A2[i];
                    }
                }

                switch (i) {
                    case 0:
                        D_8008A70C->unk_06 |= 2;
                        break;
                    case 1:
                        D_8008A70C->unk_06 |= 1;
                        break;
                    case 2:
                        func_80013590(D_8008A474);
                        break;
                }
            }
        }
    }

    D_8008A70C->unk_1A += D_8008A70C->unk_18 >> 8;
    if (D_8008A70C->unk_1A >= 0x100) {
        D_8008A70C->unk_1A &= 0xFF;

        if (D_8008A70C->unk_BE != 0) {
            a = D_8008A70C->unk_BE;
            a -= D_8008A70C->unk_BF;
            if (a < 0x10) {
                func_80016AA0(D_8008A70C->unk_BE);
                return;
            }

            D_8008A70C->unk_BE = a;
            D_8008A70C->unk_06 |= 1;
        }

        for (i = 0; i < 3; i++) {
            if (D_8008A70C->unk_D2[i] != 0) {
                D_8008A70C->unk_D2[i]--;

                if (D_8008A70C->unk_D2[i] != 0) {
                    D_8008A70C->unk_C6[i] += D_8008A70C->unk_CC[i];
                } else {
                    D_8008A70C->unk_C6[i] = D_8008A70C->unk_C0[i];
                }

                switch (i) {
                    case 0:
                        D_8008A70C->unk_06 |= 2;
                        break;
                    case 1:
                        D_8008A70C->unk_06 |= 1;
                        break;
                    case 2:
                        func_80013590(D_8008A474);
                        break;
                }
            }
        }

        D_8008A70C->unk_21--;
        if (D_8008A70C->unk_21 == 0) {
            func_80013F70();
            func_80015D84();
        } else {
            func_8001437C();
        }

        if (D_8008A70C->unk_1D != 0) {
            func_80014DB8();
        }
        if (D_8008A70C->unk_47 != 0) {
            func_80015208();
        }
        if (D_8008A70C->unk_5B != 0) {
            func_80015690();
        }
    } else {
        func_8001454C();
    }

    if (D_8008A70C->unk_92 != 0) {
        func_80015C10();
    }
}

void func_80013F70(void) {
    u8 s0;
    u8 sp26;

    sp26 = 0;
    if (D_8008A70C->unk_22 == 0) {
        sp26 = 1;
    } else if (D_8008A70C->unk_0E != 0) {
        D_8008A70C->unk_0F = 0;
        D_8008A70C->unk_0E = 0;
        alSynStopVoice(&alGlobals->drvr, &D_8008A548[D_8008A474]);
    }

    D_8008A708 = D_8008A70C->unk_08;

    while ((s0 = *D_8008A708++) >= 0xD0) {
        D_8002A690[s0 - 0xD0]();
        switch (s0) {
            case 0xF2:
            case 0xF3:
                D_8008A70C->unk_08 = D_8008A708;
                return;
            case 0xFF:
                return;
        }
    }

    D_8008A70C->unk_84 = D_8008A70C->unk_28;

    if (s0 < 0x68) {
        D_8008A70C->unk_25 = s0;
    } else {
        D_8008A70C->unk_25 = s0 - 0x68;
    }

    if (D_8008A70C->unk_25 >= 0x48) {
        if (D_8008A70C->unk_25 == 0x67) {
            D_8008A70C->unk_25 = *D_8008A708++;
        }
        D_8008A70C->unk_06 |= 4;
        func_80015070();
        D_8008A70C->unk_25 = 60;
    } else {
        D_8008A70C->unk_06 &= 0xFB;
    }

    D_8008A70C->unk_28 = D_8008A70C->unk_25 << 8;
    D_8008A70C->unk_28 += D_8008A70C->unk_2C;
    D_8008A70C->unk_28 += D_8008A70C->unk_2E;
    D_8008A70C->unk_28 += D_8008A70C->unk_30;
    D_8008A70C->unk_28 += D_8008A70C->unk_32;
    D_8008A70C->unk_28 += D_8008A70C->unk_34;

    if (s0 < 0x68) {
        D_8008A70C->unk_20 = *D_8008A708++;
    }
    D_8008A70C->unk_21 = D_8008A70C->unk_20;

    s0 = *D_8008A708++;
    if (s0 < 0x80) {
        D_8008A70C->unk_23 = s0;
        s0 = *D_8008A708++;
    }
    D_8008A70C->unk_22 = D_8008A70C->unk_23;

    if (D_8008A70C->unk_22 == 0) {
        D_8008A70C->unk_24 = 0;
    } else {
        D_8008A70C->unk_24 = (D_8008A70C->unk_21 * D_8008A70C->unk_22) >> 7;
        if (D_8008A70C->unk_24 == 0) {
            D_8008A70C->unk_24 = 1;
        }
    }

    D_8008A70C->unk_48 = s0 & 0x7F;
    D_8008A70C->unk_08 = D_8008A708;

    if (D_8008A70C->unk_8A == 0) {
        D_8008A70C->unk_7D = 0;
    } else {
        func_80015FD0();
    }

    D_8008A70C->unk_36 = 0;

    if (D_8008A70C->unk_9A != 0) {
        func_80015900();
    }

    if (D_8008A70C->unk_D5 == 0) {
        func_800145F8();
        if (!sp26) {
            D_8008A70C->unk_B6 = 0xFFFF;
            func_80014A74();
            D_8008A70C->unk_0E = 1;
            alSynStartVoice(&alGlobals->drvr, &D_8008A548[D_8008A474], D_8008A70C->unk_14);
        } else {
            D_8008A70C->unk_06 |= 1;

            if (D_8008A70C->unk_4C != 0) {
                func_80014C4C();
            }
            if (D_8008A70C->unk_06 & 1) {
                func_80014708();
            }
        }
    }
}

void func_8001437C(void) {
    if (D_8008A70C->unk_7D != 0) {
        func_80015E64();
    }
    if (D_8008A70C->unk_9A != 0) {
        func_80015958();
    }
    if (D_8008A70C->unk_06 & 2) {
        func_800145F8();
    }

    if (D_8008A70C->unk_22 != 0 && D_8008A70C->unk_21 == 1) {
        func_80014C00();
        return;
    }

    if (D_8008A70C->unk_24 != 0) {
        D_8008A70C->unk_24--;
        if (D_8008A70C->unk_24 == 0) {
            func_80014BBC();
            return;
        }
    }
    if (D_8008A70C->unk_4C != 0) {
        func_80014C4C();
    }
    if (D_8008A70C->unk_06 & 1) {
        func_80014708();
    } else {
        func_80014498();
    }
}

void func_80014498(void) {
    s32 i;

    if (D_8008A47E != 0) {
        func_80014708();
    } else if ((D_8008A70C->unk_00 & 0x7FFF) < 0x100 && (D_8008A47B != 0 || D_8008A483 != 0)) {
        func_80014708();
    } else {
        for (i = 0; i < 1; i++) {
            if (D_8008A486[i] == (D_8008A70C->unk_00 & 0x7FFF)) {
                func_80014708();
                break;
            }
        }
    }
}

void func_8001454C(void) {
    if (D_8008A70C->unk_7D != 0) {
        func_80015EFC();
    }
    if (D_8008A70C->unk_9A != 0) {
        func_800159D4();
    }
    if (D_8008A70C->unk_06 & 2) {
        func_800145F8();
    }
    if (D_8008A70C->unk_4C != 0) {
        func_80014C4C();
    }
    if (D_8008A70C->unk_06 & 1) {
        func_80014708();
    }
}

void func_800145F8(void) {
    u8 x1;
    s32 v0;
    f32 df;

    D_8008A70C->unk_06 &= 0xfd;
    v0 = D_8008A70C->unk_A8[0] + D_8008A70C->unk_28 + D_8008A70C->unk_38 + D_8008A70C->unk_36;
    v0 += D_8008A70C->unk_C6[0];
    if (v0 < 0) {
        v0 = 0;
    } else if (v0 > 0x4800) {
        v0 = 0x4800;
    }

    x1 = v0 & 0xFF;
    v0 >>= 8;
    df = D_8002A758[v0 + 1] - D_8002A758[v0];
    df = x1 * df / 256;
    df += D_8002A758[v0];
    if (df != D_8008A70C->unk_B0) {
        D_8008A70C->unk_B0 = df;
        alSynSetPitch(&alGlobals->drvr, &D_8008A548[D_8008A474], df);
    }
}

void func_80014708(void) {
    s32 t0;
    s32 s0;
    s16 v1;
    s32 i;

    D_8008A70C->unk_06 &= 0xFE;

    t0 = (D_8008A70C->unk_48 + D_8008A70C->unk_40 + D_8008A70C->unk_42);
    t0 *= D_8008A70C->unk_3A;

    if (t0 > 0x7FFFFF) {
        t0 = 0x7FFF;
    } else if (t0 < 0) {
        t0 = 0;
    } else {
        t0 = t0 >> 8;
    }

    s0 = D_8008A70C->unk_4C;
    t0 = (D_8008A70C->unk_4A * t0) >> 8;

    if (D_8008A70C->unk_A8[1] != 0) {
        t0 = ((D_8008A70C->unk_A8[1] + 0x100) * t0) >> 8;
        if (t0 > 0x7FFF) {
            t0 = 0x7FFF;
        }
    }

    if (D_8008A70C->unk_C6[1] != 0) {
        v1 = D_8008A70C->unk_C6[1] / 64;
        if (v1 <= -0x100) {
            t0 = 0;
        } else {
            t0 = ((v1 + 0x100) * t0) >> 8;
            if (t0 > 0x7FFF) {
                t0 = 0x7FFF;
            }
        }
    }

    if (D_8008A70C->unk_BE != 0) {
        t0 = (D_8008A70C->unk_BE * t0) >> 8;
        s0 = func_80014A18(s0, D_8008A70C->unk_BE, 2);
    }

    if (D_8008A47E != 0) {
        t0 = (D_8008A47E * t0) >> 8;
        s0 = func_80014A18(s0, D_8008A47E, D_8008A47C);
    }

    if ((D_8008A70C->unk_00 & 0x7FFF) < 0x100) {
        if (D_8008A47B != 0) {
            t0 = (D_8008A47B * t0) >> 8;
            s0 = func_80014A18(s0, D_8008A47B, D_8008A479);
        }

        if (D_8008A484 != 0) {
            t0 = (D_8008A484 * t0) >> 8;
            if (D_8008A483 < 0) {
                s0 = func_80014A18(s0, D_8008A484, 2);
            }
        }
    }

    for (i = 0; i < 1; i++) {
        if ((D_8008A70C->unk_00 & 0x7FFF) == D_8008A486[i]) {
            t0 = (D_8008A485[i] * t0) >> 8;
            s0 = func_80014A18(s0, D_8008A485[i], 2);
            break;
        }
    }

    if (D_8008A70C->unk_B4 != (s16) t0 || D_8008A70C->unk_B6 != (u16) s0) {
        D_8008A70C->unk_B4 = t0;
        D_8008A70C->unk_B6 = s0;
        alSynSetVol(&alGlobals->drvr, &D_8008A548[D_8008A474], t0, s0 * 5000);
    }
}

s32 func_80014A18(s32 arg0, u8 arg1, u8 arg2) {
    if (D_8008A70C->unk_49 >= 2) {
        if (arg0 < 0x200) {
            arg0 = (arg1 * arg0) >> 8;
        } else {
            arg0 = arg1 * arg2 * 2;
        }
    }

    return arg0;
}

void func_80014A74(void) {
    D_8008A70C->unk_4C = 0;
    if (D_8008A70C->unk_4E != 0) {
        D_8008A70C->unk_4A = 0x20;
        func_80014708();
        D_8008A70C->unk_49 = 0;
        D_8008A70C->unk_4A = 0x100;
        D_8008A70C->unk_4C = D_8008A70C->unk_4E;
        func_80014708();
    } else {
        D_8008A70C->unk_4A = 0x100;
        func_80014708();
        func_80014B00();
    }
}

void func_80014B00(void) {
    if (D_8008A70C->unk_54 != 0) {
        D_8008A70C->unk_49 = 1;
        D_8008A70C->unk_4A -= D_8008A70C->unk_54;
        D_8008A70C->unk_4C = D_8008A70C->unk_50;
        func_80014708();
    } else {
        func_80014B6C();
    }
}

void func_80014B6C(void) {
    D_8008A70C->unk_49 = 2;
    if (D_8008A70C->unk_52 != 0) {
        D_8008A70C->unk_4A = 0;
        D_8008A70C->unk_4C = D_8008A70C->unk_52;
        func_80014708();
    }
}

void func_80014BBC(void) {
    D_8008A70C->unk_49 = 3;
    D_8008A70C->unk_4A = 0;
    D_8008A70C->unk_4C = D_8008A70C->unk_56;
    func_80014708();
}

void func_80014C00(void) {
    D_8008A70C->unk_0F = 1;
    D_8008A70C->unk_49 = 3;
    D_8008A70C->unk_4A = 0;
    D_8008A70C->unk_4C = 1;
    func_80014708();
}

void func_80014C4C(void) {
    D_8008A70C->unk_4C--;
    if (D_8008A70C->unk_B6 != 0) {
        D_8008A70C->unk_B6--;
    }
    if (D_8008A70C->unk_4C == 0) {
        switch (D_8008A70C->unk_49) {
            case 0:
                func_80014B00();
                break;
            case 1:
                func_80014B6C();
                break;
        }
    }
}
