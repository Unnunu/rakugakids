#include "common.h"

typedef struct Struct6 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ Struct4Sub5 *unk_04;
} Struct6; // size >= 8

const char string1[] = "DMA WAIT in romCopy\n";
const char string2[] = "System Wowk";
const char string3[] = "List";
const char string4[] = "ObjList";
const char string5[] = "FONT HEAP";
const char string6[] = "ScDmaTrans Work";
const char string7[] = "ScLzssDecode";
const char string8[] = "ScHuffmanDecode";
const char string9[] = "FontHeap";

extern Struct6 *D_80044244;

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_800032B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_800032FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003B30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003CBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003D20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80003D40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_800049AC.s")

#ifdef NON_MATCHING
void func_80004AC4(void) {
    s32 i;
    Struct4Sub5 *v0;
    Struct4Sub5 *a0;
    Struct4Sub5 *a1;
    CameraSettings *v1;
    Struct4Sub2 *a11;
    f32 fv0;
    s32 ft5;

    v0 = D_80044244->unk_04;
    v1 = &D_80044254->cameras;
    if (D_80044254->unk_757F0 != NULL) {
        return;
    }
    v0 = v0 + D_80044254->unk_76C7C;

    for (i = 0; i < 64; i++) {
        a11 = &D_80044254->unk_757F4[i];
        if (a11->unk_00 != 0 && D_80044254->unk_76C7C < 300) {
            fv0 = a11->unk_08 - v1->zEye;
            ft5 = (s32) (111.0 - fv0 / -10.0);

            if (ft5 < 0 || ft5 >= 111) {
                return;
            }
            v0->unk_00 = 3;
            v0->unk_04 = 0;
            v0->unk_08 = a11;
            v0->unk_0C = 0;
            v0->unk_10 = fv0;

            if (D_80044254->unk_768F8[ft5].unk_00) {} // required to match

            a0 = D_80044254->unk_768F8[ft5].unk_00;

            if (a0 != NULL) {
                a1 = D_80044254->unk_768F8[ft5].unk_00;
                while (TRUE) {
                    if (a0->unk_10 > fv0) {
                        if (a0 == a1) {
                            v0->unk_04 = a0;
                            D_80044254->unk_768F8[ft5].unk_00 = v0;
                        } else {
                            v0->unk_04 = a1->unk_04;
                            a1->unk_04 = v0;
                        }
                        break;
                    } else {
                        if (a0->unk_04 == NULL) {
                            a0->unk_04 = v0;
                            break;
                        } else {
                            a1 = a0;
                            a0 = a0->unk_04;
                        }
                    }
                }
            } else {
                D_80044254->unk_768F8[ft5].unk_00 = v0;
            }

            v0++;
            D_80044254->unk_76C7C++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/3EB0/func_80004AC4.s")
void func_80004AC4(void);
#endif
