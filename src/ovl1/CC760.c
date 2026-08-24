#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A6F50_CC760.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A6FF8_CC808.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A7054_CC864.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A70DC_CC8EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A7164_CC974.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A71B0_CC9C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A73A4_CCBB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A7414_CCC24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A75E8_CCDF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A7F68_CD778.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A7FD8_CD7E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A8050_CD860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A81FC_CDA0C.s")

typedef struct Struct12 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ u16 *unk_04;
} Struct12; // size >= 0x8

extern Struct12 *D_800299D8;

#if 0
void func_800A82B8_CDAC8(void) {
    s16 i;

    gDPPipeSync(D_80044258++);
    gDPSetCycleType(D_80044258++, G_CYC_COPY);
    gDPPipelineMode(D_80044258++, G_PM_NPRIMITIVE);
    gDPSetTextureLOD(D_80044258++, G_TL_TILE);
    gDPSetTextureLUT(D_80044258++, G_TT_RGBA16);
    gDPSetTextureDetail(D_80044258++, G_TD_CLAMP);
    gDPSetTexturePersp(D_80044258++, G_TP_NONE);
    gDPSetTextureFilter(D_80044258++, G_TF_POINT);
    gDPSetTextureConvert(D_80044258++, G_TC_FILT);
    gDPSetAlphaCompare(D_80044258++, G_AC_THRESHOLD);
    gDPSetCombineMode(D_80044258++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(D_80044258++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetBlendColor(D_80044258++, 0, 0, 0, 1);
    gDPLoadTLUT_pal256(D_80044258++, D_800299D8->unk_04);

    for (i = 0; i < 64; i++) {}
}
#endif
#pragma GLOBAL_ASM("asm/nonmatchings/ovl1/CC760/func_800A82B8_CDAC8.s")

void func_800A8880_CE090(s32 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4) {
    Struct4Sub2 *v0;

    v0 = &D_80044254->unk_757F4[arg0];
    v0->unk_00 = arg3 | 0x80000000;
    v0->unk_04 = arg1;
    v0->unk_06 = arg2;
    v0->unk_0C = arg4;
}
