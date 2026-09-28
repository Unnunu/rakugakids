#ifndef VARIABLES_H
#define VARIABLES_H

extern ScTask D_80027738[];
extern Gfx D_80028790[];
extern HeapChunk *D_8002A2D0;
extern Scheduler gScheduler;
extern OSMesgQueue *D_80037458;
extern OSIoMesg D_80037460;
extern HeapChunk D_80044230;
extern HeapChunk *D_80044240;
extern HeapChunk *D_80044248;
extern HeapChunk *D_8004424C;
extern u8 D_80044250;
extern u8 D_80044251;
extern Struct4 *D_80044254;
extern Gfx *D_80044258;
extern TaskManager *D_80044260;
extern TaskManager *D_80044264;
extern HeapChunk *D_80044268;
extern u8 D_80044270[];
extern u8 D_80045270[0xA000];
extern u8 D_8004F2C0[];

extern u16 D_80100000[2][SCREEN_WIDTH * SCREEN_HEIGHT];
extern u8 D_8014B000[];
extern u8 D_3D6500[];

extern u8 D_800255A0[];

extern Asset D_80028998;
extern Asset D_80028968;
extern Asset D_80029CB8;
extern Asset D_80029CC4;
extern Asset D_800296D0;
extern Asset D_8002994C;

extern ChanState *Aud_CurrentChannel;
extern u8 *D_8008A708;
extern ALBankFile *Aud_Banks[3];
extern u8 Aud_CurrentChanId;
extern ALVoice Aud_Voices[];
extern ALFxRef D_8008A760;
extern s32 Aud_FxParams[];
extern u8 D_8008A488[];
extern u8 D_80055430;
extern u8 D_80055431;
extern u16 Aud_TickCount;
extern AudioStruct3 D_8008A718[];
extern u8 D_8008A710;
extern AudioStruct9 D_8008A730[];

extern u8 D_8002B0D0[];
extern u8 D_8002B0D8[][4];
extern AudioStruct5 D_8002B0F8[];
extern AudioStruct7 D_8002B1C0[];
extern u8 D_8008A728;
extern u16 D_8008A770;

extern Struct6 *D_80044244;
extern s32 D_80029F30;

#endif
