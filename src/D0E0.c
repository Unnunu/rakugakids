#include "common.h"

void func_8000C4E0(Struct7 *arg0, void (*arg1)(void), u8 *arg2) {
    u32 i;

    for (i = 0; i < 0xE0; i++) {
        arg0->unk_189D[i] = 0xDF - i;
    }
    arg0->unk_189C = 0xE0;
    arg0->unk_197D = 0;

    arg0->unk_10 = arg0;
    arg0->unk_14 = arg0;

    arg0->unk_00 = arg1;
    arg0->unk_04 = arg2;
    arg0->unk_0C = 0x38000;
    arg0->unk_1A = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C54C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C628.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C6A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C728.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C758.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C784.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C7CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C904.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C930.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000C9CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CA00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CA58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CAB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CBDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CC30.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CCA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CDE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000CFFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/D0E0/func_8000D208.s")
