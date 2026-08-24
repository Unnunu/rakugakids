#include "common.h"

extern u8 D_800AB534_40454;
extern s32 D_800AB448_40368;
extern Overlay D_800AB4B8_403D8[];
extern s32 D_800ACA08_41928;

s32 func_800A7790_3C6B0(s32);
void func_800A7B1C_3CA3C(void);

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A6F50_3BE70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7148_3C068.s")

void func_800A7670_3C590(s32 arg0) {
    if (arg0 != D_800ACA08_41928) {
        load_overlay(&D_800AB4B8_403D8[arg0]);
        D_800ACA08_41928 = arg0;
    }
}

s32 func_800A76BC_3C5DC(s32 arg0) {
    switch (D_800AB534_40454) {
        case 0:
            D_800AB448_40368 = 0;
            func_80000AD0(0, 0, 0, 1);
            func_80003CBC();
            func_80006940();
            D_800AB534_40454 = 1;
            break;
        case 1:
            func_800A7B1C_3CA3C();
            D_800AB534_40454 = 2;
            break;
        case 2:
            load_overlay(&D_800AB4B8_403D8[0]);
            func_8000C54C(D_80044260, 198, func_800A7790_3C6B0, NULL);
            D_800AB534_40454 = 3;
            return 0;
    }

    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7790_3C6B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7994_3C8B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7B1C_3CA3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7B94_3CAB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7BC4_3CAE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7F84_3CEA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7FB4_3CED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl3/3BE70/func_800A7FE4_3CF04.s")
