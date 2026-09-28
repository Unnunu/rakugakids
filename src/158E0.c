#include "common.h"

u16 D_8002A880[128] = {
    0,    1,    2,    2,    3,    4,    5,    6,    7,    8,    9,    10,   11,   11,   12,   13,   14,   15,   16,
    17,   18,   19,   20,   21,   22,   24,   26,   28,   30,   31,   32,   34,   36,   38,   40,   42,   44,   46,
    50,   54,   58,   62,   66,   70,   74,   77,   80,   84,   88,   94,   102,  110,  118,  124,  132,  140,  148,
    154,  160,  168,  176,  192,  208,  224,  240,  254,  268,  284,  300,  314,  328,  344,  360,  390,  420,  450,
    480,  504,  528,  554,  580,  610,  640,  670,  700,  760,  820,  880,  940,  1000, 1060, 1120, 1180, 1240, 1300,
    1360, 1420, 1520, 1640, 1760, 1880, 2000, 2120, 2260, 2400, 2500, 2600, 2700, 2800, 3040, 3280, 3540, 3800, 4040,
    4280, 4540, 4800, 5040, 5280, 5540, 5800, 6200, 6600, 7000, 7600, 8200, 8800, 9600,
};
u8 D_8002A980[] = {
    0x00, 0x20, 0x38, 0x50, 0x68, 0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xE8, 0xF0, 0xF8, 0xFC,
    0xFF, 0xFC, 0xF8, 0xF0, 0xE8, 0xE0, 0xD0, 0xC0, 0xB0, 0xA0, 0x90, 0x80, 0x68, 0x50, 0x38, 0x20,
};
u8 Aud_PitchDriftNoiseTable[] = {
    159, 60,  178, 82,  175, 69,  199, 137, 16,  127, 224, 157, 220, 31,  97,  22,  57,  201, 156, 235, 87,  8,
    102, 248, 90,  36,  191, 14,  62,  21,  75,  219, 171, 245, 49,  12,  67,  2,   85,  222, 65,  218, 189, 174,
    25,  176, 72,  87,  186, 163, 54,  11,  249, 223, 23,  168, 4,   12,  224, 145, 24,  93,  221, 211, 40,  138,
    242, 17,  89,  111, 6,   10,  52,  42,  121, 172, 94,  167, 131, 198, 57,  193, 180, 58,  63,  254, 79,  239,
    31,  0,   48,  153, 76,  40,  131, 237, 138, 47,  44,  102, 63,  214, 108, 183, 73,  34,  188, 101, 250, 207,
    2,   177, 70,  240, 154, 215, 226, 15,  17,  197, 116, 246, 122, 44,  143, 251, 25,  106,
};
extern s8 D_8002AA28[];
extern s8 D_8002ADCC[];
s8 *D_8002AA20[2] = { D_8002AA28, D_8002ADCC };
s8 D_8002AA28[] = {
    16,  13,  127, 0, 0, 31, 64, // inst 0
    16,  13,  127, 0, 0, 31, 64, // inst 1
    16,  13,  127, 0, 0, 31, 64, // inst 2
    16,  13,  127, 0, 0, 31, 64, // inst 3
    5,   127, 127, 0, 0, 31, 64, // inst 4
    11,  87,  127, 0, 0, 0,  64, // inst 5
    -8,  7,   127, 0, 0, 31, 64, // inst 6
    -11, 20,  127, 0, 0, 31, 64, // inst 7
    -5,  56,  127, 0, 0, 31, 64, // inst 8
    -11, 29,  127, 0, 0, 31, 64, // inst 9
    4,   107, 127, 0, 0, 31, 64, // inst 10
    4,   87,  127, 0, 0, 31, 64, // inst 11
    6,   107, 127, 0, 0, 31, 64, // inst 12
    4,   107, 127, 0, 0, 0,  64, // inst 13
    -11, 30,  127, 0, 0, 31, 64, // inst 14
    11,  85,  127, 0, 0, 31, 64, // inst 15
    6,   101, 127, 0, 0, 31, 64, // inst 16
    7,   107, 127, 0, 0, 31, 64, // inst 17
    6,   121, 127, 0, 0, 0,  64, // inst 18
    -3,  28,  127, 0, 0, 31, 64, // inst 19
    -11, 31,  127, 0, 0, 31, 64, // inst 20
    -8,  7,   127, 0, 0, 31, 64, // inst 21
    9,   26,  127, 0, 0, 31, 64, // inst 22
    -11, 31,  127, 0, 0, 31, 64, // inst 23
    -11, 31,  127, 0, 0, 31, 64, // inst 24
    -11, 31,  127, 0, 0, 31, 64, // inst 25
    -11, 31,  127, 0, 0, 31, 64, // inst 26
    -11, 31,  127, 0, 0, 31, 64, // inst 27
    -11, 31,  127, 0, 0, 31, 64, // inst 28
    -11, 31,  127, 0, 0, 31, 64, // inst 29
    -11, 31,  127, 0, 0, 31, 64, // inst 30
    -11, 31,  127, 0, 0, 31, 64, // inst 31
    -8,  2,   127, 0, 0, 31, 64, // inst 32
    -8,  2,   127, 0, 0, 31, 64, // inst 33
    -8,  2,   127, 0, 0, 31, 64, // inst 34
    -8,  2,   127, 0, 0, 31, 64, // inst 35
    -8,  2,   127, 0, 0, 31, 64, // inst 36
    -8,  2,   127, 0, 0, 31, 64, // inst 37
    13,  119, 127, 0, 0, 31, 64, // inst 38
    11,  31,  127, 0, 0, 31, 64, // inst 39
    21,  24,  127, 0, 0, 31, 64, // inst 40
    12,  25,  127, 0, 0, 31, 64, // inst 41
    2,   40,  127, 0, 0, 31, 64, // inst 42
    -11, 30,  127, 0, 0, 31, 64, // inst 43
    -11, 30,  127, 0, 0, 25, 64, // inst 44
    -11, 30,  127, 0, 0, 25, 64, // inst 45
    -11, 30,  127, 0, 0, 31, 64, // inst 46
    -11, 30,  127, 0, 0, 31, 64, // inst 47
    -11, 30,  127, 0, 0, 31, 64, // inst 48
    -11, 30,  127, 0, 0, 31, 64, // inst 49
    -11, 30,  127, 0, 0, 31, 64, // inst 50
    -11, 30,  127, 0, 0, 31, 64, // inst 51
    -11, 30,  127, 0, 0, 31, 64, // inst 52
    -11, 29,  127, 0, 0, 31, 64, // inst 53
    -11, 29,  127, 0, 0, 31, 64, // inst 54
    -11, 29,  127, 0, 0, 31, 64, // inst 55
    -11, 29,  127, 0, 0, 31, 64, // inst 56
    -11, 29,  127, 0, 0, 31, 64, // inst 57
    -11, 29,  127, 0, 0, 31, 64, // inst 58
    -11, 29,  127, 0, 0, 31, 64, // inst 59
    -11, 29,  127, 0, 0, 31, 64, // inst 60
    -11, 30,  127, 0, 0, 31, 64, // inst 61
    -11, 30,  127, 0, 0, 31, 64, // inst 62
    -11, 29,  127, 0, 0, 31, 64, // inst 63
    -11, 29,  127, 0, 0, 31, 64, // inst 64
    -11, 29,  127, 0, 0, 31, 64, // inst 65
    -11, 29,  127, 0, 0, 31, 64, // inst 66
    -11, 30,  127, 0, 0, 31, 64, // inst 67
    -11, 30,  127, 0, 0, 31, 64, // inst 68
    -11, 29,  127, 0, 0, 31, 64, // inst 69
    -11, 29,  127, 0, 0, 31, 64, // inst 70
    -11, 29,  127, 0, 0, 31, 64, // inst 71
    -11, 29,  127, 0, 0, 31, 64, // inst 72
    -11, 30,  127, 0, 0, 31, 64, // inst 73
    -11, 30,  127, 0, 0, 31, 64, // inst 74
    -11, 29,  127, 0, 0, 31, 64, // inst 75
    -11, 29,  127, 0, 0, 31, 64, // inst 76
    -11, 29,  127, 0, 0, 31, 64, // inst 77
    -11, 29,  127, 0, 0, 31, 64, // inst 78
    -11, 29,  127, 0, 0, 31, 64, // inst 79
    -11, 29,  127, 0, 0, 31, 64, // inst 80
    -11, 29,  127, 0, 0, 31, 64, // inst 81
    -11, 29,  127, 0, 0, 31, 64, // inst 82
    -11, 29,  127, 0, 0, 31, 64, // inst 83
    -11, 29,  127, 0, 0, 31, 64, // inst 84
    -11, 29,  127, 0, 0, 31, 64, // inst 85
    -11, 29,  127, 0, 0, 31, 64, // inst 86
    -11, 30,  127, 0, 0, 31, 64, // inst 87
    -11, 29,  127, 0, 0, 31, 64, // inst 88
    -11, 29,  127, 0, 0, 31, 64, // inst 89
    -11, 29,  127, 0, 0, 31, 64, // inst 90
    -11, 30,  127, 0, 0, 31, 64, // inst 91
    -11, 29,  127, 0, 0, 31, 64, // inst 92
    -11, 29,  127, 0, 0, 31, 64, // inst 93
    -11, 29,  127, 0, 0, 31, 64, // inst 94
    -11, 29,  127, 0, 0, 31, 64, // inst 95
    -11, 29,  127, 0, 0, 31, 64, // inst 96
    -11, 29,  127, 0, 0, 31, 64, // inst 97
    -11, 30,  127, 0, 0, 31, 64, // inst 98
    -11, 29,  127, 0, 0, 31, 64, // inst 99
    -11, 29,  127, 0, 0, 31, 64, // inst 100
    -11, 29,  127, 0, 0, 31, 64, // inst 101
    -11, 29,  127, 0, 0, 31, 64, // inst 102
    -11, 29,  127, 0, 0, 31, 64, // inst 103
    -11, 29,  127, 0, 0, 31, 64, // inst 104
    -11, 29,  127, 0, 0, 31, 64, // inst 105
    -11, 29,  127, 0, 0, 31, 64, // inst 106
    -11, 29,  127, 0, 0, 31, 64, // inst 107
    -11, 29,  127, 0, 0, 31, 64, // inst 108
    -11, 30,  127, 0, 0, 31, 64, // inst 109
    -11, 29,  127, 0, 0, 31, 64, // inst 110
    -11, 29,  127, 0, 0, 31, 64, // inst 111
    -11, 29,  127, 0, 0, 31, 64, // inst 112
    -11, 30,  127, 0, 0, 31, 64, // inst 113
    -11, 29,  127, 0, 0, 31, 64, // inst 114
    -11, 30,  127, 0, 0, 31, 64, // inst 115
    -11, 30,  127, 0, 0, 31, 64, // inst 116
    -11, 29,  127, 0, 0, 31, 64, // inst 117
    -11, 29,  127, 0, 0, 31, 64, // inst 118
    -11, 29,  127, 0, 0, 31, 64, // inst 119
    -11, 29,  127, 0, 0, 31, 64, // inst 120
    -11, 29,  127, 0, 0, 31, 64, // inst 121
    -11, 29,  127, 0, 0, 31, 64, // inst 122
    -5,  57,  127, 0, 0, 31, 64, // inst 123
    -5,  56,  127, 0, 0, 31, 64, // inst 124
    -3,  -33, 127, 0, 0, 31, 64, // inst 125
    -11, 29,  127, 0, 0, 31, 64, // inst 126
    -4,  30,  127, 0, 0, 31, 64, // inst 127
    -48, 5,   127, 0, 0, 31, 64, // inst 128
    -8,  8,   127, 0, 0, 31, 64, // inst 129
    -4,  30,  127, 0, 0, 31, 64, // inst 130
    -11, 29,  127, 0, 0, 31, 64, // inst 131
    -11, 29,  127, 0, 0, 31, 64, // inst 132
};

s8 D_8002ADCC[] = {
    1,   29, 127, 0, 0, 31, 64, // inst 0
    1,   29, 127, 0, 0, 31, 64, // inst 1
    1,   29, 127, 0, 0, 31, 64, // inst 2
    1,   29, 127, 0, 0, 31, 64, // inst 3
    1,   29, 127, 0, 0, 31, 64, // inst 4
    1,   29, 127, 0, 0, 31, 64, // inst 5
    1,   29, 127, 0, 0, 31, 64, // inst 6
    1,   29, 127, 0, 0, 31, 64, // inst 7
    1,   29, 127, 0, 0, 31, 64, // inst 8
    1,   29, 127, 0, 0, 31, 64, // inst 9
    1,   29, 127, 0, 0, 31, 64, // inst 10
    1,   29, 127, 0, 0, 31, 64, // inst 11
    1,   29, 127, 0, 0, 31, 64, // inst 12
    1,   29, 127, 0, 0, 31, 64, // inst 13
    1,   29, 127, 0, 0, 31, 64, // inst 14
    1,   29, 127, 0, 0, 31, 64, // inst 15
    1,   29, 127, 0, 0, 31, 64, // inst 16
    1,   29, 127, 0, 0, 31, 64, // inst 17
    1,   29, 127, 0, 0, 31, 64, // inst 18
    1,   29, 127, 0, 0, 31, 64, // inst 19
    1,   29, 127, 0, 0, 31, 64, // inst 20
    1,   29, 127, 0, 0, 31, 64, // inst 21
    1,   29, 127, 0, 0, 31, 64, // inst 22
    1,   29, 127, 0, 0, 31, 64, // inst 23
    1,   29, 127, 0, 0, 31, 64, // inst 24
    1,   29, 127, 0, 0, 31, 64, // inst 25
    1,   29, 127, 0, 0, 31, 64, // inst 26
    1,   29, 127, 0, 0, 31, 64, // inst 27
    1,   29, 127, 0, 0, 31, 64, // inst 28
    1,   29, 127, 0, 0, 31, 64, // inst 29
    1,   29, 127, 0, 0, 31, 64, // inst 30
    1,   29, 127, 0, 0, 31, 64, // inst 31
    1,   29, 127, 0, 0, 31, 64, // inst 32
    1,   29, 127, 0, 0, 31, 64, // inst 33
    1,   29, 127, 0, 0, 31, 64, // inst 34
    1,   29, 127, 0, 0, 31, 64, // inst 35
    1,   29, 127, 0, 0, 31, 64, // inst 36
    1,   29, 127, 0, 0, 31, 64, // inst 37
    1,   29, 127, 0, 0, 31, 64, // inst 38
    1,   29, 127, 0, 0, 31, 64, // inst 39
    1,   29, 127, 0, 0, 31, 64, // inst 40
    1,   29, 127, 0, 0, 31, 64, // inst 41
    1,   29, 127, 0, 0, 31, 64, // inst 42
    1,   29, 127, 0, 0, 31, 64, // inst 43
    1,   29, 127, 0, 0, 31, 64, // inst 44
    1,   29, 127, 0, 0, 31, 64, // inst 45
    1,   29, 127, 0, 0, 31, 64, // inst 46
    1,   29, 127, 0, 0, 31, 64, // inst 47
    1,   29, 127, 0, 0, 31, 64, // inst 48
    1,   29, 127, 0, 0, 31, 64, // inst 49
    1,   29, 127, 0, 0, 31, 64, // inst 50
    1,   29, 127, 0, 0, 31, 64, // inst 51
    1,   29, 127, 0, 0, 31, 64, // inst 52
    1,   29, 127, 0, 0, 31, 64, // inst 53
    1,   29, 127, 0, 0, 31, 64, // inst 54
    1,   29, 127, 0, 0, 31, 64, // inst 55
    1,   29, 127, 0, 0, 31, 64, // inst 56
    1,   29, 127, 0, 0, 31, 64, // inst 57
    1,   29, 127, 0, 0, 31, 64, // inst 58
    1,   29, 127, 0, 0, 31, 64, // inst 59
    1,   29, 127, 0, 0, 31, 64, // inst 60
    1,   29, 127, 0, 0, 31, 64, // inst 61
    1,   29, 127, 0, 0, 31, 64, // inst 62
    1,   29, 127, 0, 0, 31, 64, // inst 63
    1,   29, 127, 0, 0, 31, 64, // inst 64
    1,   29, 127, 0, 0, 31, 64, // inst 65
    -4,  30, 127, 0, 0, 31, 64, // inst 66
    -4,  5,  127, 0, 0, 31, 64, // inst 67
    -4,  30, 127, 0, 0, 31, 64, // inst 68
    -4,  30, 127, 0, 0, 31, 64, // inst 69
    -4,  30, 127, 0, 0, 31, 64, // inst 70
    -4,  5,  127, 0, 0, 31, 64, // inst 71
    -4,  5,  127, 0, 0, 31, 64, // inst 72
    -4,  5,  127, 0, 0, 31, 64, // inst 73
    -4,  5,  127, 0, 0, 31, 64, // inst 74
    -4,  5,  127, 0, 0, 31, 64, // inst 75
    -4,  30, 127, 0, 0, 31, 64, // inst 76
    -4,  30, 127, 0, 0, 31, 64, // inst 77
    -4,  5,  127, 0, 0, 31, 64, // inst 78
    -4,  5,  127, 0, 0, 31, 64, // inst 79
    -4,  30, 127, 0, 0, 31, 64, // inst 80
    -4,  30, 127, 0, 0, 31, 64, // inst 81
    -4,  5,  127, 0, 0, 31, 64, // inst 82
    -4,  5,  127, 0, 0, 31, 64, // inst 83
    -4,  5,  127, 0, 0, 31, 64, // inst 84
    -4,  5,  127, 0, 0, 31, 64, // inst 85
    -4,  5,  127, 0, 0, 31, 64, // inst 86
    -4,  5,  127, 0, 0, 31, 64, // inst 87
    5,   20, 127, 0, 0, 31, 64, // inst 88
    5,   20, 127, 0, 0, 31, 64, // inst 89
    5,   20, 127, 0, 0, 31, 64, // inst 90
    5,   20, 127, 0, 0, 31, 64, // inst 91
    5,   20, 127, 0, 0, 31, 64, // inst 92
    -4,  30, 127, 0, 0, 31, 64, // inst 93
    -4,  30, 127, 0, 0, 31, 64, // inst 94
    -48, 5,  127, 0, 0, 31, 64, // inst 95
};

s8 D_8002B06C[7] = {
    0, 0, 127, 0, 0, 31, 64,
};

s8 D_8002B074[8] = {
    0, 0, 0, 127, 0, 0, 31, 64,
};

AudioStruct3Sub D_8002B07C[] = {
    { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0 },
};
u16 D_8002B0AC[] = { 18, 47, 42, 52, 57, 27, 31, 63 };
u8 D_8002B0BC = 255;
u8 D_8002B0C0 = 255;

void func_80014F04(s8 *);
void func_800159D4(void);
void func_8001609C(void);

void aud_seq_cmd_D0(void) {
    Aud_CurrentChannel->tempo = (*D_8008A708++) * 256;
    Aud_CurrentChannel->unk_1D = 0;
}

void aud_seq_cmd_D1(void) {
    s32 tmp;

    Aud_CurrentChannel->unk_1D = *D_8008A708++;
    Aud_CurrentChannel->unk_1C = *D_8008A708++;
    tmp = (u16) (Aud_CurrentChannel->unk_1C * 256) - Aud_CurrentChannel->tempo;
    Aud_CurrentChannel->unk_1E = tmp / Aud_CurrentChannel->unk_1D;
}

void func_80014DB8(void) {
    s32 var_v1;

    Aud_CurrentChannel->unk_1D--;
    if (Aud_CurrentChannel->unk_1D != 0) {
        var_v1 = Aud_CurrentChannel->tempo;
        var_v1 += Aud_CurrentChannel->unk_1E;
        if (var_v1 < 0x100) {
            var_v1 = 0x100;
        } else if (var_v1 > 0xFF00) {
            var_v1 = 0xFF00;
        }
        Aud_CurrentChannel->tempo = var_v1;

    } else {
        Aud_CurrentChannel->tempo = Aud_CurrentChannel->unk_1C * 256;
    }
}

void aud_seq_cmd_D2(void) {
    s8 *var_a0;
    u32 var_v0;

    var_v0 = Aud_CurrentChannel->command & 0x7F0000;
    if (var_v0 != 0) {
        var_v0 >>= 8;
        if (var_v0 < 0xA00) {
            var_v0 = 0xA00;
        } else if (var_v0 > 0x7500) {
            var_v0 = 0x7500;
        }
        Aud_CurrentChannel->unk_5B = 0;
        Aud_CurrentChannel->unk_58 = var_v0 | 0x8000;
    }
    Aud_CurrentChannel->instrumentId = *D_8008A708++;

    if (Aud_CurrentChannel->bankId < 2) {
        var_a0 = D_8002AA20[Aud_CurrentChannel->bankId];
        var_a0 += Aud_CurrentChannel->instrumentId * 7;
    } else {
        var_a0 = D_8002B06C;
    }
    func_80014F04(var_a0);
}

void func_80014F04(s8 *arg0) {
    ALBank *bank;
    ALInstrument *inst;
    ALSound *sound;
    u8 tmp;

    bank = Aud_Banks[Aud_CurrentChannel->bankId]->bankArray[0];
    inst = bank->instArray[Aud_CurrentChannel->instrumentId];
    sound = inst->soundArray[0];
    Aud_CurrentChannel->wavetable = sound->wavetable;

    Aud_CurrentChannel->keyShift = (*arg0++) << 8;
    Aud_CurrentChannel->keyShift += (*arg0++) << 2;
    Aud_CurrentChannel->attackTime = D_8002A880[0x7F - (*arg0++)];
    tmp = *arg0++;
    Aud_CurrentChannel->decayTime = D_8002A880[61 - ((tmp & 0xF0) >> 2)];
    Aud_CurrentChannel->unk_54 = (tmp & 0xF) << 2;
    tmp = *arg0++;
    Aud_CurrentChannel->sustainTime = tmp == 0 ? 0 : D_8002A880[0x7F - tmp] + 1;
    Aud_CurrentChannel->releaseTime = D_8002A880[(31 - (*arg0++)) * 4 + 1];
    if (Aud_CurrentChannel->unk_58 < 0x8000) {
        Aud_CurrentChannel->unk_58 = (*arg0++) << 8;
        Aud_CurrentChannel->unk_5B = 0;
    }

    aud_update_pan(Aud_CurrentChanId);
}

void func_80015070(void) {
    s8 *temp_a0;

    temp_a0 = D_8002B074 + (Aud_CurrentChannel->key - 72) * 8;
    Aud_CurrentChannel->instrumentId = *temp_a0++;
    func_80014F04(temp_a0);
}

void aud_seq_cmd_D3(void) {
    aud_seq_cmd_D5();
    aud_seq_cmd_D2();
}

void aud_seq_cmd_D4(void) {
    aud_seq_cmd_D5();
    aud_seq_cmd_D2();
    func_8001557C();
}

void aud_seq_cmd_D5(void) {
    u8 temp_v0;
    u32 temp;

    temp_v0 = *D_8008A708++;
    if ((Aud_CurrentChannel->command >> 0x18) != 0) {
        temp = Aud_CurrentChannel->command;
        Aud_CurrentChannel->unk_3A = temp_v0 * (temp >> 0x18);
    } else {
        Aud_CurrentChannel->unk_3A = temp_v0 * 256;
    }
    Aud_CurrentChannel->unk_47 = 0;
}

void aud_seq_cmd_D6(void) {
    s32 tmp;

    Aud_CurrentChannel->unk_47 = *D_8008A708++;
    Aud_CurrentChannel->unk_46 = *D_8008A708++;
    tmp = (u16) (Aud_CurrentChannel->unk_46 * 256) - Aud_CurrentChannel->unk_3A;
    Aud_CurrentChannel->unk_44 = tmp / Aud_CurrentChannel->unk_47;
}

void func_80015208(void) {
    s32 var_v1;

    Aud_CurrentChannel->flags |= 1;
    Aud_CurrentChannel->unk_47--;
    if (Aud_CurrentChannel->unk_47 != 0) {
        var_v1 = Aud_CurrentChannel->unk_3A;
        var_v1 += Aud_CurrentChannel->unk_44;
        if (var_v1 < 0) {
            var_v1 = 0;
        } else if (var_v1 > 0xFF00) {
            var_v1 = 0xFF00;
        }
        Aud_CurrentChannel->unk_3A = var_v1;
    } else {
        Aud_CurrentChannel->unk_3A = Aud_CurrentChannel->unk_46 << 8;
    }
}

void aud_seq_cmd_D7(void) {
    u8 tmp;

    Aud_CurrentChannel->attackTime = D_8002A880[0x7F - (*D_8008A708++)];
    tmp = *D_8008A708++;
    Aud_CurrentChannel->decayTime = D_8002A880[61 - ((tmp & 0xF0) >> 2)];
    Aud_CurrentChannel->unk_54 = (tmp & 0xF) << 2;
}

void aud_seq_cmd_D8(void) {
    u8 temp_v0;
    s32 a0;

    temp_v0 = *D_8008A708++;
    if (!temp_v0) {
        Aud_CurrentChannel->sustainTime = 0;
        if (Aud_CurrentChannel->unk_22 == 0 && Aud_CurrentChannel->envelopePhase == AL_PHASE_SUSTAIN) {
            Aud_CurrentChannel->envelopeTimer = 0x7FFF;
        }
    } else {
        a0 = Aud_CurrentChannel->sustainTime;
        Aud_CurrentChannel->sustainTime = D_8002A880[0x7F - temp_v0] + 1;
        if (Aud_CurrentChannel->unk_22 == 0 && Aud_CurrentChannel->envelopePhase == AL_PHASE_SUSTAIN) {
            Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->sustainTime;
            if (a0 == 0) {
                Aud_CurrentChannel->envelopeVolume = 0;
            }
        }
    }
}

void aud_seq_cmd_D9(void) {
    Aud_CurrentChannel->releaseTime = D_8002A880[(31 - (*D_8008A708++)) * 4 + 1];
    if (Aud_CurrentChannel->unk_22 == 0 && Aud_CurrentChannel->envelopePhase == AL_PHASE_RELEASE) {
        Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->releaseTime;
    }
}

void aud_seq_cmd_DA(void) {
    u8 v1;
    s32 value;

    if (Aud_CurrentChannel->fxAmt != 0) {
        alSynSetFXMix(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], 0);
    }

    v1 = *D_8008A708++;
    value = v1 * 40;
    if (value == 0) {
        value = Aud_FxParams[3];
    }
    alSynSetFXParam(&alGlobals->drvr, D_8008A760, 3, &value);

    v1 = *D_8008A708++;
    value = v1 * 128;
    if (value == 0) {
        value = Aud_FxParams[4];
    }
    alSynSetFXParam(&alGlobals->drvr, D_8008A760, 4, &value);

    if (Aud_CurrentChannel->fxAmt != 0) {
        alSynSetFXMix(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], Aud_CurrentChannel->fxAmt);
    }
}

void func_80015574(void) {
}

void func_8001557C(void) {
    u8 v1;

    Aud_CurrentChannel->unk_5B = 0;
    v1 = *D_8008A708++;
    Aud_CurrentChannel->unk_58 = v1 << 8;
    aud_update_pan(Aud_CurrentChanId);
}

void func_800155D4(void) {
    s32 tmp;

    Aud_CurrentChannel->unk_5B = *D_8008A708++;
    Aud_CurrentChannel->unk_5A = *D_8008A708++;

    if (Aud_CurrentChannel->unk_58 >= 0x8000 || !(Aud_CurrentChannel->flags & 4)) {
        tmp = (u16) (Aud_CurrentChannel->unk_5A << 8) - (Aud_CurrentChannel->unk_58 & 0x7FFF);
        Aud_CurrentChannel->unk_5C = tmp / Aud_CurrentChannel->unk_5B;
    }
}

void func_80015690(void) {
    s32 v1;
    u16 a1;

    a1 = Aud_CurrentChannel->unk_58 & 0x8000;

    Aud_CurrentChannel->unk_5B--;
    if (Aud_CurrentChannel->unk_5B != 0) {
        v1 = Aud_CurrentChannel->unk_58 & 0x7FFF;
        v1 += Aud_CurrentChannel->unk_5C;
        if (v1 < 0) {
            v1 = 0;
        } else if (v1 >= 0x8000) {
            v1 = 0x7F00;
        }
        Aud_CurrentChannel->unk_58 = v1;
    } else {
        Aud_CurrentChannel->unk_58 = Aud_CurrentChannel->unk_5A << 8;
    }

    Aud_CurrentChannel->unk_58 |= a1;
    aud_update_pan(Aud_CurrentChanId);
}

void func_8001573C(void) {
    Aud_CurrentChannel->coarseTune = (*D_8008A708++) << 8;
}

void func_8001576C(void) {
    Aud_CurrentChannel->fineTune = (s8) (*D_8008A708++) * 4;
}

void func_8001579C(void) {
    u8 v0;

    v0 = *D_8008A708++;
    if (v0 < 100) {
        Aud_CurrentChannel->unk_93 = v0;
    } else {
        Aud_CurrentChannel->unk_93 = 0;
        Aud_CurrentChannel->unk_9E = v0 - 100;
    }

    v0 = *D_8008A708++;
    if (v0 < 0x40) {
        if (v0 < 0x20) {
            Aud_CurrentChannel->unk_99 = 1;
            v0 *= 8;
        } else {
            Aud_CurrentChannel->unk_99 = 2;
            v0 *= 4;
        }
    } else if (v0 < 0x80) {
        Aud_CurrentChannel->unk_99 = 4;
        v0 *= 2;
    } else if (v0 == 0xFF) {
        Aud_CurrentChannel->unk_99 = 16;
    } else {
        Aud_CurrentChannel->unk_99 = 8;
    }
    Aud_CurrentChannel->unk_95 = v0;

    Aud_CurrentChannel->unk_9A = *(D_8008A708++) << 8;
    if (Aud_CurrentChannel->unk_9E != 0) {
        Aud_CurrentChannel->unk_A0 = Aud_CurrentChannel->unk_9A / Aud_CurrentChannel->unk_9E;
    }
}

void func_80015900(void) {
    Aud_CurrentChannel->unk_94 = Aud_CurrentChannel->unk_93;
    Aud_CurrentChannel->unk_9F = Aud_CurrentChannel->unk_9E;
    if (Aud_CurrentChannel->unk_9E == 0) {
        Aud_CurrentChannel->unk_9C = Aud_CurrentChannel->unk_9A;
    } else {
        Aud_CurrentChannel->unk_9C = 0;
    }
    Aud_CurrentChannel->unk_96 = 0;
    Aud_CurrentChannel->unk_98 = Aud_CurrentChannel->unk_96;
}

void func_80015958(void) {
    if (Aud_CurrentChannel->unk_94 != 0) {
        Aud_CurrentChannel->unk_94--;
        return;
    }

    if (Aud_CurrentChannel->unk_9F != 0) {
        Aud_CurrentChannel->unk_9F--;
        if (Aud_CurrentChannel->unk_9F != 0) {
            Aud_CurrentChannel->unk_9C += Aud_CurrentChannel->unk_A0;
        } else {
            Aud_CurrentChannel->unk_9C = Aud_CurrentChannel->unk_9A;
        }
    }

    func_800159D4();
}

void func_800159D4(void) {
    if (Aud_CurrentChannel->unk_94 == 0) {
        Aud_CurrentChannel->unk_96 += Aud_CurrentChannel->unk_95;
        if (Aud_CurrentChannel->unk_96 >= 0x100) {
            Aud_CurrentChannel->unk_96 &= 0xFF;
            Aud_CurrentChannel->flags |= 2;
            Aud_CurrentChannel->unk_98 += Aud_CurrentChannel->unk_99;
            Aud_CurrentChannel->unk_98 &= 0x3F;
            if (Aud_CurrentChannel->unk_9C < 0x8000) {
                Aud_CurrentChannel->vibrato = Aud_CurrentChannel->unk_9C >> 7;
                Aud_CurrentChannel->vibrato =
                    (D_8002A980[Aud_CurrentChannel->unk_98 & 0x1F] * Aud_CurrentChannel->vibrato) >> 8;
            } else {
                Aud_CurrentChannel->vibrato = (Aud_CurrentChannel->unk_9C >> 8) & 0x7F;
                Aud_CurrentChannel->vibrato += 2;
                Aud_CurrentChannel->vibrato =
                    (D_8002A980[Aud_CurrentChannel->unk_98 & 0x1F] * Aud_CurrentChannel->vibrato) >> 1;
            }
            if (Aud_CurrentChannel->unk_98 >= 0x20) {
                Aud_CurrentChannel->vibrato = -Aud_CurrentChannel->vibrato;
            }
        }
    }
}

void func_80015B04(void) {
    if ((Aud_CurrentChannel->unk_9E = *D_8008A708++) != 0) {
        Aud_CurrentChannel->unk_A0 = Aud_CurrentChannel->unk_9A / Aud_CurrentChannel->unk_9E;
    }
}

void func_80015B78(void) {
    Aud_CurrentChannel->pitchDriftSpeed = *D_8008A708++;
    Aud_CurrentChannel->pitchDriftMask = (*D_8008A708++) << 8;
    Aud_CurrentChannel->pitchDriftMask += *D_8008A708++;

    Aud_CurrentChannel->pitchDriftAccumulator = Aud_CurrentChannel->unk_8D = 0;
    if (Aud_CurrentChannel->pitchDriftSpeed == 0) {
        Aud_CurrentChannel->pitchDrift = 0;
    }
}

void func_80015C10(void) {
    Aud_CurrentChannel->pitchDriftAccumulator += Aud_CurrentChannel->pitchDriftSpeed;
    if (Aud_CurrentChannel->pitchDriftAccumulator >= 0x100) {
        Aud_CurrentChannel->pitchDriftAccumulator &= 0xFF;
        Aud_CurrentChannel->flags |= 2;

        Aud_CurrentChannel->pitchDrift = Aud_PitchDriftNoiseTable[Aud_CurrentChannel->unk_8D++];
        Aud_CurrentChannel->unk_8D &= 0x7F;
        Aud_CurrentChannel->pitchDrift += Aud_PitchDriftNoiseTable[Aud_CurrentChannel->unk_8D] << 8;
        Aud_CurrentChannel->pitchDrift &= Aud_CurrentChannel->pitchDriftMask;
    }
}

void func_80015CCC(void) {
    D_8008A708 += 3;
}

void func_80015CE4(void) {
    s32 a0;
    u16 a1;

    a1 = ((u32) (Aud_CurrentChannel->unk_7D * 0x10000) / Aud_CurrentChannel->tempo) + 1;
    a0 = Aud_CurrentChannel->unk_80 - Aud_CurrentChannel->pitch;
    Aud_CurrentChannel->unk_84 = a0 / a1;

    if (Aud_CurrentChannel->unk_84 == 0) {
        if (a0 < 0) {
            Aud_CurrentChannel->unk_84--;
        } else {
            Aud_CurrentChannel->unk_84++;
        }
    }
}

void func_80015D84(void) {
    s32 v1;

    if ((*D_8008A708++) == 0xE4) {
        if (Aud_CurrentChannel->unk_8A == 0) {
            Aud_CurrentChannel->unk_8C = 0;
            Aud_CurrentChannel->unk_7C = *D_8008A708++;
            Aud_CurrentChannel->unk_7D = *D_8008A708++;

            v1 = *D_8008A708++;
            v1 -= Aud_CurrentChannel->key;
            v1 <<= 8;
            Aud_CurrentChannel->unk_80 = Aud_CurrentChannel->pitch + v1;
            if (v1 && v1) {} // required to match
            func_80015CE4();
        } else {
            D_8008A708 += 3;
        }
        Aud_CurrentChannel->seqPtr = D_8008A708;
    }
}

void func_80015E64(void) {
    if (Aud_CurrentChannel->unk_8C == 0) {
        if (Aud_CurrentChannel->unk_7C != 0) {
            Aud_CurrentChannel->unk_7C--;
            return;
        }
        Aud_CurrentChannel->flags |= 2;

        Aud_CurrentChannel->unk_7D--;
        if (Aud_CurrentChannel->unk_7D != 0) {
            Aud_CurrentChannel->pitch += Aud_CurrentChannel->unk_84;
        } else {
            Aud_CurrentChannel->pitch = Aud_CurrentChannel->unk_80;
        }
    } else {
        func_8001609C();
    }
}

void func_80015EFC(void) {
    if (Aud_CurrentChannel->unk_8C == 0) {
        if (Aud_CurrentChannel->unk_7C == 0) {
            Aud_CurrentChannel->flags |= 2;
            Aud_CurrentChannel->pitch += Aud_CurrentChannel->unk_84;
        }
    } else {
        func_8001609C();
    }
}

void func_80015F64(void) {
    Aud_CurrentChannel->unk_8C = 0;
    Aud_CurrentChannel->unk_88 = *D_8008A708++;
    Aud_CurrentChannel->unk_89 = *D_8008A708++;
    Aud_CurrentChannel->unk_8A = (s8) (*D_8008A708++) << 8;
}

void func_80015FD0(void) {
    if (Aud_CurrentChannel->unk_8C == 0) {
        Aud_CurrentChannel->unk_7C = Aud_CurrentChannel->unk_88;
        Aud_CurrentChannel->unk_7D = Aud_CurrentChannel->unk_89;
        Aud_CurrentChannel->unk_80 = Aud_CurrentChannel->pitch;
        Aud_CurrentChannel->pitch -= Aud_CurrentChannel->unk_8A;
        func_80015CE4();
    } else {
        Aud_CurrentChannel->unk_80 = Aud_CurrentChannel->pitch;
        Aud_CurrentChannel->pitch = Aud_CurrentChannel->unk_84;
        Aud_CurrentChannel->unk_7D = 1;
    }
}

void func_80016060(void) {
    Aud_CurrentChannel->unk_8C = 1;
    Aud_CurrentChannel->unk_8A = *D_8008A708++;
}

void func_8001609C(void) {
    s32 a1;
    s32 v1;

    Aud_CurrentChannel->flags |= 2;
    v1 = Aud_CurrentChannel->unk_80 - Aud_CurrentChannel->pitch;
    a1 = v1;
    if (v1 < 0) {
        a1 = -v1;
    }
    a1 = (Aud_CurrentChannel->unk_8A * a1) >> 8;
    if (a1 == 0) {
        a1 = 1;
    }

    if (v1 < 0) {
        Aud_CurrentChannel->pitch -= a1;
        if (Aud_CurrentChannel->pitch < Aud_CurrentChannel->unk_80) {
            Aud_CurrentChannel->pitch = Aud_CurrentChannel->unk_80;
        }
    } else {
        Aud_CurrentChannel->pitch += a1;
        if (Aud_CurrentChannel->pitch > Aud_CurrentChannel->unk_80) {
            Aud_CurrentChannel->pitch = Aud_CurrentChannel->unk_80;
        }
    }

    if (Aud_CurrentChannel->pitch == Aud_CurrentChannel->unk_80) {
        Aud_CurrentChannel->unk_7D = 0;
    }
}

void func_80016170(void) {
    Aud_CurrentChannel->unk_5E = 0;
    Aud_CurrentChannel->unk_60 = D_8008A708;
    Aud_CurrentChannel->unk_40 = 0;
    Aud_CurrentChannel->pitchMod1 = Aud_CurrentChannel->unk_40;
}

void func_800161A8(void) {
    u8 v0;

    if (1) { // required to match
        v0 = *D_8008A708++;
        Aud_CurrentChannel->unk_5E++;
    }
    if (v0 == 0 || v0 != Aud_CurrentChannel->unk_5E) {
        Aud_CurrentChannel->unk_40 += (s8) *D_8008A708++;
        Aud_CurrentChannel->pitchMod1 += (s8) (*D_8008A708++) * 8;
        D_8008A708 = Aud_CurrentChannel->unk_60;
    } else {
        Aud_CurrentChannel->pitchMod1 = Aud_CurrentChannel->unk_40 = 0;
        D_8008A708 += 2;
    }
}

void func_80016268(void) {
    Aud_CurrentChannel->unk_64 = 0;
    Aud_CurrentChannel->unk_68 = D_8008A708;
    Aud_CurrentChannel->unk_42 = 0;
    Aud_CurrentChannel->pitchMod2 = Aud_CurrentChannel->unk_42;
}

void func_800162A0(void) {
    u8 v0;

    if (1) { // required to match
        v0 = *D_8008A708++;
        Aud_CurrentChannel->unk_64++;
    }
    if (v0 == 0 || v0 != Aud_CurrentChannel->unk_64) {
        Aud_CurrentChannel->unk_42 += (s8) *D_8008A708++;
        Aud_CurrentChannel->pitchMod2 += (s8) (*D_8008A708++) * 8;
        D_8008A708 = Aud_CurrentChannel->unk_68;
    } else {
        Aud_CurrentChannel->pitchMod2 = Aud_CurrentChannel->unk_42 = 0;
        D_8008A708 += 2;
    }
}

void func_80016360(void) {
    Aud_CurrentChannel->unk_6C = D_8008A708;
}

void func_80016378(void) {
    D_8008A708 = Aud_CurrentChannel->unk_6C;
}

void func_80016390(void) {
    Aud_CurrentChannel->unk_70 = 0;
    Aud_CurrentChannel->unk_74 = D_8008A708;
}

void func_800163B4(void) {
    switch (Aud_CurrentChannel->unk_70) {
        case 0:
            Aud_CurrentChannel->unk_70++;
            break;
        case 1:
            Aud_CurrentChannel->unk_70++;
            Aud_CurrentChannel->unk_78 = D_8008A708;
            D_8008A708 = Aud_CurrentChannel->unk_74;
            break;
        case 2:
            Aud_CurrentChannel->unk_70--;
            D_8008A708 = Aud_CurrentChannel->unk_78;
            break;
    }
}

void func_80016440(void) {
    s32 var_a0;
    u8 temp_a2;

    if ((Aud_CurrentChannel->command & 0x7FFF) < 0x100) {
        var_a0 = 0;
    } else {
        var_a0 = 1;
    }
    temp_a2 = *D_8008A708++;
    temp_a2 += D_8008A488[var_a0];
    if (temp_a2 > 0x7F) {
        temp_a2 = 0x7F;
    }

    if (temp_a2 != Aud_CurrentChannel->fxAmt) {
        Aud_CurrentChannel->fxAmt = temp_a2;
        alSynSetFXMix(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], temp_a2);
    }
}

void func_800164F8(void) {
    Aud_CurrentChannel->bankId = *D_8008A708++;
}

void func_80016524(void) {
    u8 tmp;

    tmp = (*D_8008A708++) & 1;
    if (tmp) {
        if (D_80055430 > (u8) Aud_CurrentChannel->command) {
            Aud_CurrentChannel->unk_D5 = 0;
        } else {
            Aud_CurrentChannel->unk_D5 = 1;
        }
    } else if (D_80055430 != (u8) Aud_CurrentChannel->command) {
        D_80055431 = TRUE;
    }
}

void func_800165AC(void) {
    if (Aud_CurrentChannel->isPlaying) {
        Aud_CurrentChannel->stopTimer = 1;
        alSynSetVol(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], 0, 5000);
    }

    Aud_CurrentChannel->unk_21 = *D_8008A708++;
    Aud_CurrentChannel->unk_22 = 1;
}

void func_80016648(void) {
    Aud_CurrentChannel->unk_21 = *D_8008A708++;
    Aud_CurrentChannel->unk_22 = *D_8008A708++;
    if (Aud_CurrentChannel->unk_22 == 0) {
        Aud_CurrentChannel->unk_24 = 0;
    } else {
        Aud_CurrentChannel->unk_24 = (Aud_CurrentChannel->unk_21 * Aud_CurrentChannel->unk_22) >> 7;
        if (Aud_CurrentChannel->unk_24 == 0) {
            Aud_CurrentChannel->unk_24 = 1;
        }
    }
    Aud_CurrentChannel->flags |= 1;

    if (Aud_CurrentChannel->envelopeTimer != 0) {
        func_80014C4C();
    }
    if (Aud_CurrentChannel->flags & 1) {
        aud_update_volume();
    }
}

void func_80016734(void) {
    u8 v0;

    v0 = *D_8008A708++;
    Aud_CurrentChannel->unk_B8[v0] = *D_8008A708++;
    Aud_CurrentChannel->unk_BB[v0] = *D_8008A708++;
}

#ifdef NON_EQUIVALENT
void func_80016790(void) {
    u8 v0;
    s32 a1;
    u8 a0;
    u16 a3;
    u16 a2;
    u8 v1;

    v0 = *D_8008A708++;
    D_8008A770++;
    a1 = D_8008A770 & 0x7F;
    a0 = 255 - (*D_8008A708++);

    a3 = Aud_PitchDriftNoiseTable[a1] << 8;
    a1 = (a1 + 1) & 0x7F;
    a3 += Aud_PitchDriftNoiseTable[a1];
    a3 += D_8008A770 >> 7;
    a3 += Aud_TickCount >> 1;

    if ((u8) a3 >= a0) {
        v1 = (a3 >> 8) & 3;
        if (v0 == D_8002B0BC && D_8002B0C0 == a0) {
            v1 = (v1 + 1) & 3;
        }

        D_8002B0BC = v0;
        D_8002B0C0 = v1;
        D_8008A718[D_8008A710].unk_00 = a3;
        D_8008A718[D_8008A710].unk_04 = &D_8002B07C[4 * v0 + v1];
        D_8008A710++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/158E0/func_80016790.s")
#endif

void func_800169B8(u8, u8, u8, s16);
void func_80016A38(u8);

void func_800168D0(void) {
    func_800169B8(0, *D_8008A708++, 0, 0);
}

void func_80016910(void) {
    u8 arg2, arg3;

    arg2 = *D_8008A708++;
    arg3 = *D_8008A708++;

    func_800169B8(1, arg2, arg3, 0);
}

void func_80016958(void) {
    func_80016A38(2);
}

void func_80016978(void) {
    func_80016A38(3);
}

void func_80016998(void) {
    func_80016A38(4);
}

void func_800169B8(u8 arg0, u8 arg1, u8 arg2, s16 arg3) {
    void *temp_v1;

    if (D_8008A728 < 8) {
        D_8008A730[D_8008A728].unk_02 = arg0;
        D_8008A730[D_8008A728].unk_00 = D_8002B0AC[arg1];
        D_8008A730[D_8008A728].unk_03 = arg2;
        D_8008A730[D_8008A728].unk_04 = arg3;
        D_8008A728++;
    }
}

void func_80016A38(u8 arg0) {
    u8 arg2, arg3;
    u8 arg4;

    arg2 = *D_8008A708++;
    arg3 = *D_8008A708++;
    arg4 = *D_8008A708++;
    func_800169B8(arg0, arg2, arg3, ((s8) (arg4 & 0xFF)) * 256);
}

void func_80016AA0(void) {
    if (Aud_CurrentChannel->isPlaying) {
        Aud_CurrentChannel->stopTimer = 1;
        alSynSetVol(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], 0, 5000);
    }
    Aud_CurrentChannel->priority = Aud_CurrentChannel->command = 0;
}
