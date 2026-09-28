#include "common.h"
#include "ld_addrs.h"

typedef struct AudioStruct1 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ u8 unk_04;
} AudioStruct1; // size = 6

typedef struct AudioStruct2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
} AudioStruct2; // size = 4

typedef struct AudioPlaybackRequest {
    /* 0x00 */ u8 numTracks;
    /* 0x01 */ u8 baseChannel;
    /* 0x02 */ u8 priority;
    /* 0x03 */ u8 bankId;
    /* 0x04 */ u8 delay;
    /* 0x08 */ u8 **tracks;
    /* 0x0C */ s16 unk_0C[3];
} AudioPlaybackRequest; // size = ?

typedef struct AudioStructA {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 *unk_04;
} AudioStructA; // size = 8

typedef struct AudioStructAA {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 **unk_04;
} AudioStructAA; // size = 8

typedef void (*AudioFunc1)(void);

/* .data */

s32 Aud_BankRomStart[3] = {
    (s32) audio_bank1_ROM_START,
    (s32) audio_bank2_ROM_START,
    (s32) audio_bank3_ROM_START,
};
s32 Aud_BankRomEnd[3] = {
    (s32) audio_bank1_ROM_END,
    (s32) audio_bank2_ROM_END,
    (s32) audio_bank3_ROM_END,
};
u8 *Aud_WaveTables[] = {
    (s32) audio_table1_ROM_START,
    (s32) audio_table2_ROM_START,
    (s32) audio_table3_ROM_START,
};
AudioStructAA *D_8002A474[] = {
    0x8002BAB8,
}; // TODO: make pointers
AudioStructA *D_8002A478[] = {
    0x8002C288,
    0x8002D324,
}; // TODO: make pointers

u8 D_8002A480 = 0;

s32 Aud_FxParams[] = {
    1,      // sections
    12000,  // length
            //
    0,      // input
    10200,  // output
    12800,  // fbcoef
    0,      // ffcoef
    0x7fff, // gain
    0,      // chorus rate
    0,      // chorus depth
    0,      // filter coef
};

u32 Aud_SongRomStart[] = {
    (u32) audio_seq1_ROM_START,  (u32) audio_seq2_ROM_START,  (u32) audio_seq3_ROM_START,  (u32) audio_seq4_ROM_START,
    (u32) audio_seq5_ROM_START,  (u32) audio_seq6_ROM_START,  (u32) audio_seq7_ROM_START,  (u32) audio_seq8_ROM_START,
    (u32) audio_seq9_ROM_START,  (u32) audio_seq10_ROM_START, (u32) audio_seq11_ROM_START, (u32) audio_seq12_ROM_START,
    (u32) audio_seq13_ROM_START, (u32) audio_seq14_ROM_START, (u32) audio_seq15_ROM_START, (u32) audio_seq16_ROM_START,
    (u32) audio_seq17_ROM_START, (u32) audio_seq18_ROM_START, (u32) audio_seq19_ROM_START, (u32) audio_seq20_ROM_START,
    (u32) audio_seq21_ROM_START, (u32) audio_seq22_ROM_START, (u32) audio_seq23_ROM_START, (u32) audio_seq24_ROM_START,
    (u32) audio_seq25_ROM_START, (u32) audio_seq26_ROM_START, (u32) audio_seq27_ROM_START, (u32) audio_seq28_ROM_START,
    (u32) audio_seq29_ROM_START, (u32) audio_seq30_ROM_START, (u32) audio_seq31_ROM_START, (u32) audio_seq32_ROM_START,
    (u32) audio_seq33_ROM_START, (u32) audio_seq34_ROM_START, (u32) audio_seq35_ROM_START, (u32) audio_seq36_ROM_START,
    (u32) audio_seq37_ROM_START, (u32) audio_seq38_ROM_START, (u32) audio_seq39_ROM_START, (u32) audio_seq40_ROM_START,
    (u32) audio_seq41_ROM_START, (u32) audio_seq42_ROM_START, (u32) audio_seq43_ROM_START, (u32) audio_seq44_ROM_START,
    (u32) audio_seq45_ROM_START, (u32) audio_seq46_ROM_START, (u32) audio_seq47_ROM_START, (u32) audio_seq48_ROM_START,
    (u32) audio_seq49_ROM_START, (u32) audio_seq50_ROM_START, (u32) audio_seq51_ROM_START,
};
u32 Aud_SongRomEnd[] = {
    (u32) audio_seq1_ROM_END,  (u32) audio_seq2_ROM_END,  (u32) audio_seq3_ROM_END,  (u32) audio_seq4_ROM_END,
    (u32) audio_seq5_ROM_END,  (u32) audio_seq6_ROM_END,  (u32) audio_seq7_ROM_END,  (u32) audio_seq8_ROM_END,
    (u32) audio_seq9_ROM_END,  (u32) audio_seq10_ROM_END, (u32) audio_seq11_ROM_END, (u32) audio_seq12_ROM_END,
    (u32) audio_seq13_ROM_END, (u32) audio_seq14_ROM_END, (u32) audio_seq15_ROM_END, (u32) audio_seq16_ROM_END,
    (u32) audio_seq17_ROM_END, (u32) audio_seq18_ROM_END, (u32) audio_seq19_ROM_END, (u32) audio_seq20_ROM_END,
    (u32) audio_seq21_ROM_END, (u32) audio_seq22_ROM_END, (u32) audio_seq23_ROM_END, (u32) audio_seq24_ROM_END,
    (u32) audio_seq25_ROM_END, (u32) audio_seq26_ROM_END, (u32) audio_seq27_ROM_END, (u32) audio_seq28_ROM_END,
    (u32) audio_seq29_ROM_END, (u32) audio_seq30_ROM_END, (u32) audio_seq31_ROM_END, (u32) audio_seq32_ROM_END,
    (u32) audio_seq33_ROM_END, (u32) audio_seq34_ROM_END, (u32) audio_seq35_ROM_END, (u32) audio_seq36_ROM_END,
    (u32) audio_seq37_ROM_END, (u32) audio_seq38_ROM_END, (u32) audio_seq39_ROM_END, (u32) audio_seq40_ROM_END,
    (u32) audio_seq41_ROM_END, (u32) audio_seq42_ROM_END, (u32) audio_seq43_ROM_END, (u32) audio_seq44_ROM_END,
    (u32) audio_seq45_ROM_END, (u32) audio_seq46_ROM_END, (u32) audio_seq47_ROM_END, (u32) audio_seq48_ROM_END,
    (u32) audio_seq49_ROM_END, (u32) audio_seq50_ROM_END, (u32) audio_seq51_ROM_END,
};

AudioStruct2 D_8002A644[3] = {
    { -0xC00, 0xC00 },
    { -0x100, 0x100 },
    { -0x7F, 0x7F },
};

void aud_cmd_1_stop_all(void);
void aud_cmd_2_stop_music(void);
void aud_cmd_3(void);
void aud_cmd_4(void);
void aud_cmd_5(void);
void aud_cmd_6(void);
void aud_cmd_7_to_10(void);
void aud_cmd_11(void);
void aud_cmd_12(void);
void aud_cmd_13(void);
void aud_cmd_14(void);

AudioFunc1 Aud_CommandHandlers[14] = {
    aud_cmd_1_stop_all, aud_cmd_2_stop_music, aud_cmd_3,       aud_cmd_4,  aud_cmd_5,  aud_cmd_6,  aud_cmd_7_to_10,
    aud_cmd_7_to_10,    aud_cmd_7_to_10,      aud_cmd_7_to_10, aud_cmd_11, aud_cmd_12, aud_cmd_13, aud_cmd_14,
};
u8 D_8002A688[] = { 1, 2, 4, 1, 0, 0, 0, 0 }; // size = 4 ? or split ?

AudioFunc1 D_8002A690[0x30] = {
    aud_seq_cmd_D0, aud_seq_cmd_D1, aud_seq_cmd_D2, aud_seq_cmd_D3, aud_seq_cmd_D4, aud_seq_cmd_D5, aud_seq_cmd_D6,
    aud_seq_cmd_D7, aud_seq_cmd_D8, aud_seq_cmd_D9, aud_seq_cmd_DA, func_80016AA0,  func_80015574,  func_8001557C,
    func_800155D4,  func_8001573C,  func_8001576C,  func_8001579C,  func_80015B04,  func_80015B78,  func_80015CCC,
    func_80015F64,  func_80016060,  func_80016170,  func_800161A8,  func_80016268,  func_800162A0,  func_80016360,
    func_80016378,  func_80016390,  func_800163B4,  func_80016440,  func_800164F8,  func_80016524,  func_800165AC,
    func_80016648,  func_80016AA0,  func_80016AA0,  func_80016AA0,  func_80016AA0,  func_80016734,  func_80016790,
    func_800168D0,  func_80016910,  func_80016958,  func_80016978,  func_80016998,  func_80016AA0,
};

s16 D_8002A750[] = { 10, 2, 4, 0 };

f32 Aud_NotePitchTable[] = {
    0.03125,
    0.0331082195,
    0.03507693857,
    0.03716271743,
    0.03937252983,
    0.04171371832,
    0.04419415444,
    0.04682206362,
    0.04960624874,
    0.05255596712,
    0.05568112433,
    0.05899209529,
    0.0625,
    0.06621643901,
    0.07015387714,
    0.07432543486,
    0.07874505967,
    0.08342743665,
    0.08838830888,
    0.09364412725,
    0.09921249747,
    0.1051119342,
    0.1113622487,
    0.1179841906,
    0.125,
    0.132432878,
    0.1403077543,
    0.1486508697,
    0.1574901193,
    0.1668548733,
    0.1767766178,
    0.1872882545,
    0.1984249949,
    0.2102238685,
    0.2227244973,
    0.2359683812,
    0.25,
    0.264865756,
    0.2806155086,
    0.2973017395,
    0.3149802387,
    0.3337097466,
    0.3535532355,
    0.374576509,
    0.3968499899,
    0.420447737,
    0.4454489946,
    0.4719367623,
    0.5,
    0.5297315121,
    0.5612310171,
    0.5946034789,
    0.6299604774,
    0.6674194932,
    0.7071064711,
    0.749153018,
    0.7936999798,
    0.840895474,
    0.8908979893,
    0.9438735247,
    1,
    1.059463024,
    1.122462034,
    1.189206958,
    1.259920955,
    1.334838986,
    1.414212942,
    1.498306036,
    1.58739996,
    1.681790948,
    1.781795979,
    1.887747049,
    2,
    2,
};

// 8002A880

/* .bss */

u8 D_80055430;
u8 D_80055431;
ALPlayer Aud_Player;
ALHeap Aud_Heap;
ALBankFile *Aud_Banks[3];
u8 Aud_HeapBuffer[0x35000];
u8 Aud_WarmupTickCounter;
u8 Aud_CommandQueueLocked;
u16 Aud_TickCount;
u8 Aud_CurrentChanId;
u8 D_8008A475;
s8 D_8008A476;
s8 D_8008A477;
u8 D_8008A478;
u8 D_8008A479;
u8 D_8008A47A;
u8 D_8008A47B;
u8 D_8008A47C;
u8 D_8008A47D;
u8 D_8008A47E;
u16 D_8008A480;
u8 D_8008A482;
s8 D_8008A483;
u8 D_8008A484;
u8 D_8008A485[1];
u16 D_8008A486[1];
u8 D_8008A488[2];
AudioPlaybackRequest Aud_PlaybackRequest;
AudioStruct1 D_8008A4A8[8];
u8 D_8008A4D8;
u8 D_8008A4D9;
u8 Aud_CommandQueueCount;
s32 Aud_CommandQueue[8];
u32 Aud_Command;
u16 D_8008A504;
u8 D_8008A506;
u16 *D_8008A508[16];
ALVoice Aud_Voices[NUM_AUDIO_CHANNELS];
u8 *D_8008A708;
ChanState *Aud_CurrentChannel;
u8 D_8008A710;
AudioStruct3 D_8008A718[2];
u8 D_8008A728;
AudioStruct9 D_8008A730[8];
ALFxRef D_8008A760;
char D_8008A768[0x18]; // unused
u8 Aud_BankBuffer[0x12000];
ChanState Aud_Channels[NUM_AUDIO_CHANNELS];
u8 Aud_SequenceBuffer[0x6000];

void aud_init_player(ALPlayer *);
ALMicroTime aud_voice_handler(void *);
void aud_create_voices(void);
void aud_play_request(u16 arg0, u8 arg1, u8 arg2);
void aud_process_requests(void);
void func_80011CC4(void);
void func_80011ECC(void);
void func_80012008(u32);
void func_80012314(s32 arg0, s32 arg1);
void aud_play_sound(s32);
u8 aud_steal_channel(u8 arg0);
void aud_play_song(void);
void func_800129BC(void);
void func_80012A98(u16 arg0, u8 arg1);
void func_80012B60(void);
void func_80012C50(u8, u16, u8);
void func_80012D54(s32);
void func_800131C4(s32);
void func_8001377C(void);
void aud_update_channels(void);
void aud_update_channel(void);
void aud_process_sequence(void);
void func_8001437C(void);
void func_80014498(void);
void func_8001454C(void);
void func_800145F8(void);
void aud_update_volume(void);
s32 func_80014A18(s32 arg0, u8 arg1, u8 arg2);
void func_80014A74(void);
void func_80014B00(void);
void func_80014B6C(void);
void func_80014BBC(void);
void func_80014C00(void);
void func_80014C4C(void);
void func_80014DB8(void);
void func_80015070(void);
void func_80015208(void);
void func_80015690(void);
void func_80015900(void);
void func_80015958(void);
void func_800159D4(void);
void func_80015C10(void);
void func_80015D84(void);
void func_80015E64(void);
void func_80015EFC(void);
void func_80015FD0(void);

#ifdef NON_MATCHING
void aud_init(void) {
    ALSynConfig synConfig;
    AudioConfig audioConfig;
    u32 i, j;
    s32 size;
    s32 offset;
    s32 romAddr;
    u8 *ptr;

    for (i = 0; i < 0x100000; i++) {}

    alHeapInit(&Aud_Heap, Aud_HeapBuffer, sizeof(Aud_HeapBuffer));

    offset = 0;
    for (j = 0; j < 3; j++) {
        size = Aud_BankRomEnd[j] - Aud_BankRomStart[j];
        romAddr = Aud_BankRomStart[j];
        ptr = Aud_Banks[j] = Aud_BankBuffer + offset;

        // clang-format off
        for (i = 0; i < size; i++) { ptr[i] = 0; }
        // clang-format on
        dma_read(romAddr, Aud_Banks[j], size);
        offset += size;
    }

    for (j = 0; j < 3; j++) {
        alBnkfNew(Aud_Banks[j], Aud_WaveTables[j]);
    }

    synConfig.maxVVoices = 16;
    synConfig.maxPVoices = 16;
    synConfig.maxUpdates = 160;
    synConfig.dmaproc = NULL;
    synConfig.outputRate = 0;
    synConfig.heap = &Aud_Heap;
    synConfig.fxType = AL_FX_CUSTOM;
    synConfig.params = Aud_FxParams;

    audioConfig.frequency = 44100;
    audioConfig.freqMultiplier = 1;
    audioConfig.maxCommands = 0x1000;

    func_800108F0(&synConfig, 80, &audioConfig);
    aud_init_player(&Aud_Player);

    for (i = 0; i < 0x100000; i++) {}
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio/aud_init.s")
#endif

void aud_init_player(ALPlayer *player) {
    Aud_WarmupTickCounter = 8;
    Aud_TickCount = Aud_CommandQueueCount = D_8008A475 = D_8008A478 = D_8008A4D9 = 0;
    D_8008A477 = D_8008A476 = 0;

    player->next = NULL;
    player->handler = aud_voice_handler;
    player->clientData = player;
    alSynAddPlayer(&alGlobals->drvr, player);
}

ALMicroTime aud_voice_handler(void *arg0) {
    if (Aud_WarmupTickCounter != 0) {
        if (Aud_WarmupTickCounter == 8) {
            aud_create_voices();
        }
        Aud_WarmupTickCounter--;
    } else {
        if (D_8008A504 != 0) {
            func_800129BC();
        }
        if (D_8008A710 != 0) {
            func_80011CC4();
        }
        if (D_8008A728 != 0) {
            func_80011ECC();
        }
        if (Aud_CommandQueueLocked == 0) {
            aud_process_requests();
        }

        aud_update_channels();
        Aud_TickCount++;

        if (D_80055431) {
            D_80055431 = FALSE;
            func_80012C50(1, D_80055430, 0);
        }
    }
    return 5000;
}

void aud_create_voices(void) {
    ALVoiceConfig voiceConfig;
    s32 i;
    ALVoice *v;
    ALBank *bank;
    ALInstrument *inst;
    ALSound *sound;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        voiceConfig.priority = 10;
        voiceConfig.fxBus = 0;
        voiceConfig.unityPitch = 0;
        alSynAllocVoice(&alGlobals->drvr, &Aud_Voices[i], &voiceConfig);

        Aud_CurrentChannel = &Aud_Channels[i];
        Aud_CurrentChannel->bankId = Aud_CurrentChannel->instrumentId = 0;

        bank = Aud_Banks[Aud_CurrentChannel->bankId]->bankArray[0];
        inst = bank->instArray[Aud_CurrentChannel->instrumentId];
        sound = inst->soundArray[0];
        Aud_CurrentChannel->wavetable = sound->wavetable;

        Aud_CurrentChannel->pitchRatio = 1.0f;
        Aud_CurrentChannel->volume = 0;
        Aud_CurrentChannel->volumeFrames = 0;
        Aud_CurrentChannel->isPlaying = TRUE;

        alSynStartVoiceParams(&alGlobals->drvr, &Aud_Voices[i], Aud_CurrentChannel->wavetable, 1.0f, 0, AL_PAN_CENTER,
                              AL_DEFAULT_FXMIX, 0);
    }

    aud_cmd_1_stop_all();
    D_8008A760 = alSynGetFXRef(&alGlobals->drvr, 0, 0);
}

void func_80011738(u16 commandId) {
    aud_play_request(commandId, 0, 0);
}

void func_80011764(u16 commandId) {
    aud_play_request(commandId, 0, 0);
}

void func_80011790(u16 commandId, u8 arg1) {
    aud_play_request(commandId, arg1, 0);
}

void func_800117C0(u16 commandId, u8 arg1) {
    aud_play_request(commandId, 0, arg1);
}

void aud_play_request(u16 commandId, u8 arg1, u8 arg2) {
    u32 v1;
    s32 i;
    s32 a3;

    if (commandId) {
        Aud_CommandQueueLocked = -1;

        if (!arg1 || arg1 > 127) {
            v1 = commandId;
        } else {
            v1 = commandId + (arg1 << 16);
        }

        if (arg2 != 0) {
            v1 |= arg2 << 24;
        }

        if (Aud_CommandQueueCount < 8) {
            if (Aud_CommandQueueCount != 0) {
                for (i = 0; i < Aud_CommandQueueCount; i++) {
                    if ((u32) (Aud_CommandQueue[i] & 0xFFFF) == commandId) {
                        Aud_CommandQueueLocked = 0;
                        return;
                    }
                }
            }

            Aud_CommandQueue[Aud_CommandQueueCount++] = v1;
        }

        Aud_CommandQueueLocked = 0;
    }
}

void func_800118C8(u16 arg0, u8 arg1, s16 arg2) {
    if (D_8008A4D8 < 8 && arg0 != 0 && arg1 < 3) {
        D_8008A4A8[D_8008A4D8].unk_00 = arg0;
        D_8008A4A8[D_8008A4D8].unk_02 = arg2;
        D_8008A4A8[D_8008A4D8].unk_04 = arg1;
        D_8008A4D8++;
        Aud_CommandQueueLocked = 0;
    }
}

s32 func_80011940(u8 arg0, u8 arg1) {
    s32 a0;
    s32 v1;

    v1 = Aud_CurrentChannel->unk_B8[arg1];
    if (v1 != 0) {
        if (arg1 == 0) {
            a0 = Aud_CurrentChannel->unk_BB[arg1] << 8;
        } else {
            a0 = Aud_CurrentChannel->unk_BB[arg1];
        }
        a0 += D_8008A4A8[arg0].unk_02 * v1 / 10;

        return a0;
    } else {
        return D_8008A4A8[arg0].unk_02;
    }
}

void func_800119D8(s32 arg0) {
    u8 s3;
    s32 i;
    AudioStruct2 *s0;
    s32 v0;
    s32 v1;

    s3 = D_8008A4A8[arg0].unk_04;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        Aud_CurrentChannel = &Aud_Channels[i];
        if ((Aud_CurrentChannel->command & 0x7FFF) == D_8008A4A8[arg0].unk_00) {
            s0 = &D_8002A644[s3];

            v0 = func_80011940(arg0, s3);
            v1 = v0;
            if (v0 < s0->unk_00) {
                v1 = s0->unk_00;
            } else if (v0 > s0->unk_02) {
                v1 = s0->unk_02;
            }

            if (Aud_CurrentChannel->unk_A2[s3] != (s16) v1) {
                Aud_CurrentChannel->unk_A2[s3] = v1;
            }
        }
    }
}

void func_80011AF4(u8 arg0, u8 arg1) {
    if (arg1 > 20) {
        arg1 = 20;
    }
    if (arg0 < 2) {
        D_8008A488[arg0] = arg1;
        return;
    } else {
        D_8008A488[0] = arg1;
        D_8008A488[1] = arg1;
    }
}

void func_80011B44(void) {
    D_8008A488[0] = D_8008A488[1] = 0;
}

s32 func_80011B58(void) {
    s32 var_v1;

    var_v1 = D_8008A47B + D_8008A47E;
    if (var_v1 == 0 && Aud_Channels[0].command != 0 && Aud_Channels[0].command < 0x100) {
        var_v1 = -1;
    }
    return var_v1;
}

void aud_process_requests(void) {
    s32 i;
    u16 commandId;

    i = 0;
    while (Aud_CommandQueueCount != 0) {
        Aud_Command = Aud_CommandQueue[i++];
        commandId = Aud_Command & 0xFFFF;
        Aud_CommandQueueCount--;

        if (commandId < 0x100) {
            if (commandId < 0x10) {
                Aud_CommandHandlers[commandId - 1]();
            } else {
                aud_play_song();
            }
        } else {
            if (commandId < 0x8000) {
                aud_play_sound(0);
            } else {
                func_8001377C();
            }
        }
    }

    i = 0;
    while (D_8008A4D8 != 0) {
        func_800119D8(i);
        i++;
        D_8008A4D8--;
    }
}

void func_80011CC4(void) {
    AudioStruct3Sub *sub;
    s16 val1, val2, val3;
    s16 temp1;
    s16 temp2;
    s16 temp3;
    u16 temp0;

    while (D_8008A710) {
        D_8008A710--;

        temp0 = D_8008A718[D_8008A710].unk_00;
        sub = D_8008A718[D_8008A710].unk_04;

        temp1 = temp0 >> 3;
        temp2 = temp1 >> 3;
        temp3 = temp2 >> 3;

        val1 = temp1 & 0x3FFF;
        val2 = temp2 & 0xFF;
        val3 = temp3 & 0x7F;

        if (sub->unk_02) {
            s16 v0 = sub->unk_02 << 8;
            while (val1 > v0) {
                val1 >>= 1;
            }
        } else {
            val1 = 0;
        }

        if (sub->unk_03) {
            while (val2 > sub->unk_03) {
                val2 >>= 1;
            }
        } else {
            val2 = 0;
        }

        if (sub->unk_04) {
            while (val3 > sub->unk_04) {
                val3 >>= 1;
            }
        } else {
            val3 = 0;
        }

        if (temp0 & 1) {
            val1 = -val1;
        }
        if (temp0 & 2) {
            val2 = -val2;
        }
        if (temp0 & 4) {
            val3 = -val3;
        }
        Aud_Command = sub->unk_00;
        Aud_PlaybackRequest.unk_0C[0] = val1;
        Aud_PlaybackRequest.unk_0C[1] = val2;
        Aud_PlaybackRequest.unk_0C[2] = val3;

        if (Aud_Command >= 0x100) {
            aud_play_sound(1);
        }
    }
}

void func_80011ECC(void) {
    u32 command;

    while (D_8008A728) {
        D_8008A728--;
        command = D_8008A730[D_8008A728].unk_00;
        switch (D_8008A730[D_8008A728].unk_02) {
            case 0:
                Aud_Command = command;
                if (command < 0x100) {
                    if (command < 0x10) {
                        Aud_CommandHandlers[command - 1]();
                    } else {
                        aud_play_song();
                    }
                } else {
                    aud_play_sound(0);
                }
                break;
            case 1:
                func_80012008(command);
                break;
            case 2:
                func_80012314(0, command);
                break;
            case 3:
                func_80012314(1, command);
                break;
            case 4:
                func_80012314(2, command);
                break;
        }
    }
}

void func_80012008(u32 arg0) {
    s32 i;

    if (D_8008A730[D_8008A728].unk_03 != 0) {
        for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
            Aud_CurrentChannel = &Aud_Channels[i];
            if ((Aud_CurrentChannel->command & 0x7FFF) == arg0) {
                Aud_CurrentChannel->unk_BE = 0xFF;
                Aud_CurrentChannel->unk_BF = 0x100 / D_8008A730[D_8008A728].unk_03;
                if (Aud_CurrentChannel->unk_BF == 0) {
                    Aud_CurrentChannel->unk_BF = 1;
                }
            }
        }
    } else {
        if (arg0 < 0x100) {
            if (arg0 == (Aud_Channels->command & 0x7FFF)) {
                aud_cmd_2_stop_music();
            }
        } else {
            for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
                if (arg0 == (Aud_Channels[i].command & 0x7FFF)) {
                    func_800131C4(i);
                }
            }
        }
    }
}

void func_80012314(s32 arg0, s32 arg1) {
    s32 v0;
    s32 a2;
    s32 i;
    s32 temp;

    v0 = D_8008A730[D_8008A728].unk_03;
    a2 = D_8008A730[D_8008A728].unk_04;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        Aud_CurrentChannel = &Aud_Channels[i];
        if ((Aud_CurrentChannel->command & 0x7FFF) == arg1) {
            if (Aud_CurrentChannel->unk_C6[arg0] != a2) {
                temp = (a2 - Aud_CurrentChannel->unk_C6[arg0]);
                temp /= v0;
                Aud_CurrentChannel->unk_D2[arg0] = v0;
                Aud_CurrentChannel->unk_C0[arg0] = a2;
                Aud_CurrentChannel->unk_CC[arg0] = temp;
            }
        }
    }
}

void aud_play_sound(s32 arg0) {
    u16 soundId;
    AudioStructA *v;
    AudioStructAA *vv;
    u8 channel;
    s32 i;

    soundId = Aud_Command & 0x7FFF;

    if (soundId >= 0x200) {
        if (soundId > 0x37A) {
            return;
        }
        v = D_8002A478[(soundId >> 8) - 2];

        Aud_PlaybackRequest.priority = v[(soundId & 0xFF)].unk_00;
        Aud_PlaybackRequest.priority &= 0x1F;

        channel = v[(soundId & 0xFF)].unk_01;
        Aud_PlaybackRequest.bankId = channel & 0xF;
        channel = channel >> 4;

        if (channel == 0) {
            for (i = 10; i < NUM_AUDIO_CHANNELS; i++) {
                if ((Aud_Channels[i].command & 0x7FFF) == soundId) {
                    channel = i;
                    break;
                }
            }
            if (channel == 0) {
                channel = aud_steal_channel(1);
            }
        }

        if (arg0) {
            if (Aud_Channels[channel].priority >= Aud_PlaybackRequest.priority) {
                return;
            }
        } else {
            if (Aud_Channels[channel].priority > Aud_PlaybackRequest.priority) {
                return;
            }
        }
        Aud_PlaybackRequest.baseChannel = channel;
        Aud_PlaybackRequest.numTracks = 1;
        Aud_PlaybackRequest.tracks = D_8008A508;
        D_8008A508[0] = v[(soundId & 0xFF)].unk_04;

    } else {
        if (soundId > 0x12E) {
            return;
        }

        vv = D_8002A474[(soundId >> 8) - 1];

        channel = vv[soundId & 0xFF].unk_00;
        Aud_PlaybackRequest.priority = channel & 0x1F;
        Aud_PlaybackRequest.numTracks = (channel >> 5) + 1;

        channel = vv[soundId & 0xFF].unk_01;
        Aud_PlaybackRequest.bankId = channel & 0xF;
        channel = channel >> 4;

        if (Aud_PlaybackRequest.numTracks == 2) {
            if (channel == 0) {
                for (i = 14; i >= 10; i -= 2) {
                    if ((Aud_Channels[i].command & 0x7FFF) == soundId) {
                        channel = i;
                        break;
                    }
                }
                if (channel == 0) {
                    channel = aud_steal_channel(2);
                }
            }

            if (Aud_Channels[channel].priority > Aud_PlaybackRequest.priority ||
                Aud_Channels[channel + 1].priority > Aud_PlaybackRequest.priority) {
                return;
            }
        }

        Aud_PlaybackRequest.baseChannel = channel;
        Aud_PlaybackRequest.tracks = vv[soundId & 0xFF].unk_04;
    }

    Aud_PlaybackRequest.delay = 6;
    func_80012D54(arg0);
}

void func_80012720(void) {
}

u8 aud_steal_channel(u8 mode) {
    u8 bestIndex;
    u8 i;
    u8 bestPriority;
    u8 a3;

    bestIndex = 14;

    if (mode == 1) {
        bestIndex = 10;
        bestPriority = Aud_Channels[bestIndex].priority;
        for (i = 11; i < NUM_AUDIO_CHANNELS; i++) {
            if (bestPriority >= Aud_Channels[i].priority) {
                bestIndex = i;
                bestPriority = Aud_Channels[i].priority;
            }
        }
    } else {
        bestPriority = 255;
        for (i = 14; i >= 10; i -= 2) {
            a3 = i;
            if (Aud_Channels[i].priority < Aud_Channels[i + 1].priority) {
                a3++;
            }

            if (bestPriority >= Aud_Channels[a3].priority) {
                bestIndex = i;
                bestPriority = Aud_Channels[a3].priority;
            }
        }
    }

    return bestIndex;
}

void aud_play_song(void) {
    u16 command;
    u8 tmp;

    command = Aud_Command & 0x7FFF;

    if (D_8002B0F8[command - 16].unk_02 == 0 || D_8002B0F8[command - 16].unk_02 != D_8002A480) {
        if (D_8008A47E) {
            aud_cmd_1_stop_all();
        } else {
            aud_cmd_2_stop_music();
        }
    }

    if (command < 0xC0) {
        if (command <= 66) {
            tmp = D_8002B0F8[command - 16].unk_02;
            if (tmp != 0) {
                if (tmp != D_8002A480) {
                    D_8008A504 = command;
                    D_8008A506 = 4;
                } else {
                    func_80012C50(0, command, 5);
                }
            } else {
                if (command != D_8008A4D9) {
                    D_8008A504 = command;
                    D_8008A506 = 4;
                } else {
                    func_80012A98(command, 6);
                }
            }
        }
    } else if (command < 0xC1) {
        command -= 0xC0;
        Aud_PlaybackRequest.numTracks = D_8002B1C0[command].numTracks;
        Aud_PlaybackRequest.bankId = D_8002B1C0[command].bankId;
        Aud_PlaybackRequest.tracks = D_8002B1C0[command].tracks;
        Aud_PlaybackRequest.baseChannel = 0;
        Aud_PlaybackRequest.priority = 30;
        Aud_PlaybackRequest.delay = 6;

        func_80012D54(0);
    }
}

void func_800129BC(void) {
    u16 songId;

    if (--D_8008A506) {
        return;
    }

    if (D_80044251) {
        D_8008A506 = 1;
        return;
    }

    songId = D_8008A504 - 16;
    D_8008A4D9 = D_8008A504;
    D_8002A480 = D_8002B0F8[songId].unk_02;

    if (D_8002A480 != 0) {
        func_80012B60();
    } else {
        func_8000DF24(Aud_SongRomStart[songId], Aud_SequenceBuffer, Aud_SongRomEnd[songId] - Aud_SongRomStart[songId]);
        func_80012A98(D_8008A504, 5);
        D_8008A504 = 0;
    }
}

void func_80012A98(u16 command, u8 arg1) {
    u16 songId;
    s32 i;
    u16 *tmp2;

    songId = command - 16;
    tmp2 = Aud_SequenceBuffer;

    Aud_PlaybackRequest.numTracks = D_8002B0F8[songId].numTracks;
    Aud_PlaybackRequest.bankId = D_8002B0F8[songId].bankId;
    Aud_PlaybackRequest.tracks = D_8008A508;

    for (i = 0; i < Aud_PlaybackRequest.numTracks; i++) {
        D_8008A508[i] = (u16 *) ((u32) (Aud_SequenceBuffer) + tmp2[i]);
    }

    Aud_Command = command;
    Aud_PlaybackRequest.baseChannel = 0;
    Aud_PlaybackRequest.priority = 30;
    Aud_PlaybackRequest.delay = arg1;
    func_80012D54(0);
}

void func_80012B60(void) {
    s32 i;
    u16 songId;
    u8 *tmp;
    s32 v2;
    u8 *ptr;
    s32 size;

    v2 = D_8002A480 - 1;
    tmp = D_8002B0D8[v2];
    ptr = Aud_SequenceBuffer;
    for (i = 0; i < D_8002B0D0[v2]; i++, ptr += 0x1800) {
        songId = tmp[i] - 16;
        size = Aud_SongRomEnd[songId] - Aud_SongRomStart[songId];
        func_8000DF24(Aud_SongRomStart[songId], ptr, size);
    }

    func_80012C50(0, D_8008A504, 5);
    D_8008A504 = 0;
}

void func_80012C50(u8 arg0, u16 command, u8 arg2) {
    u16 songId;
    u16 *a0;
    s32 i;

    D_80055430 = command;
    if (arg0 || Aud_Channels->command == 0) {
        songId = command - 16;
        Aud_PlaybackRequest.numTracks = D_8002B0F8[songId].numTracks;
        Aud_PlaybackRequest.bankId = D_8002B0F8[songId].bankId;
        Aud_PlaybackRequest.tracks = D_8008A508;

        a0 = Aud_SequenceBuffer + D_8002B0F8[songId].unk_03 * 0x1800;
        for (i = 0; i < Aud_PlaybackRequest.numTracks; i++) {
            D_8008A508[i] = (u32) a0 + a0[i];
        }
        Aud_Command = command;
        Aud_PlaybackRequest.baseChannel = 0;
        Aud_PlaybackRequest.priority = 30;
        Aud_PlaybackRequest.delay = arg2;
        func_80012D54(0);
    }
}

#ifdef NON_EQUIVALENT
void func_80012D54(s32 arg0) {
    s32 v0;
    s32 i;
    s32 j;
    ChanState *chan;
    u8 **tracks;

    if (arg0 == 0) {
        Aud_PlaybackRequest.unk_0C[0] = 0;
        Aud_PlaybackRequest.unk_0C[1] = 0;
        Aud_PlaybackRequest.unk_0C[2] = 0;
    }

    v0 = ((Aud_Command & 0x7FFF) < 0x100) ? 0 : 1;
    tracks = Aud_PlaybackRequest.tracks;

    for (i = 0; i < Aud_PlaybackRequest.numTracks; i++) {
        chan = Aud_Channels + Aud_PlaybackRequest.baseChannel + i;

        if (chan->fxAmt != D_8008A488[v0]) {
            chan->fxAmt = D_8008A488[v0];
            alSynSetFXMix(&alGlobals->drvr, &Aud_Voices[Aud_PlaybackRequest.baseChannel + i], chan->fxAmt);
        }

        if (v0 != 0 && chan->isPlaying) {
            alSynSetVol(&alGlobals->drvr, &Aud_Voices[Aud_PlaybackRequest.baseChannel + i], 0, 5000);
            chan->stopTimer = 2;
        }

        chan->startTimer = Aud_PlaybackRequest.delay;
        chan->command = Aud_Command;
        chan->priority = Aud_PlaybackRequest.priority;
        chan->bankId = Aud_PlaybackRequest.bankId;

        chan->seqPtr = tracks[i];

        chan->tempo = 0x8000;
        chan->unk_1A = 0x80;

        chan->unk_21 = chan->unk_22 = 1;

        chan->pitchDrift = 0;

        chan->unk_9E = 0;
        chan->unk_1D = 0;
        chan->unk_47 = chan->unk_5B = 0;
        chan->unk_58 = 0;
        chan->coarseTune = chan->fineTune = 0;
        chan->pitchMod1 = chan->pitchMod2 = 0;
        chan->unk_40 = chan->unk_42 = 0;
        chan->unk_7D = chan->unk_8A = 0;
        chan->unk_9A = chan->pitchDriftSpeed = 0;

        for (j = 0; j < 3; j++) {
            chan->unk_A2[j] = chan->unk_A8[j] = Aud_PlaybackRequest.unk_0C[j];
        }

        for (j = 0; j < 3; j++) {
            chan->unk_B8[j] = 0;
            chan->unk_BB[j] = 0;
        }
        chan->unk_BE = 0;

        for (j = 0; j < 3; j++) {
            chan->unk_C6[j] = 0;
            chan->unk_D2[j] = 0;
        }
        chan->unk_D5 = 0;
    }

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == (Aud_Command & 0x7FFF)) {
            D_8008A486[i] = D_8008A485[i] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio/func_80012D54.s")
#endif

void aud_cmd_1_stop_all(void) {
    s32 i;

    D_8008A710 = 0;
    D_8008A728 = 0;
    D_8008A4D8 = 0;
    D_8008A47E = 0;
    D_8008A488[0] = D_8008A488[1] = 0;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        Aud_Channels[i].command = 0x10;
    }

    aud_cmd_2_stop_music();

    for (i = 0; i < 1; i++) {
        D_8008A486[i] = D_8008A485[i] = 0;
    }
}

void aud_cmd_2_stop_music(void) {
    s32 i;
    u32 v0;

    D_80055431 = FALSE;
    D_8008A504 = 0;
    D_8008A506 = 0;

    D_8008A47B = D_8008A482 = D_8008A480 = 0;
    D_8008A483 = D_8008A484 = 0;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        v0 = Aud_Channels[i].command & 0x7FFF;
        if (v0 >= 0x10 && v0 < 0x100) {
            func_800131C4(i);
        }
    }
}

void func_800131C4(s32 channel) {
    Aud_CurrentChannel = &Aud_Channels[channel];
    Aud_CurrentChannel->command = 0;
    Aud_CurrentChannel->priority = 0;
    if (Aud_CurrentChannel->isPlaying) {
        Aud_CurrentChannel->stopTimer = 2;
        Aud_CurrentChannel->volume = 0;
        Aud_CurrentChannel->volumeFrames = 0;
        alSynSetVol(&alGlobals->drvr, &Aud_Voices[channel], 0, 5000);
    }
}

void aud_cmd_3(void) {
    s32 i;
    u32 command;

    if (D_8008A475 == 0) {
        D_8008A475++;

        for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
            Aud_CurrentChannel = &Aud_Channels[i];
            command = Aud_CurrentChannel->command & 0x7FFF;
            if (command >= 0x10 && command < 0x100 && Aud_CurrentChannel->isPlaying) {
                Aud_CurrentChannel->stopTimer = 2;
                alSynSetVol(&alGlobals->drvr, &Aud_Voices[i], 0, 5000);
            }
        }
    }
}

void aud_cmd_4(void) {
    s32 i;
    u32 command;

    if (D_8008A475 != 0) {
        D_8008A475 = 0;

        for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
            Aud_CurrentChannel = &Aud_Channels[i];
            command = Aud_CurrentChannel->command & 0x7FFF;
            if (command >= 0x10 && command < 0x100) {
                Aud_CurrentChannel->flags |= 1;
                if (Aud_CurrentChannel->isPlaying) {
                    Aud_CurrentChannel->stopTimer = 0;
                    alSynStopVoice(&alGlobals->drvr, &Aud_Voices[i]);
                }

                Aud_CurrentChannel->isPlaying = TRUE;
                alSynStartVoice(&alGlobals->drvr, &Aud_Voices[i], Aud_CurrentChannel->wavetable);
            }
        }
    }
}

void aud_cmd_5(void) {
    s32 i;

    if (D_8008A478 != 0) {
        D_8008A478 = 0;

        for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
            Aud_CurrentChannel = &Aud_Channels[i];
            if (Aud_CurrentChannel->command != 0) {
                aud_update_pan(i);
            }
        }
    }
}

void aud_cmd_6(void) {
    s32 i;

    if (D_8008A478 == 0) {
        D_8008A478 = 1;

        for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
            Aud_CurrentChannel = &Aud_Channels[i];
            if (Aud_CurrentChannel->command != 0) {
                aud_update_pan(i);
            }
        }
    }
}

void aud_update_pan(u8 channel) {
    s16 pan;

    Aud_CurrentChannel->flags |= 1;

    if (D_8008A478) {
        pan = AL_PAN_CENTER;
    } else {
        pan = ((Aud_CurrentChannel->unk_58 >> 8) & 0x7F);
        pan += Aud_CurrentChannel->unk_A8[2];
        if (Aud_CurrentChannel->unk_C6[2] != 0) {
            pan += Aud_CurrentChannel->unk_C6[2] / 256;
        }

        if (pan < AL_PAN_LEFT) {
            pan = AL_PAN_LEFT;
        } else if (pan > AL_PAN_RIGHT) {
            pan = AL_PAN_RIGHT;
        }
    }

    alSynSetPan(&alGlobals->drvr, &Aud_Voices[channel], pan);
}

void aud_cmd_7_to_10(void) {
    if (Aud_Command != 10) {
        if (D_8008A47B == 0) {
            D_8008A47B = 255;
        }
        D_8008A47A = D_8008A479 = D_8002A688[Aud_Command - 7];
    } else {
        if (D_8008A47E == 0) {
            D_8008A47E = 255;
        }
        D_8008A47D = D_8008A47C = D_8002A688[Aud_Command - 7];
    }
}

void aud_cmd_11(void) {
    if (D_8008A480 < 0x100) {
        D_8008A482 = 0x10;
    }
}

void aud_cmd_12(void) {
    D_8008A482 = D_8008A480 = 0;
}

void aud_cmd_13(void) {
    if (D_8008A484 == 0) {
        D_8008A483 = -1;
    }
}

void aud_cmd_14(void) {
    if (D_8008A484 != 0) {
        D_8008A483 = 1;
    }
}

void func_8001377C(void) {
    s32 i, j;

    Aud_Command &= 0x7FFF;

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == Aud_Command) {
            return;
        }
    }

    for (i = 0; i < 1; i++) {
        if (D_8008A486[i] == 0) {
            D_8008A486[i] = Aud_Command;
            D_8008A485[i] = 255;
            break;
        }
    }
}

void func_80013800(u16 arg0) {
    s32 i;

    for (i = 0; i < NUM_AUDIO_CHANNELS; i++) {
        if (D_8008A486[arg0] == (Aud_Channels[i].command & 0x7FFF)) {
            func_800131C4(i);
        }
    }

    D_8008A486[arg0] = D_8008A485[arg0] = 0;
}

void aud_update_channels(void) {
    s32 i;

    if (D_8008A47E != 0 && D_8008A475 == 0 && (Aud_TickCount % 4) == 0) {
        if (--D_8008A47D == 0) {
            D_8008A47D = D_8008A47C;
            D_8008A47E -= 4;
            if (D_8008A47E < 0x10) {
                aud_cmd_1_stop_all();
            }
        }
    }

    if (D_8008A47B != 0 && D_8008A475 == 0 && (Aud_TickCount % 4) == 0) {
        if (--D_8008A47A == 0) {
            D_8008A47A = D_8008A479;
            D_8008A47B -= 4;
            if (D_8008A47B < 0x10) {
                aud_cmd_2_stop_music();
            }
        }
    }

    if (D_8008A475 == 0 && !(Aud_TickCount & 1)) {
        for (i = 0; i < 1; i++) {
            if (D_8008A486[i] != 0) {
                D_8008A485[i] -= 4;
                if (D_8008A485[i] < 16) {
                    func_80013800(i);
                }
            }
        }
    }

    if (D_8008A482 != 0 && D_8008A475 == 0 && (Aud_TickCount % 8) == 0) {
        D_8008A482--;
        D_8008A480++;
    }

    if (D_8008A483 != 0 && (Aud_TickCount % 2) == 0) {
        D_8008A484 += D_8008A483;
        if (D_8008A484 == 0xA0 || D_8008A484 == 0) {
            D_8008A483 = 0;
        }
    }

    for (Aud_CurrentChanId = 0; Aud_CurrentChanId < NUM_AUDIO_CHANNELS; Aud_CurrentChanId++) {
        Aud_CurrentChannel = &Aud_Channels[Aud_CurrentChanId];

        if (Aud_CurrentChannel->stopTimer != 0) {
            Aud_CurrentChannel->stopTimer--;
            if (Aud_CurrentChannel->stopTimer == 0 && Aud_CurrentChannel->isPlaying) {
                Aud_CurrentChannel->isPlaying = FALSE;
                alSynStopVoice(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId]);
            }
        }

        if (Aud_CurrentChannel->command != 0) {
            if (Aud_CurrentChannel->startTimer != 0) {
                Aud_CurrentChannel->startTimer--;
            } else if ((Aud_CurrentChannel->command & 0x7FFF) < 0x100) {
                // music
                if (D_8008A475 == 0) {
                    Aud_CurrentChannel->unk_1A += D_8008A480;
                    aud_update_channel();
                }
            } else {
                // sound
                aud_update_channel();
            }
        }
    }
}

void aud_update_channel(void) {
    s32 i;
    s16 a;

    if ((Aud_TickCount % 4) == 0) {
        for (i = 0; i < 3; i++) {
            if (Aud_CurrentChannel->unk_A2[i] != Aud_CurrentChannel->unk_A8[i]) {
                if (Aud_CurrentChannel->unk_A8[i] < Aud_CurrentChannel->unk_A2[i]) {
                    Aud_CurrentChannel->unk_A8[i] += D_8002A750[i];
                    if (Aud_CurrentChannel->unk_A8[i] > Aud_CurrentChannel->unk_A2[i]) {
                        Aud_CurrentChannel->unk_A8[i] = Aud_CurrentChannel->unk_A2[i];
                    }
                } else {
                    Aud_CurrentChannel->unk_A8[i] -= D_8002A750[i];
                    if (Aud_CurrentChannel->unk_A8[i] < Aud_CurrentChannel->unk_A2[i]) {
                        Aud_CurrentChannel->unk_A8[i] = Aud_CurrentChannel->unk_A2[i];
                    }
                }

                switch (i) {
                    case 0:
                        Aud_CurrentChannel->flags |= 2;
                        break;
                    case 1:
                        Aud_CurrentChannel->flags |= 1;
                        break;
                    case 2:
                        aud_update_pan(Aud_CurrentChanId);
                        break;
                }
            }
        }
    }

    Aud_CurrentChannel->unk_1A += Aud_CurrentChannel->tempo >> 8;
    if (Aud_CurrentChannel->unk_1A >= 0x100) {
        Aud_CurrentChannel->unk_1A &= 0xFF;

        if (Aud_CurrentChannel->unk_BE != 0) {
            a = Aud_CurrentChannel->unk_BE;
            a -= Aud_CurrentChannel->unk_BF;
            if (a < 0x10) {
                func_80016AA0();
                return;
            }

            Aud_CurrentChannel->unk_BE = a;
            Aud_CurrentChannel->flags |= 1;
        }

        for (i = 0; i < 3; i++) {
            if (Aud_CurrentChannel->unk_D2[i] != 0) {
                Aud_CurrentChannel->unk_D2[i]--;

                if (Aud_CurrentChannel->unk_D2[i] != 0) {
                    Aud_CurrentChannel->unk_C6[i] += Aud_CurrentChannel->unk_CC[i];
                } else {
                    Aud_CurrentChannel->unk_C6[i] = Aud_CurrentChannel->unk_C0[i];
                }

                switch (i) {
                    case 0:
                        Aud_CurrentChannel->flags |= 2;
                        break;
                    case 1:
                        Aud_CurrentChannel->flags |= 1;
                        break;
                    case 2:
                        aud_update_pan(Aud_CurrentChanId);
                        break;
                }
            }
        }

        Aud_CurrentChannel->unk_21--;
        if (Aud_CurrentChannel->unk_21 == 0) {
            aud_process_sequence();
            func_80015D84();
        } else {
            func_8001437C();
        }

        if (Aud_CurrentChannel->unk_1D != 0) {
            func_80014DB8();
        }
        if (Aud_CurrentChannel->unk_47 != 0) {
            func_80015208();
        }
        if (Aud_CurrentChannel->unk_5B != 0) {
            func_80015690();
        }
    } else {
        func_8001454C();
    }

    if (Aud_CurrentChannel->pitchDriftSpeed != 0) {
        func_80015C10();
    }
}

void aud_process_sequence(void) {
    u8 s0;
    u8 sp26;

    sp26 = 0;
    if (Aud_CurrentChannel->unk_22 == 0) {
        sp26 = 1;
    } else if (Aud_CurrentChannel->isPlaying) {
        Aud_CurrentChannel->stopTimer = 0;
        Aud_CurrentChannel->isPlaying = FALSE;
        alSynStopVoice(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId]);
    }

    D_8008A708 = Aud_CurrentChannel->seqPtr;

    while ((s0 = *D_8008A708++) >= 0xD0) {
        D_8002A690[s0 - 0xD0]();
        switch (s0) {
            case 0xF2:
            case 0xF3:
                Aud_CurrentChannel->seqPtr = D_8008A708;
                return;
            case 0xFF:
                return;
        }
    }

    Aud_CurrentChannel->unk_84 = Aud_CurrentChannel->pitch;

    if (s0 < 0x68) {
        Aud_CurrentChannel->key = s0;
    } else {
        Aud_CurrentChannel->key = s0 - 0x68;
    }

    if (Aud_CurrentChannel->key >= 0x48) {
        if (Aud_CurrentChannel->key == 0x67) {
            Aud_CurrentChannel->key = *D_8008A708++;
        }
        Aud_CurrentChannel->flags |= 4;
        func_80015070();
        Aud_CurrentChannel->key = 60;
    } else {
        Aud_CurrentChannel->flags &= 0xFB;
    }

    Aud_CurrentChannel->pitch = Aud_CurrentChannel->key << 8;
    Aud_CurrentChannel->pitch += Aud_CurrentChannel->keyShift;
    Aud_CurrentChannel->pitch += Aud_CurrentChannel->coarseTune;
    Aud_CurrentChannel->pitch += Aud_CurrentChannel->fineTune;
    Aud_CurrentChannel->pitch += Aud_CurrentChannel->pitchMod1;
    Aud_CurrentChannel->pitch += Aud_CurrentChannel->pitchMod2;

    if (s0 < 0x68) {
        Aud_CurrentChannel->unk_20 = *D_8008A708++;
    }
    Aud_CurrentChannel->unk_21 = Aud_CurrentChannel->unk_20;

    s0 = *D_8008A708++;
    if (s0 < 0x80) {
        Aud_CurrentChannel->unk_23 = s0;
        s0 = *D_8008A708++;
    }
    Aud_CurrentChannel->unk_22 = Aud_CurrentChannel->unk_23;

    if (Aud_CurrentChannel->unk_22 == 0) {
        Aud_CurrentChannel->unk_24 = 0;
    } else {
        Aud_CurrentChannel->unk_24 = (Aud_CurrentChannel->unk_21 * Aud_CurrentChannel->unk_22) >> 7;
        if (Aud_CurrentChannel->unk_24 == 0) {
            Aud_CurrentChannel->unk_24 = 1;
        }
    }

    Aud_CurrentChannel->velocity = s0 & 0x7F;
    Aud_CurrentChannel->seqPtr = D_8008A708;

    if (Aud_CurrentChannel->unk_8A == 0) {
        Aud_CurrentChannel->unk_7D = 0;
    } else {
        func_80015FD0();
    }

    Aud_CurrentChannel->vibrato = 0;

    if (Aud_CurrentChannel->unk_9A != 0) {
        func_80015900();
    }

    if (Aud_CurrentChannel->unk_D5 == 0) {
        func_800145F8();
        if (!sp26) {
            Aud_CurrentChannel->volumeFrames = 0xFFFF;
            func_80014A74();
            Aud_CurrentChannel->isPlaying = TRUE;
            alSynStartVoice(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], Aud_CurrentChannel->wavetable);
        } else {
            Aud_CurrentChannel->flags |= 1;

            if (Aud_CurrentChannel->envelopeTimer != 0) {
                func_80014C4C();
            }
            if (Aud_CurrentChannel->flags & 1) {
                aud_update_volume();
            }
        }
    }
}

void func_8001437C(void) {
    if (Aud_CurrentChannel->unk_7D != 0) {
        func_80015E64();
    }
    if (Aud_CurrentChannel->unk_9A != 0) {
        func_80015958();
    }
    if (Aud_CurrentChannel->flags & 2) {
        func_800145F8();
    }

    if (Aud_CurrentChannel->unk_22 != 0 && Aud_CurrentChannel->unk_21 == 1) {
        func_80014C00();
        return;
    }

    if (Aud_CurrentChannel->unk_24 != 0) {
        Aud_CurrentChannel->unk_24--;
        if (Aud_CurrentChannel->unk_24 == 0) {
            func_80014BBC();
            return;
        }
    }
    if (Aud_CurrentChannel->envelopeTimer != 0) {
        func_80014C4C();
    }
    if (Aud_CurrentChannel->flags & 1) {
        aud_update_volume();
    } else {
        func_80014498();
    }
}

void func_80014498(void) {
    s32 i;

    if (D_8008A47E != 0) {
        aud_update_volume();
    } else if ((Aud_CurrentChannel->command & 0x7FFF) < 0x100 && (D_8008A47B != 0 || D_8008A483 != 0)) {
        aud_update_volume();
    } else {
        for (i = 0; i < 1; i++) {
            if (D_8008A486[i] == (Aud_CurrentChannel->command & 0x7FFF)) {
                aud_update_volume();
                break;
            }
        }
    }
}

void func_8001454C(void) {
    if (Aud_CurrentChannel->unk_7D != 0) {
        func_80015EFC();
    }
    if (Aud_CurrentChannel->unk_9A != 0) {
        func_800159D4();
    }
    if (Aud_CurrentChannel->flags & 2) {
        func_800145F8();
    }
    if (Aud_CurrentChannel->envelopeTimer != 0) {
        func_80014C4C();
    }
    if (Aud_CurrentChannel->flags & 1) {
        aud_update_volume();
    }
}

void func_800145F8(void) {
    u8 cents;
    s32 note;
    f32 pitchRatio;

    Aud_CurrentChannel->flags &= 0xfd;
    note = Aud_CurrentChannel->unk_A8[0] + Aud_CurrentChannel->pitch + Aud_CurrentChannel->pitchDrift +
           Aud_CurrentChannel->vibrato;
    note += Aud_CurrentChannel->unk_C6[0];
    if (note < 0) {
        note = 0;
    } else if (note > 0x4800) {
        note = 0x4800;
    }

    cents = note & 0xFF;
    note >>= 8;
    pitchRatio = Aud_NotePitchTable[note + 1] - Aud_NotePitchTable[note];
    pitchRatio = cents * pitchRatio / 256;
    pitchRatio += Aud_NotePitchTable[note];
    if (pitchRatio != Aud_CurrentChannel->pitchRatio) {
        Aud_CurrentChannel->pitchRatio = pitchRatio;
        alSynSetPitch(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], pitchRatio);
    }
}

void aud_update_volume(void) {
    s32 volume;
    s32 volumeFrames;
    s16 v1;
    s32 i;

    Aud_CurrentChannel->flags &= 0xFE;

    volume = (Aud_CurrentChannel->velocity + Aud_CurrentChannel->unk_40 + Aud_CurrentChannel->unk_42);
    volume *= Aud_CurrentChannel->unk_3A;

    if (volume > 0x7FFFFF) {
        volume = 0x7FFF;
    } else if (volume < 0) {
        volume = 0;
    } else {
        volume = volume >> 8;
    }

    volumeFrames = Aud_CurrentChannel->envelopeTimer;
    volume = (Aud_CurrentChannel->envelopeVolume * volume) >> 8;

    if (Aud_CurrentChannel->unk_A8[1] != 0) {
        volume = ((Aud_CurrentChannel->unk_A8[1] + 0x100) * volume) >> 8;
        if (volume > 0x7FFF) {
            volume = 0x7FFF;
        }
    }

    if (Aud_CurrentChannel->unk_C6[1] != 0) {
        v1 = Aud_CurrentChannel->unk_C6[1] / 64;
        if (v1 <= -0x100) {
            volume = 0;
        } else {
            volume = ((v1 + 0x100) * volume) >> 8;
            if (volume > 0x7FFF) {
                volume = 0x7FFF;
            }
        }
    }

    if (Aud_CurrentChannel->unk_BE != 0) {
        volume = (Aud_CurrentChannel->unk_BE * volume) >> 8;
        volumeFrames = func_80014A18(volumeFrames, Aud_CurrentChannel->unk_BE, 2);
    }

    if (D_8008A47E != 0) {
        volume = (D_8008A47E * volume) >> 8;
        volumeFrames = func_80014A18(volumeFrames, D_8008A47E, D_8008A47C);
    }

    if ((Aud_CurrentChannel->command & 0x7FFF) < 0x100) {
        if (D_8008A47B != 0) {
            volume = (D_8008A47B * volume) >> 8;
            volumeFrames = func_80014A18(volumeFrames, D_8008A47B, D_8008A479);
        }

        if (D_8008A484 != 0) {
            volume = (D_8008A484 * volume) >> 8;
            if (D_8008A483 < 0) {
                volumeFrames = func_80014A18(volumeFrames, D_8008A484, 2);
            }
        }
    }

    for (i = 0; i < 1; i++) {
        if ((Aud_CurrentChannel->command & 0x7FFF) == D_8008A486[i]) {
            volume = (D_8008A485[i] * volume) >> 8;
            volumeFrames = func_80014A18(volumeFrames, D_8008A485[i], 2);
            break;
        }
    }

    if (Aud_CurrentChannel->volume != (s16) volume || Aud_CurrentChannel->volumeFrames != (u16) volumeFrames) {
        Aud_CurrentChannel->volume = volume;
        Aud_CurrentChannel->volumeFrames = volumeFrames;
        alSynSetVol(&alGlobals->drvr, &Aud_Voices[Aud_CurrentChanId], volume, volumeFrames * 5000);
    }
}

s32 func_80014A18(s32 duration, u8 volumeMult, u8 arg2) {
    if (Aud_CurrentChannel->envelopePhase >= AL_PHASE_SUSTAIN) {
        if (duration < 512) {
            duration = (volumeMult * duration) >> 8;
        } else {
            duration = volumeMult * arg2 * 2;
        }
    }

    return duration;
}

void func_80014A74(void) {
    Aud_CurrentChannel->envelopeTimer = 0;
    if (Aud_CurrentChannel->attackTime != 0) {
        Aud_CurrentChannel->envelopeVolume = 0x20;
        aud_update_volume();
        Aud_CurrentChannel->envelopePhase = AL_PHASE_ATTACK;
        Aud_CurrentChannel->envelopeVolume = 0x100;
        Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->attackTime;
        aud_update_volume();
    } else {
        Aud_CurrentChannel->envelopeVolume = 0x100;
        aud_update_volume();
        func_80014B00();
    }
}

void func_80014B00(void) {
    if (Aud_CurrentChannel->unk_54 != 0) {
        Aud_CurrentChannel->envelopePhase = AL_PHASE_DECAY;
        Aud_CurrentChannel->envelopeVolume -= Aud_CurrentChannel->unk_54;
        Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->decayTime;
        aud_update_volume();
    } else {
        func_80014B6C();
    }
}

void func_80014B6C(void) {
    Aud_CurrentChannel->envelopePhase = AL_PHASE_SUSTAIN;
    if (Aud_CurrentChannel->sustainTime != 0) {
        Aud_CurrentChannel->envelopeVolume = 0;
        Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->sustainTime;
        aud_update_volume();
    }
}

void func_80014BBC(void) {
    Aud_CurrentChannel->envelopePhase = AL_PHASE_RELEASE;
    Aud_CurrentChannel->envelopeVolume = 0;
    Aud_CurrentChannel->envelopeTimer = Aud_CurrentChannel->releaseTime;
    aud_update_volume();
}

void func_80014C00(void) {
    Aud_CurrentChannel->stopTimer = 1;
    Aud_CurrentChannel->envelopePhase = AL_PHASE_RELEASE;
    Aud_CurrentChannel->envelopeVolume = 0;
    Aud_CurrentChannel->envelopeTimer = 1;
    aud_update_volume();
}

void func_80014C4C(void) {
    Aud_CurrentChannel->envelopeTimer--;
    if (Aud_CurrentChannel->volumeFrames != 0) {
        Aud_CurrentChannel->volumeFrames--;
    }
    if (Aud_CurrentChannel->envelopeTimer == 0) {
        switch (Aud_CurrentChannel->envelopePhase) {
            case AL_PHASE_ATTACK:
                func_80014B00();
                break;
            case AL_PHASE_DECAY:
                func_80014B6C();
                break;
        }
    }
}
