#include "common.h"

typedef struct StructOvl2 {
    /* 0x00 */ u16 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ u16 *unk_0C;
    /* 0x10 */ s16 *unk_10;
    /* 0x14 */ u16 *unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ u8 unk_1A;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
} StructOvl2; // size = 0x24

typedef struct StructOvl2A {
    /* 0x00 */ f32 xEye;
    /* 0x04 */ f32 yEye;
    /* 0x08 */ f32 zEye;
    /* 0x0C */ f32 xAt;
    /* 0x10 */ f32 yAt;
    /* 0x14 */ f32 zAt;
    /* 0x18 */ f32 fovy;
} StructOvl2A; // size = 0x1C

typedef struct StructOvl2C {
    /* 0x00 */ f32 roll;
    /* 0x04 */ f32 pitch;
    /* 0x08 */ f32 yaw;
    /* 0x0C */ f32 x;
    /* 0x10 */ f32 y;
    /* 0x14 */ f32 z;
    /* 0x18 */ f32 scale;
} StructOvl2C; // size = 0x1C

typedef struct StructOvl2B {
    /* 0x000 */ Mtx mtxPersp;
    /* 0x040 */ Mtx mtxView;
    /* 0x080 */ Mtx mtxModel;
    /* 0x0C0 */ Mtx unk_C0;
    /* 0x100 */ Mtx unk_100;
    /* 0x140 */ Mtx unk_140;
} StructOvl2B; // size = 0x180

extern StructOvl2C D_800A8250_31950;
extern StructOvl2C D_800A84F0_31BF0;
extern StructOvl2C D_800A8790_31E90;
extern StructOvl2A D_800A8A30_32130;
extern StructOvl2 D_800B0DB8_3A4B8;
extern StructOvl2 D_800B0DDC_3A4DC;
extern Gfx D_800B0E00_3A500[];
extern Gfx D_800B0EA0_3A5A0[];
extern Gfx D_800B0F28_3A628[];
extern Gfx D_800B18B8_3AFB8[];
extern Gfx D_800B2248_3B948[];

StructOvl2B D_800B2770_3BE70[2];
s32 D_800B2A70_3C170;
s32 D_800B2A74_3C174;
s32 D_800B2A78_3C178;
f32 D_800B2A7C_3C17C;
s32 D_800B2A80_3C180;
Gfx *D_800B2A84_3C184;
s32 D_800B2A88_3C188;
s32 D_800B2A8C_3C18C;
s32 D_800B2A90_3C190;
s32 D_800B2A94_3C194;
s32 D_800B2A98_3C198;
StructOvl2 D_800B2AA0_3C1A0;

void func_800A6FAC_306AC(void);
void func_800A6FFC_306FC(void);
void func_800A79F4_310F4(StructOvl2 *);
void func_800A7094_30794(void);
void func_800A73F4_30AF4(u8);
void func_800A7464_30B64(void);
void func_800A7A30_31130(void);
void func_800A7590_30C90(Gfx *, Mtx *, StructOvl2C *, s32, f32);
void func_800A7B5C_3125C(StructOvl2 *arg0);
void func_800A7728_30E28(StructOvl2B *arg0, StructOvl2A *arg1, s32 arg2, f32 arg3);

void func_800A6F50_30650(void) {
    void (*sp18[])(void) = { func_800A6FAC_306AC, func_800A6FFC_306FC };
    sp18[D_80044254->unk_39C9D]();
}

Vp D_800B26A8_3BDA8 = { { { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 2) << 2, G_MAXZ / 2, 0 },
                          { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 2) << 2, G_MAXZ / 2, 0 } } };
Gfx D_800B26B8_3BDB8[] = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsDPSetBlendColor(0, 0, 0, 1),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsSPEndDisplayList(),
};

void func_800A6FAC_306AC(void) {
    func_800A7094_30794();
    func_800A79F4_310F4(&D_800B0DDC_3A4DC);
    D_80044254->unk_39C9D++;
}

void func_800A6FFC_306FC(void) {
    if (D_80044254->inputs[0].unk_04 & 0x1000) {
        if (D_800B2A70_3C170 == 1) {
            D_800B2A70_3C170 = 2;
        } else if (D_800B2A70_3C170 >= 2) {
            D_800B2A98_3C198 = 0x30;
        }
    }
    if (D_800B2A70_3C170 == 5) {
        D_80044254->unk_39C9C = 1;
        D_80044254->flags = 0;
    }
}

void func_800A7094_30794(void) {
    D_800B2A78_3C178 = 0;
    D_800B2A7C_3C17C = 0.0f;
    D_800B2A80_3C180 = 0;
    D_80044254->flags |= 0x8000;
    D_800B2A90_3C190 = 0;
    D_800B2A88_3C188 = 0;
    D_800B2A8C_3C18C = 0;
    D_800B2A94_3C194 = 0xFF;
    D_800B2A70_3C170 = 0;
    D_800B2A98_3C198 = 0x100;
}

Gfx *func_800A7110_30810(s32 arg0, Gfx *arg1) {
    u8 temp_a0;

    D_800B2A74_3C174 = arg0;
    D_800B2A84_3C184 = arg1;

    if (!(D_80044254->flags & 0x8000)) {
        return D_800B2A84_3C184;
    }
    switch (D_800B2A70_3C170) {
        case 0:
            temp_a0 = D_800B2A94_3C194;
            if (temp_a0 == 0) {
                D_800B2A70_3C170++;
            }
            func_800A7A30_31130();
            func_800A73F4_30AF4(temp_a0);
            D_800B2A94_3C194 -= 16;
            if (D_800B2A94_3C194 < 0) {
                D_800B2A94_3C194 = 0;
            }
            return D_800B2A84_3C184;
        case 1:
            if (D_800B2A7C_3C17C >= 1.0) {
                D_800B2A78_3C178++;
                D_800B2A7C_3C17C = 0.0f;
            }
            if (D_800B2A78_3C178 >= 23) {
                D_800B2A78_3C178 = 23;
                D_800B2A80_3C180 = 1;
                D_800B2A70_3C170++;
            }
            func_800A7A30_31130();
            func_800A7464_30B64();
            D_800B2A7C_3C17C += 0.25;
            return D_800B2A84_3C184;
        case 2:
            D_800B2A78_3C178 = 23;
            D_800B2A80_3C180 = 1;
            D_800B2A90_3C190++;
            if (D_800B2A90_3C190 >= 7) {
                func_80011738(25);
                func_800A79F4_310F4(&D_800B0DB8_3A4B8);
                D_800B2A90_3C190 = 0;
                D_800B2A70_3C170++;
            }
            func_800A7A30_31130();
            func_800A7464_30B64();
            return D_800B2A84_3C184;
        case 3:
            D_800B2A90_3C190++;
            if (D_800B2A90_3C190 > D_800B2A98_3C198) {
                D_800B2A94_3C194 = 0;
                D_800B2A70_3C170++;
            }
            if (D_800B2A88_3C188 != 31) {
                D_800B2A88_3C188++;
            }
            func_800A7A30_31130();
            return D_800B2A84_3C184;
        case 4:
            temp_a0 = D_800B2A94_3C194;
            if (temp_a0 == 255) {
                D_800B2A70_3C170++;
            }
            func_800A7A30_31130();
            func_800A73F4_30AF4(temp_a0);
            D_800B2A94_3C194 += 16;
            if (D_800B2A94_3C194 > 255) {
                D_800B2A94_3C194 = 0xFF;
            }
            return D_800B2A84_3C184;
        case 5:
            return D_800B2A84_3C184;
    }
}

void func_800A73F4_30AF4(u8 arg0) {
    if (arg0 != 0) {
        gDPPipeSync(D_800B2A84_3C184++);
        gDPSetPrimColor(D_800B2A84_3C184++, 0, 0, 0, 0, 0, arg0);
        gSPDisplayList(D_800B2A84_3C184++, D_800B0EA0_3A5A0);
    }
}

void func_800A7464_30B64(void) {
    StructOvl2B *s0;

    s0 = &D_800B2770_3BE70[D_800B2A74_3C174];
    func_800A7728_30E28(s0, &D_800A8A30_32130, D_800B2A78_3C178, D_800B2A7C_3C17C);
    gSPDisplayList(D_800B2A84_3C184++, D_800B0E00_3A500);
    func_800A7590_30C90(D_800B0F28_3A628, &s0->unk_C0, &D_800A84F0_31BF0, D_800B2A78_3C178, D_800B2A7C_3C17C);
    func_800A7590_30C90(D_800B18B8_3AFB8, &s0->unk_100, &D_800A8250_31950, D_800B2A78_3C178, D_800B2A7C_3C17C);
    func_800A7590_30C90(D_800B2248_3B948, &s0->unk_140, &D_800A8790_31E90, D_800B2A78_3C178, D_800B2A7C_3C17C);
    gDPPipeSync(D_800B2A84_3C184++);
}

#ifdef NON_EQUIVALENT
void func_800A7590_30C90(Gfx *arg0, Mtx *arg1, StructOvl2C *arg2, s32 arg3, f32 arg4) {
    StructOvl2C *s0;
    StructOvl2C *v0;
    f32 sp40, sp3C, sp38;
    f32 sp34, sp30, sp2C;
    f32 scale;

    s0 = arg2 + arg3;
    v0 = s0 + 1;

    if (D_800B2A80_3C180 == 1) {
        v0 = s0;
    }

    sp40 = s0->x + (v0->x - s0->x) * arg4;
    sp3C = s0->y + (v0->y - s0->y) * arg4;
    sp38 = s0->z + (v0->z - s0->z) * arg4;

    sp34 = s0->roll + (v0->roll - s0->roll) * arg4;
    sp30 = s0->pitch + (v0->pitch - s0->pitch) * arg4;
    sp2C = s0->yaw + (v0->yaw - s0->yaw) * arg4;

    scale = s0->scale + (v0->scale - s0->scale) * arg4;

    guPosition(arg1, sp34, sp30, sp2C, scale * 0.01, sp40, sp3C, sp38);
    gSPMatrix(D_800B2A84_3C184++, arg1, G_MTX_PUSH | G_MTX_MUL | G_MTX_MODELVIEW);
    gSPDisplayList(D_800B2A84_3C184++, arg0);
    gSPPopMatrix(D_800B2A84_3C184++, G_MTX_MODELVIEW);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl2/30650/func_800A7590_30C90.s")
#endif

#ifdef NON_EQUIVALENT
void func_800A7728_30E28(StructOvl2B *arg0, StructOvl2A *arg1, s32 arg2, f32 arg3) {
    StructOvl2A *s2;
    u16 sp92;
    f32 sp8C, sp88, sp84;
    f32 sp80, sp7C, sp78;
    StructOvl2A *v0;
    f32 fovy;
    Mtx *pad;

    s2 = &arg1[arg2];
    v0 = &arg1[arg2 + 1];

    if (D_800B2A80_3C180 == 1) {
        v0 = &arg1[arg2];
    }

    sp8C = s2->xEye + (v0->xEye - s2->xEye) * arg3;
    sp88 = s2->yEye + (v0->yEye - s2->yEye) * arg3;
    sp84 = s2->zEye + (v0->zEye - s2->zEye) * arg3;
    sp80 = s2->xAt + (v0->xAt - s2->xAt) * arg3;
    sp7C = s2->yAt + (v0->yAt - s2->yAt) * arg3;
    sp78 = s2->zAt + (v0->zAt - s2->zAt) * arg3;
    fovy = s2->fovy + (v0->fovy - s2->fovy) * arg3;

    gSPViewport(D_800B2A84_3C184++, &D_800B26A8_3BDA8);

    guPerspective(&arg0->mtxPersp, &sp92, fovy, 4.0f / 3.0f, 1.0f, 1000.0f, 1.0f);
    gSPPerspNormalize(D_800B2A84_3C184++, sp92);
    gSPMatrix(D_800B2A84_3C184++, &arg0->mtxPersp, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    guLookAt(&arg0->mtxView, sp8C, sp88, sp84, sp80, sp7C, sp78, 0.0f, 1.0f, 0.0f);
    gSPMatrix(D_800B2A84_3C184++, &arg0->mtxView, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

    gSPClipRatio(D_800B2A84_3C184++, FRUSTRATIO_3);
    gDPSetScissor(D_800B2A84_3C184++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);

    guMtxIdent(&arg0->mtxModel);
    gSPMatrix(D_800B2A84_3C184++, &arg0->mtxModel, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl2/30650/func_800A7728_30E28.s")
#endif

void func_800A79F4_310F4(StructOvl2 *arg0) {
    D_800B2AA0_3C1A0 = *arg0;
}

void func_800A7A30_31130(void) {
    u16 *palette;
    u16 **temp;

    temp = &D_800B2AA0_3C1A0.unk_14;

    if (D_800B2AA0_3C1A0.unk_00) {
        gSPDisplayList(D_800B2A84_3C184++, D_800B26B8_3BDB8);
        palette = (*temp) + 16 * D_800B2A88_3C188;
        gDPLoadTLUT_pal16(D_800B2A84_3C184++, 0, palette);
        func_800A7B5C_3125C(&D_800B2AA0_3C1A0);
        gDPPipeSync(D_800B2A84_3C184++);
    }
}

#ifdef NON_EQUIVALENT
void func_800A7B5C_3125C(StructOvl2 *arg0) {
    u16 temp_a0_3;
    s32 sp138;
    s32 pad[19];
    s32 sp100;
    s32 spF8;
    s32 spF0;
    s32 spE8;
    s8 *spE4;
    s16 *spE0;
    s16 temp_a1_2;
    s16 temp_a2;
    s16 temp_a3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_t8;
    s32 temp_v0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;

    u16 temp_t4;
    s32 tmp;
    s32 t5;
    s32 v0;

    spE4 = arg0->unk_04;
    spE0 = arg0->unk_08;

    sp100 = 0xFFFF;

    for (sp138 = 0; sp138 < 9; sp138++) {
        if (sp138 < 0) {
            continue;
        }
        if (sp138 >= 0xFFFF) {
            continue;
        }
        spF8 = sp138 * 32;
        spF0 = spF8 + 0x1F;
        spE8 = 0;
        if (spF8 >= 0xF0 || spF0 < 0) {
            continue;
        }

        if (sp138 < 0) {
            spE8 = -spF8;
            spF8 = 0;
        }
        if (spF0 > 239) {
            spF0 = 239;
        }
        spF8 <<= 2;
        spF0 <<= 2;

        for (var_s4 = 0; var_s4 < 11; var_s4++) {
            if (var_s4 < 0 || var_s4 >= 0xFFFF) {
                continue;
            }
            var_s3 = 0;
            var_s1 = var_s4 * 32;
            var_s2 = var_s1 + 0x1F;

            if (var_s1 >= 0x140) {
                continue;
            }
            if (var_s2 < 0) {
                continue;
            }

            if (var_s4 < 0) {
                var_s3 = -var_s1;
                var_s1 = 0;
            }
            if (var_s2 > 0x13F) {
                var_s2 = 0x13F;
            }

            var_s2 <<= 2;
            var_s1 <<= 2;
            var_s3 <<= 5;
            spE8 <<= 5;

            tmp = spE4[((var_s4 * 32 / arg0->unk_20) % arg0->unk_1C) +
                       (arg0->unk_1C * ((temp_t8 / arg0->unk_22) % arg0->unk_1E))];
            temp_t4 = spE0[(arg0->unk_20 / 32) * tmp * (arg0->unk_22 / 32) + ((var_s4 * 32 % arg0->unk_20) / 32) +
                           (arg0->unk_20 / 32) * ((temp_t8 % arg0->unk_22) / 32)];

            if (sp100 != temp_t4) {
                sp100 = temp_t4;
                switch (arg0->unk_1A) {
                    case 0:
                        gDPLoadTextureBlock(D_800B2A84_3C184++, &arg0->unk_10[(sp100 * 1024) / 4], G_IM_FMT_RGBA,
                                            G_IM_SIZ_16b, 32, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP,
                                            5, 5, G_TX_NOLOD, G_TX_NOLOD);
                        break;
                    case 1:
                        t5 = (arg0->unk_0C[sp100] & 0xFF) * 0x80 + (arg0->unk_0C[sp100] & 0xF00) * 4;
                        gDPLoadTextureBlock(D_800B2A84_3C184++, &arg0->unk_10[t5 * 4], G_IM_FMT_CI, G_IM_SIZ_8b, 32, 32,
                                            0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD,
                                            G_TX_NOLOD);
                        break;
                    case 2:
                        t5 = (arg0->unk_0C[sp100] & 0xFF) * 0x40 + (arg0->unk_0C[sp100] & 0xF00) * 4;
                        gDPLoadTextureBlock_4b(D_800B2A84_3C184++, &arg0->unk_10[t5 * 4], G_IM_FMT_CI, 32, 32, 0,
                                               G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 5, 5, G_TX_NOLOD,
                                               G_TX_NOLOD);
                        break;
                }
            }
            gSPTextureRectangle(D_800B2A84_3C184++, var_s1, spF8, var_s2, spF0, G_TX_RENDERTILE, var_s3, spE8, 4 << 10,
                                1 << 10);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/ovl2/30650/func_800A7B5C_3125C.s")
#endif
