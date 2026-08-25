#include "common.h"

Vp D_80029D40 = { { { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 2) << 2, G_MAXZ / 2, 0 },
                    { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 2) << 2, 0, 0 } } };

Vp D_80029D50 = { { { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 4) << 2, G_MAXZ / 2, 0 },
                    { (SCREEN_WIDTH / 2) << 2, (SCREEN_HEIGHT / 4) << 2, 0, 0 } } };

CameraSettings D_80029D60[] = {
    {
        1,           // id
        NULL,        // updateFunc
        0,           // flags
        160,         // xEye
        -136,        // yEye
        331,         // zEye
        0,           // xAt
        0,           // yAt
        0,           // zAt
        0,           // xUp
        0,           // yUp
        0,           // zUp
        0,           // xAngle
        0,           // yAngle
        0,           // zAngle
        45,          // fovy
        4.0 / 3.0,   // aspect
        1,           // near
        500,         // far
        1,           // scale
        -160,        // left
        160,         // right
        -120,        // bottom
        120,         // top
        &D_80029D40, // viewport
        0,           // scissor left
        0,           // scissor top
        320,         // scissor right
        240,         // scissor bottom
    },
    {
        2,           // id
        NULL,        // updateFunc
        3,           // flags
        160,         // xEye
        -120,        // yEye
        331,         // zEye
        160,         // xAt
        -120,        // yAt
        0,           // zAt
        0,           // xUp
        1,           // yUp
        0,           // zUp
        0,           // xAngle
        0,           // yAngle
        0,           // zAngle
        40,          // fovy
        4.0 / 3.0,   // aspect
        1,           // near
        1300,        // far
        1,           // scale
        -160,        // left
        160,         // right
        -120,        // bottom
        120,         // top
        &D_80029D40, // viewport
        0,           // scissor left
        0,           // scissor top
        320,         // scissor right
        240,         // scissor bottom
    },
    {
        3,           // id
        NULL,        // updateFunc
        3,           // flags
        160,         // xEye
        -120,        // yEye
        331,         // zEye
        160,         // xAt
        -120,        // yAt
        0,           // zAt
        0,           // xUp
        1,           // yUp
        0,           // zUp
        0,           // xAngle
        0,           // yAngle
        0,           // zAngle
        40,          // fovy
        4.0 / 3.0,   // aspect
        1,           // near
        1000,        // far
        1,           // scale
        -160,        // left
        160,         // right
        -120,        // bottom
        120,         // top
        &D_80029D40, // viewport
        0,           // scissor left
        0,           // scissor top
        320,         // scissor right
        240,         // scissor bottom
    },
    {
        4,           // id
        NULL,        // updateFunc
        3,           // flags
        160,         // xEye
        -120,        // yEye
        331,         // zEye
        160,         // xAt
        -120,        // yAt
        0,           // zAt
        0,           // xUp
        1,           // yUp
        0,           // zUp
        0,           // xAngle
        0,           // yAngle
        0,           // zAngle
        40,          // fovy
        4.0 / 3.0,   // aspect
        1,           // near
        1500,        // far
        1,           // scale
        -160,        // left
        160,         // right
        -120,        // bottom
        120,         // top
        &D_80029D40, // viewport
        0,           // scissor left
        0,           // scissor top
        320,         // scissor right
        240,         // scissor bottom
    },
};

void func_80006200(void) {
    D_80044254->cameras[0].id = 0;
    D_80044254->cameras[0].updateFunc = NULL;
    D_80044254->cameras[1].id = 0;
    D_80044254->cameras[1].updateFunc = NULL;
    D_80044254->cameras[2].id = 0;
    D_80044254->cameras[2].updateFunc = NULL;
    D_80044254->cameras[3].id = 0;
    D_80044254->cameras[3].updateFunc = NULL;

    D_80044254->cameras[0] = D_80029D60[0];
}

void func_800062C4(u8 arg0, u8 arg1) {
    D_80044254->cameras[arg0] = D_80029D60[arg1];
}

s32 func_80006348(Task *arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        if (!D_80044254->cameras[i].id) {
            continue;
        }
        if (D_80044254->cameras[i].updateFunc != NULL) {
            D_80044254->cameras[i].updateFunc(&D_80044254->cameras[i]);
        }
    }
    return TASK_CONTINUE;
}

void func_800063E4(void) {
    s32 i;
    u16 perspNorm;
    CameraSettings *s1;
    StructOvl2B *s2;

    s1 = D_80044254->cameras;
    s2 = D_80044254->unk_00[D_80044254->cfbIdx].unk_1C848;

    for (i = 0; i < 4; i++, s1++, s2++) {
        if (!s1->id) {
            continue;
        }
        D_80044254->unk_00[D_80044254->cfbIdx].unk_1C820[i] = D_80044254->unk_00[D_80044254->cfbIdx].unk_1C810[i];
        D_80044258 = D_80044254->unk_00[D_80044254->cfbIdx].unk_1C810[i];

        gDPPipeSync(D_80044258++);
        gSPViewport(D_80044258++, s1->viewport);

        if (s1->flags & 2) {
            guPerspective(&s2->mtxProjection, &perspNorm, s1->fovy, s1->aspect, s1->near, s1->far, s1->scale);
            gSPPerspNormalize(D_80044258++, perspNorm);
        } else {
            guOrtho(&s2->mtxProjection, s1->left, s1->right, s1->bottom, s1->top, s1->near, s1->far, s1->scale);
        }
        gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxProjection), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        if (s1->flags & 1) {
            guLookAt(&s2->mtxView, s1->xEye, s1->yEye, s1->zEye, s1->xAt, s1->yAt, s1->zAt, s1->xUp, s1->yUp,
                     s1->xUp); // @BUG last parameter should be zUp
            gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxView), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        } else {
            guRotate(&s2->mtxRotateX, -s1->xAngle, 1.0f, 0.0f, 0.0f);
            guRotate(&s2->mtxRotateY, -s1->yAngle, 0.0f, 1.0f, 0.0f);
            guRotate(&s2->mtxRotateZ, -s1->zAngle, 0.0f, 0.0f, 1.0f);
            guTranslate(&s2->mtxView, -s1->xEye, -s1->yEye, -s1->zEye);
            gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxRotateX), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxRotateY), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxRotateZ), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
            gSPMatrix(D_80044258++, VIRTUAL_TO_PHYSICAL(&s2->mtxView), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        }

        gSPClipRatio(D_80044258++, FRUSTRATIO_3);
        gDPSetScissor(D_80044258++, G_SC_NON_INTERLACE, s1->scisLeft, s1->scisTop, s1->scisRight, s1->scisBottom);
        gDPPipeSync(D_80044258++);
        gSPEndDisplayList(D_80044258++);

        D_80044254->unk_00[D_80044254->cfbIdx].unk_1C810[i] = D_80044258;
    }
}