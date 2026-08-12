#include "common.h"

typedef struct SaveStruct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ OSPfs pfs;
} SaveStruct; // size = ?

#define INPUT_DIRECTION (U_JPAD | D_JPAD | L_JPAD | R_JPAD)

extern OSMesgQueue D_8004F270;
extern OSMesg D_8004F288[1];
extern OSContStatus D_8004F290[MAXCONTROLLERS];
extern OSContPad D_8004F2A0[MAXCONTROLLERS];

void func_800059F4(SaveStruct *, s32);

void func_80004C70(void) {
    s16 i;
    u8 bitpattern;

    osCreateMesgQueue(&D_8004F270, D_8004F288, ARRAY_COUNT(D_8004F288));
    osSetEventMesg(OS_EVENT_SI, &D_8004F270, (OSMesg) 0);
    osContInit(&D_8004F270, &bitpattern, D_8004F290);

    for (i = 0; i < MAXCONTROLLERS; i++) {
        D_80044254->inputs[i].unk_00 = 0;
        if ((bitpattern & (1 << i)) && !(D_8004F290[i].errno & (CONT_NO_RESPONSE_ERROR | CONT_OVERRUN_ERROR))) {
            D_80044254->inputs[i].unk_00 |= 0x8000;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80004D68.s")

#ifdef NON_MATCHING
void func_80004DD4(void) {
    s32 i, j;
    u8 a22;
    u16 a12;
    u16 v03;
    InputData *p;
    s32 v0;

    if ((D_80044254->frameCounter % 5) == 0) {
        osContStartQuery(&D_8004F270);
        osRecvMesg(&D_8004F270, NULL, OS_MESG_BLOCK);
        osContGetQuery(D_8004F290);

        for (i = 0; i < MAXCONTROLLERS; i++) {
            if (!(D_8004F290[i].errno & (CONT_NO_RESPONSE_ERROR | CONT_OVERRUN_ERROR))) {
                D_80044254->inputs[i].unk_00 |= 0x8000;

                if (D_8004F290[i].status & CONT_CARD_ON) {
                    D_80044254->inputs[i].unk_00 |= 0x4000;
                } else {
                    D_80044254->inputs[i].unk_00 &= ~0x4000;
                }

                if (D_8004F290[i].status & CONT_CARD_PULL) {
                    D_80044254->inputs[i].unk_00 |= 0x2000;
                } else {
                    D_80044254->inputs[i].unk_00 &= ~0x2000;
                }
            } else {
                D_80044254->inputs[i].unk_00 &= ~0x8000;
            }
        }
    }

    osContStartReadData(&D_8004F270);
    osRecvMesg(&D_8004F270, NULL, OS_MESG_BLOCK);
    osContGetReadData(D_8004F2A0);

    for (i = 0, p = D_80044254->inputs; i < MAXCONTROLLERS; i++, p++) {
        if (p->unk_00 & 0x8000) {
            a22 = 0;
            a12 = 0;

            p->unk_06 = D_8004F2A0[i].stick_x;
            p->unk_08 = D_8004F2A0[i].stick_y;

            if (p->unk_00 & 0x800) {
                if (p->unk_06 < -20) {
                    a12 |= L_JPAD;
                }
                if (p->unk_06 > 20) {
                    a12 |= R_JPAD;
                }
                if (p->unk_08 > 20) {
                    a12 |= U_JPAD;
                }
                if (p->unk_08 < -20) {
                    a12 |= D_JPAD;
                }

                if (p->unk_06 < -50) {
                    a22 |= 0x80;
                }
                if (p->unk_06 > 50) {
                    a22 |= 0x80;
                }
                if (p->unk_08 > 50) {
                    a22 |= 0x80;
                }
                if (p->unk_08 < -50) {
                    a22 |= 0x80;
                }

                v03 = p->unk_0A;
            } else {
                a12 = D_8004F2A0[i].button;
                v03 = p->unk_02;
            }

            p->unk_10[0].unk_00 = v03;
            if (p->unk_10[0].unk_02 ^ 0xFF) {
                p->unk_10[0].unk_02++;
            }
            p->unk_10[0].unk_03 = a22;

            v0 = (p->unk_02 & INPUT_DIRECTION) != (a12 & INPUT_DIRECTION);
            if (v0) {
                for (j = 18; j >= 0; j--) {
                    p->unk_10[j + 1].unk_00 = p->unk_10[j].unk_00;
                    p->unk_10[j + 1].unk_02 = p->unk_10[j].unk_02;
                    p->unk_10[j + 1].unk_03 = p->unk_10[j].unk_03;
                }

                p->unk_10[0].unk_00 = 0;
                p->unk_10[0].unk_02 = 0;
                p->unk_10[0].unk_03 = 0;
                p->unk_0E = 1;
            }

            a12 = 0;
            if (p->unk_06 < -20) {
                a12 |= L_JPAD;
            }
            if (p->unk_06 > 20) {
                a12 |= R_JPAD;
            }
            if (p->unk_08 > 20) {
                a12 |= U_JPAD;
            }
            if (p->unk_08 < -20) {
                a12 |= D_JPAD;
            }

            p->unk_0C = (p->unk_0A ^ a12) & a12;
            p->unk_0A = a12;

            a12 = D_8004F2A0[i].button;
            p->unk_04 = (p->unk_02 ^ a12) & a12;
            p->unk_02 = a12;
        }
    }
}
#else
void func_80004DD4(void);
#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80004DD4.s")
#endif

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80005198.s")

s32 func_800051BC(SaveStruct *arg0, u8 arg1) {
    s8 s1;
    s32 v0;

    if (D_80044254->inputs[arg1].unk_00 & 0x8000) {

        for (s1 = 2; s1 >= 0; s1--) {
            v0 = osPfsInitPak(&D_8004F270, &arg0->pfs, arg1);
            if (v0 != 0) {
                arg0->unk_02 = 0;
                func_800059F4(arg0, v0);
                arg0->unk_08 = 0;
                arg0->unk_0C = 0;
            } else {
                arg0->unk_02 = 0x8000;
                arg0->unk_00 = arg1;
                return 1;
            }
        }

        if (s1 < 0) {
            return 0;
        }
    }

    arg0->unk_02 = 0;
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800052B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_8000534C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80005478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_8000552C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_8000560C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800056E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800057B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800057D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800058A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800059D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_800059F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80005B0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/func_80005C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/5870/D_8002EE90.s")
