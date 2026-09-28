#include "common.h"

s32 func_80006B88(Task *);
s32 func_80006D78(Task *);

void func_80006940(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 0xE0; i++) {
        D_80044254->objects[i].flags = 0;
        D_80044254->objects[i].unk_43E = 0;
        D_80044254->objects[i].unk_43F = 0;
        D_80044254->objects[i].unk_04 = 0;
        D_80044254->objects[i].unk_1C = 0;
        D_80044254->objects[i].parent = 0;
        D_80044254->objects[i].unk_20 = 0;
        D_80044254->objects[i].unk_10 = 0;
        D_80044254->objects[i].unk_14 = 0;
        D_80044254->objects[i].unk_18 = NULL;
        D_80044254->objects[i].unk_0C = NULL;

        for (j = 0; j < 16; j++) {
            D_80044254->objects[i].unk_24[j] = 0;
        }

        for (j = 0; j < 4; j++) {
            D_80044254->objects[i].children[j] = 255;
        }
    }
}

s32 func_80006AC4(Task *task) {
    task_run_all(D_80044264);
    return TASK_CONTINUE;
}

s32 func_80006AF0(Task *task) {
    Object *a3;

    a3 = (Object *) task->privData;
    if ((a3->flags & 0x20000) || a3->unk_04 != NULL && a3->unk_04() == 0) {
        task->func = func_80006D78;
        a3->unk_43E = task->taskId;
        a3->flags |= 0x50000;
        a3->unk_24[0] = 0;
        task_create(D_80044260, 20, func_80006B88, a3);
    }
    return TASK_CONTINUE;
}

s32 func_80006B88(Task *task) {
    s32 i;
    Object *s2;
    UnkStructC *sc;

    s2 = (Object *) task->privData;

    if (!s2->unk_24[0]) {
        if (s2->unk_0C != NULL) {
            sc = (UnkStructC *) s2->unk_0C->data;
            if (sc->unk_04 != NULL) {
                sc->unk_04(task);
            }
        }

        if (s2->parent != NULL) {
            for (i = 0; i < 4; i++) {
                if (s2->parent->children[i] == s2->unk_43E) {
                    s2->parent->children[i] = 255;
                }
            }
        }

        for (i = 0; i < 4; i++) {
            if (s2->children[i] != 255) {
                func_800091E8(s2->children[i], 0x20000, 1);
                s2->children[i] = 255;
            }
        }
    }

    if (s2->unk_24[0] < 2) {
        s2->unk_24[0]++;
        return TASK_CONTINUE;
    } else {
        if (s2->unk_0C != NULL) {
            sc = (UnkStructC *) s2->unk_0C->data;
            for (i = 0; i < 2; i++) {
                mem_free(sc->unk_10[i]);
                mem_free(sc->unk_08[i]);
            }
            mem_free(s2->unk_0C);
        }

        for (i = 0; i < 16; i++) {
            s2->unk_24[i] = 0;
        }

        if (s2->unk_20 != NULL) {
            mem_free(s2->unk_20);
        }

        s2->flags = 0;
        s2->unk_04 = 0;
        s2->unk_1C = 0;
        s2->unk_10 = 0;
        s2->unk_14 = 0;
        s2->unk_18 = NULL;
        s2->unk_43F = 0;
        s2->unk_43E = 255;
        s2->parent = NULL;

        return TASK_DONE;
    }
}

s32 func_80006D78(Task *task) {
    Object *a3;

    a3 = (Object *) task->privData;
    if (a3->flags != 0) {
        return TASK_CONTINUE;
    } else {
        return TASK_DONE;
    }
}

#ifdef NON_EQUIVALENT
s32 func_80006D9C(Task *task) {
    Camera *t5;
    Task *s1;
    Struct4Sub5 *a3;
    Object *t3;
    UnkStruct34 *t0;
    f32 fv0;
    s32 v0;
    Struct4Sub5 *a1;
    Struct4Sub5 *a0;
    Struct4Sub5 *v1;

    t5 = &D_80044254->cameras[0];
    s1 = &D_80044264->rootTask;
    a3 = D_80044244->unk_04;
    a3 += D_80044254->unk_76C7C;

    while (TRUE) {
        s1 = s1->next;
        if (s1->flags & TASK_FLAG_LAST) {
            break;
        }

        t3 = (Object *) task->privData;
        if (t3->flags & 0x70000) {
            continue;
        }

        if (t3->flags & 0x2000000) {
            for (t0 = t3->unk_1C; t0->unk_00 != 255; t0++) {
                if (t0->unk_00 == 0 && D_80044254->unk_76C7C < 300) {
                    fv0 = t3->position.z + t0->unk_14 - t5->zEye;
                    if (!(D_80044254->flags & 1)) {
                        v0 = (106.0 - fv0 / -10.0) + 5.0;
                    } else {
                        v0 = fv0 / -10.0;
                    }

                    if (v0 < 111 && v0 >= 0) {
                        a3->unk_00 = 2;
                        a3->unk_04 = NULL;
                        a3->unk_08 = t3; // ??
                        a3->unk_0C = t0;
                        a3->unk_10 = fv0;

                        a0 = a1 = D_80044254->unk_768F8[v0].unk_00;
                        if (a1 != NULL) {
                            v1 = a1;
                            while (TRUE) {
                                if (v1->unk_10 > fv0) {
                                    if (v1 == a0) {
                                        a3->unk_04 = v1;
                                        D_80044254->unk_768F8[v0].unk_00 = a3;
                                    } else {
                                        a3->unk_04 = a0->unk_04;
                                        a0->unk_04 = a3;
                                    }
                                    break;
                                }

                                a0 = v1;
                                if (v1->unk_04 == NULL) {
                                    v1->unk_04 = a3;
                                    break;
                                }

                                v1 = v1->unk_04;
                            }
                        } else {
                            D_80044254->unk_768F8[v0].unk_00 = a3;
                        }

                        a3++;
                        D_80044254->unk_76C7C++;
                        D_80044254->unk_00[D_80044254->cfbIdx].unk_1C800[t3->flags & 7] += 0x400;
                    }
                }
            }
        } else {
            if (t3->flags & 0x1DC00000 && D_80044254->unk_76C7C < 300) {
                fv0 = t3->position.z - t5->zEye;
                v0 = 111.0 - fv0 / -10.0;

                if (v0 >= 0 && v0 < 111) {
                    a3->unk_00 = 1;
                    a3->unk_04 = NULL;
                    a3->unk_08 = t3; // ??
                    a3->unk_0C = NULL;
                    a3->unk_10 = fv0;

                    a0 = a1 = D_80044254->unk_768F8[v0].unk_00;
                    if (a1 != NULL) {
                        v1 = a1;
                        while (TRUE) {
                            if (v1->unk_10 > fv0) {
                                if (v1 == a0) {
                                    a3->unk_04 = v1;
                                    D_80044254->unk_768F8[v0].unk_00 = a3;
                                } else {
                                    a3->unk_04 = a0->unk_04;
                                    a0->unk_04 = a3;
                                }
                                break;
                            }

                            a0 = v1;
                            if (v1->unk_04 == NULL) {
                                v1->unk_04 = a3;
                                break;
                            }

                            v1 = v1->unk_04;
                        }
                    } else {
                        D_80044254->unk_768F8[v0].unk_00 = a3;
                    }

                    a3++;
                    D_80044254->unk_76C7C++;
                    D_80044254->unk_00[D_80044254->cfbIdx].unk_1C800[t3->flags & 7] += 0x80;
                }
            }
        }
    }

    func_80004AC4();
    return TASK_CONTINUE;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80006D9C.s")
#endif

#ifdef NON_EQUIVALENT
s32 func_800071A8(Task *task) {
    Object *t1;
    s32 t0;
    UnkStructG *a0;
    s32 i;
    u16 t4;
    s16 r1, g1, b1;
    s16 r2, g2, b2;
    s16 r3, g3, b3;
    s16 *ptr;
    s16 *ptr2;

    t1 = (Object *) task->privData;
    if (t1->flags == 0 || (t1->flags & 0x30000)) {
        return TASK_DONE;
    }

    a0 = (UnkStructG *) task->unk_08->data;

    if (a0->unk_204 & 0x14400000) {
        t0 = 0x10;
    } else {
        t0 = 0x100;
    }

    if (a0->unk_20D >= a0->unk_20C) {
        r1 = a0->unk_206 >> 11;
        g1 = (a0->unk_206 & 0x7FF) >> 6;
        b1 = (a0->unk_206 & 0x3F) >> 1;

        ptr = a0->unk_200;

        for (i = 0; i < t0; i++) {
            t4 = *ptr++;

            if (t4 & 1) {
                if (a0->unk_204 & 0x4000) {
                    r2 = t4 >> 11;
                    g2 = (t4 & 0x7FF) >> 6;
                    b2 = (t4 & 0x3F) >> 1;

                    r3 = r1 + (r1 - r2) * a0->unk_208 / 100;
                    g3 = g1 + (g1 - g2) * a0->unk_208 / 100;
                    b3 = b1 + (b1 - b2) * a0->unk_208 / 100;
                } else {
                    r2 = t4 >> 11;
                    g2 = (t4 & 0x7FF) >> 6;
                    b2 = (t4 & 0x3F) >> 1;

                    r3 = r1 + (r1 - r2) * (100 - a0->unk_208) / 100;
                    g3 = g1 + (g1 - g2) * (100 - a0->unk_208) / 100;
                    b3 = b1 + (b1 - b2) * (100 - a0->unk_208) / 100;
                }
                t4 = (r3 << 11) | (g3 << 6) || (b3 << 1) | 1;
            }

            a0->unk_00[i] = t4;
        }

        if (a0->unk_204 & 0x4000) {
            t1->unk_43E = 255 - a0->unk_208 * 255 / 100;
            if (a0->unk_208 >= 100 - a0->unk_20A) {
                t1->flags |= 0x40000;
            }
        } else {
            t1->unk_43E = a0->unk_208 * 255 / 100;
        }

        a0->unk_208 += a0->unk_20A;
        a0->unk_20D = 0;
    }

    if (a0->unk_208 >= 100) {
        t1->flags &= ~0x80000;
        t1->unk_18 = a0->unk_200;
        return TASK_DONE;
    } else {
        t1->unk_18 = ((UnkStructG *) task->unk_08->data)->unk_00;
        a0->unk_20D++;
        return TASK_CONTINUE;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800071A8.s")
#endif

s32 func_80007654(Task *unused) {
    Task *task;
    Object *v1;
    Object *a1;

    task = &D_80044264->rootTask;
    while (TRUE) {
        task = task->next;
        if (task->flags & TASK_FLAG_LAST) {
            break;
        }

        v1 = (Object *) task->privData;
        if ((v1->flags & 0x80000000) && !(v1->flags & 0x10000)) {
            a1 = v1->parent;
            v1->flags = (v1->flags & 7) | (~7 & (a1->flags | 0x80000000));
            v1->unk_10 = a1->unk_10;
            v1->unk_14 = a1->unk_14;
            v1->unk_18 = a1->unk_18;
            v1->unk_43C = a1->unk_43C;
            v1->unk_43E = a1->unk_43E;
            v1->unk_43F = a1->unk_43F;
        }
    }

    return TASK_CONTINUE;
}

#ifdef NON_MATCHING
s32 func_800076FC(Task *task) {
    Object *a3;

    a3 = (Object *) task->privData;
    if ((a3->parent->flags & 0x20000) || (a3->flags & 0x230000) || a3->unk_04 != NULL && a3->unk_04() == 0) {
        task->func = func_80006D78;
        a3->unk_43E = task->taskId;
        a3->flags |= 0x50000;
        a3->unk_24[0] = 0;
        task_create(D_80044260, 20, func_80006B88, a3);
    } else {
        a3->flags = (a3->flags & 7) | (~7 & (a3->flags | 0x80000000));
    }

    return TASK_CONTINUE;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800076FC.s")
s32 func_800076FC(Task *task);
#endif

s32 func_800077D4(Task *unused) {
    Task *task;
    Object *s1;
    UnkStructC *s0;

    task = &D_80044264->rootTask;
    while (TRUE) {
        task = task->next;
        if (task->flags & TASK_FLAG_LAST) {
            break;
        }

        s1 = (Object *) task->privData;
        if (s1->unk_0C != NULL) {
            s0 = (UnkStructC *) s1->unk_0C->data;

            if (s0->unk_1C >= 0) {
                s0->unk_1C++;
                if (s0->unk_1C >= 2) {
                    mem_free(s0->unk_08[s0->unk_26]);
                    mem_free(s0->unk_10[s0->unk_26]);
                    s0->unk_1C = -1;
                }
            }

            if (!(s1->flags & 0x170880)) {
                s0->unk_27--;

                if (!(s0->unk_27 & 0x7F)) {
                    if (s0->unk_27 & 0x80) {
                        s0->unk_24 = s0->unk_22;

                        if (s1->flags & 0x400) {
                            s1->flags |= 0x20000;
                        }

                        if (s0->unk_00 != NULL) {
                            s0->unk_00(task);
                        }
                    } else {
                        s0->unk_24++;
                    }

                    s1->flags |= 0x100;
                }
            }
        }
    }

    return TASK_CONTINUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000792C.s")

s32 func_800083BC(Task *unused) {
    Task *task;
    Object *obj;
    Transform *trans;
    s32 flags;

    flags = 0;

    task = &D_80044264->rootTask;
    while (TRUE) {
        task = task->next;
        if (task->flags & TASK_FLAG_LAST) {
            break;
        }

        obj = (Object *) task->privData;

        if (obj->flags & 0x51C70000) {
            continue;
        }

        trans = &obj->trans[D_80044254->cfbIdx];

        if (obj->position.x != trans->position.x || obj->position.y != trans->position.y ||
            obj->position.z != trans->position.z) {
            guTranslateF(trans->mtxTrans, obj->position.x, -obj->position.y, obj->position.z);
            flags |= 1;
            trans->position.x = obj->position.x;
            trans->position.y = obj->position.y;
            trans->position.z = obj->position.z;
        }

        if (obj->rotation.x != trans->rotation.x) {
            guRotateF(trans->mtxRotateX, obj->rotation.x, 1.0f, 0.0f, 0.0f);
            flags |= 2;
            trans->rotation.x = obj->rotation.x;
        }

        if (obj->rotation.y != trans->rotation.y) {
            guRotateF(trans->mtxRotateY, obj->rotation.y, 0.0f, 1.0f, 0.0f);
            flags |= 4;
            trans->rotation.y = obj->rotation.y;
        }

        if (obj->rotation.z != trans->rotation.z) {
            guRotateF(trans->mtxRotateZ, obj->rotation.z, 0.0f, 0.0f, 1.0f);
            flags |= 8;
            trans->rotation.z = obj->rotation.z;
        }

        if (obj->scale.x != trans->scale.x || obj->scale.y != trans->scale.y || obj->scale.z != trans->scale.z) {
            guScaleF(trans->mtxScale, obj->scale.x, obj->scale.y, obj->scale.z);
            flags |= 0x10;
            trans->scale.x = obj->scale.x;
            trans->scale.y = obj->scale.y;
            trans->scale.z = obj->scale.z;
        }

        if (flags != 0) {
            guMtxIdentF(trans->mtxModel);
            flags = 0;

            guMtxCatF(trans->mtxTrans, trans->mtxModel, trans->mtxModel);
            if (obj->rotation.x != 0.0) {
                guMtxCatF(trans->mtxRotateX, trans->mtxModel, trans->mtxModel);
            }
            if (obj->rotation.y != 0.0) {
                guMtxCatF(trans->mtxRotateY, trans->mtxModel, trans->mtxModel);
            }
            if (obj->rotation.z != 0.0) {
                guMtxCatF(trans->mtxRotateZ, trans->mtxModel, trans->mtxModel);
            }
            guMtxCatF(trans->mtxScale, trans->mtxModel, trans->mtxModel);
            guMtxF2L(trans->mtxModel, &trans->rspMatrix);
        }
    }

    return TASK_CONTINUE;
}

s32 func_80008720(Task *unused) {
    Task *task;
    Object *obj;
    Transform *trans;

    task = &D_80044264->rootTask;
    while (TRUE) {
        task = task->next;
        if (task->flags & TASK_FLAG_LAST) {
            break;
        }

        obj = (Object *) task->privData;

        if (obj->flags & 0x51C70000) {
            continue;
        }

        trans = &obj->trans[D_80044254->cfbIdx];

        trans->position.x = obj->position.x;
        trans->position.y = obj->position.y;
        trans->position.z = obj->position.z;
        trans->rotation.x = obj->rotation.x;
        trans->rotation.y = obj->rotation.y;
        trans->rotation.z = obj->rotation.z;
        trans->scale.x = obj->scale.x;
        trans->scale.y = obj->scale.y;
        trans->scale.z = obj->scale.z;

        guTranslateF(trans->mtxTrans, obj->position.x, -obj->position.y, obj->position.z);
        guRotateF(trans->mtxRotateX, obj->rotation.x, 1.0f, 0.0f, 0.0f);
        guRotateF(trans->mtxRotateY, obj->rotation.y, 0.0f, 1.0f, 0.0f);
        guRotateF(trans->mtxRotateZ, obj->rotation.z, 0.0f, 0.0f, 1.0f);
        guScaleF(trans->mtxScale, obj->scale.x, obj->scale.y, obj->scale.z);

        guMtxIdentF(trans->mtxModel);
        guMtxCatF(trans->mtxTrans, trans->mtxModel, trans->mtxModel);
        guMtxCatF(trans->mtxRotateX, trans->mtxModel, trans->mtxModel);
        guMtxCatF(trans->mtxRotateY, trans->mtxModel, trans->mtxModel);
        guMtxCatF(trans->mtxRotateZ, trans->mtxModel, trans->mtxModel);
        guMtxCatF(trans->mtxScale, trans->mtxModel, trans->mtxModel);
        guMtxF2L(trans->mtxModel, &trans->rspMatrix);
    }

    D_80029F30++;
    if (D_80029F30 > 1) {
        func_8000C924(D_80044264, func_800083BC, 0);
        D_80029F30 = 0;
    }

    return TASK_CONTINUE;
}

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80008988.s")

// UNUSED
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80008B2C.s")

// UNUSED
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80008D60.s")

// UNUSED
#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80008DBC.s")

s32 func_80008E0C(u8 priority, s32 flags, s32 (*arg2)(void), s32 arg3, s32 arg4, u16 *arg5) {
    Object *v1;
    s32 taskId;
    Task *task;

    taskId = task_create(D_80044264, priority, func_80006AF0, NULL);
    if (taskId < 0) {
        taskId = -1;
        v1->flags = 0; // v1 not initialized
    } else {
        task = &D_80044264->tasks[taskId];
        v1 = &D_80044254->objects[taskId];
        task->privData = v1;

        v1->unk_04 = arg2;
        if (!(flags & 7)) {
            flags |= 1;
        }
        v1->flags = flags;
        v1->unk_14 = arg3;
        v1->unk_10 = arg4;
        if (arg5 != NULL) {
            v1->unk_18 = arg5;
        }
        v1->unk_43E = 255;
        v1->position.x = 0.0f;
        v1->position.y = 0.0f;
        v1->position.z = 0.0f;
        v1->rotation.x = 0.0f;
        v1->rotation.y = 0.0f;
        v1->rotation.z = 0.0f;
        v1->scale.x = 1.0f;
        v1->scale.y = 1.0f;
        v1->scale.z = 1.0f;
    }
    return taskId;
}

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80008F20.s")

s32 func_80008F64(u8 arg0, s32 arg1, s32 (*arg2)(void), UnkStruct34 *arg3, s32 arg4, s32 arg5) {
    Object *v1;
    s32 taskId;
    Task *task;

    taskId = task_create(D_80044264, arg0, func_80006AF0, NULL);
    if (taskId >= 0) {
        v1 = &D_80044254->objects[taskId];
        task = &D_80044264->tasks[taskId];
        task->privData = v1;

        v1->unk_04 = arg2;
        if (!(arg1 & 7)) {
            arg1 |= 1;
        }
        v1->flags = arg1 | 0x2000000;
        v1->unk_1C = arg3;
        v1->unk_10 = arg4;
        v1->unk_14 = arg5 ? arg5 : 0;
        v1->position.x = 0.0f;
        v1->position.y = 0.0f;
        v1->position.z = 0.0f;
        v1->rotation.x = 0.0f;
        v1->rotation.y = 0.0f;
        v1->rotation.z = 0.0f;
        v1->scale.x = 1.0f;
        v1->scale.y = 1.0f;
        v1->scale.z = 1.0f;
    }

    return taskId;
}

s32 func_80009070(u8 arg0, s32 (*arg2)(void)) {
    Object *v1;
    Object *a0;
    s32 taskId;
    Task *task;

    task = &D_80044260->tasks[arg0];
    taskId = task_create(D_80044264, task->priority - 1, func_800076FC, NULL);
    if (taskId >= 0) {
        v1 = &D_80044254->objects[taskId];
        task = &D_80044264->tasks[taskId];
        task->privData = v1;
        v1->unk_04 = arg2;

        a0 = &D_80044254->objects[arg0];
        a0->flags &= ~0x200000;
        v1->parent = a0;
        v1->flags = a0->flags | 0x80000000;

        v1->scale.x = 1.0f;
        v1->scale.y = 1.0f;
        v1->scale.z = 1.0f;
        v1->position.x = 0.0f;
        v1->position.y = 0.0f;
        v1->position.z = 0.0f;
        v1->rotation.x = 0.0f;
        v1->rotation.y = 0.0f;
        v1->rotation.z = 0.0f;
    }

    return taskId;
}

void func_800091A4(u8 objId, f32 x, f32 y, f32 z) {
    Object *obj;

    obj = (Object *) D_80044264->tasks[objId].privData;
    obj->position.x = x;
    obj->position.y = y;
    obj->position.z = z;
}

void func_800091E8(u8 objId, s32 flags, s32 arg2) {
    Object *obj;

    obj = (Object *) D_80044264->tasks[objId].privData;
    if (flags & 7) {
        obj->flags &= ~7;
    }

    if (arg2) {
        obj->flags |= flags;
    } else {
        obj->flags &= ~flags;
    }
}

void func_80009254(u8 id, u8 parentId) {
    s32 i;
    Object *parent;
    Object *obj;

    obj = (Object *) D_80044264->tasks[id].privData;
    parent = (Object *) D_80044264->tasks[parentId].privData;

    for (i = 0; i < 4; i++) {
        if (parent->children[i] == 255) {
            parent->children[i] = id;
            break;
        }
    }

    obj->parent = parent;
}

void func_800092C8(TaskManager *tm, u8 objId, u8 priority) {
    task_set_priority(tm, priority, &D_80044264->tasks[objId]);
}

void func_80009314(void) {
    s32 i;
    Object *obj;

    obj = D_80044254->objects;
    for (i = 0; i < 0xE0; i++, obj++) {
        if (obj->flags) {
            obj->flags |= 0x20000;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800094C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800094F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009598.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800095D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009608.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800097C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009834.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000990C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000994C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009990.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_800099D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009A54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009A94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009AD4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009B58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_80009C44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000A290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000A874.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000ADC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000B1F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000B7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/func_8000BC70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/7540/D_8002EEE0.s")
