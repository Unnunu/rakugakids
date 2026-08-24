#include "common.h"
#include "ld_addrs.h"

s32 func_800A71B0_CC9C0(s32);
s32 func_800A76BC_3C5DC(s32);

u16 D_80027810 = 0;
Overlay D_80027814 = { (s32) ovl1_ROM_START, (s32) ovl1_ROM_END, (s32) ovl1_VRAM, func_800A71B0_CC9C0 };
Overlay D_80027824 = { (s32) ovl2_ROM_START, (s32) ovl2_ROM_END, (s32) ovl2_VRAM, NULL };
Overlay D_80027834 = { (s32) ovl3_ROM_START, (s32) ovl3_ROM_END, (s32) ovl3_VRAM, func_800A76BC_3C5DC };

s32 func_800019E0(s32 arg0) {
    func_80001200();
    func_80005E8C(D_80028998);
    func_80005E8C(D_80028968);
    func_80005E8C(D_80029CB8);
    func_80005E8C(D_80029CC4);
    func_80005E8C(D_800296D0);
    func_80005E8C(D_8002994C);
    D_80044250 = 1;
    D_80044251 = 0;
    return 0;
}

s32 func_80001A5C(s32 arg0) {
    if (D_80044254->inputs[0].unk_02 & 0x1000) {
        load_overlay(&D_80027814);
        return 0;
    } else {
        D_80044250 = 2;
        return 0;
    }
}

s32 func_80001AB8(s32 arg0) {
    u16 temp_t2;
    u16 temp_t8;
    u16 var_v0;

    if (D_80027810 == 0) {
        D_80044251 = 1;
        load_overlay(&D_80027824);
        D_80044251 = 0;
        osViSetSpecialFeatures(OS_VI_GAMMA_ON);
        D_80027810++;
    }

    if (D_80027810 == 1) {
        D_80044254->unk_39C9D = 0;
        D_80044254->unk_39C9C = 0;
        D_80027810++;
    }

    if (D_80027810 == 2) {
        func_800A6F50_30650();
        if (D_80044254->unk_39C9C != 0) {
            D_80027810 = 0;
            D_80044254->unk_39C9D = 0;
            D_80044250 = 3;
            osViSetSpecialFeatures(OS_VI_GAMMA_OFF);
            func_80011738(1);
            return 0;
        }
    }

    return 1;
}

s32 func_80001BD0(s32 arg0) {
    load_overlay(&D_80027834);
    return 0;
}

s32 func_80001BFC(s32 arg0) {
    switch (D_80044250) {
        case 0:
            func_8000C54C(D_80044260, 200, (void (*)(s32)) func_800019E0, &D_80044250);
            break;
        case 1:
            func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 240, func_800077D4, &D_80044250), 0x8000, 1);
            func_8000C54C(D_80044260, 230, func_80006348, &D_80044250);
            func_8000C54C(D_80044260, 200, func_80001A5C, &D_80044250);
            func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 49, func_80006AC4, &D_80044250), 0x8000, 1);
            func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 46, func_8000792C, &D_80044250), 0x8000, 1);
            func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 35, func_80007654, &D_80044250), 0x8000, 1);
            func_8000C7FC(D_80044260, func_8000C54C(D_80044260, 30, func_80006D9C, &D_80044250), 0x8000, 1);
            break;
        case 2:
            func_8000C54C(D_80044260, 200, func_80001AB8, &D_80044250);
            D_80044254->unk_39C9D = 1;
            break;
        case 3:
            func_8000C54C(D_80044260, 200, func_80001BD0, &D_80044250);
            break;
        case 200:
            break;
    }
    D_80044250 = 200;

    return 1;
}
