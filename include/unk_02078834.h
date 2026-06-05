#ifndef POKEHEARTGOLD_UNK_02078834_H
#define POKEHEARTGOLD_UNK_02078834_H

#include "task.h"
#include "overlay_44.h"
#include "overlay_44_02232E9C.h"

typedef struct UnkStruct_sub_02078C74 {
    u8 unk0[0x34];
    SaveData* unk34;
    u32 unk38;
    u32 unk3C;
} UnkStruct_sub_02078C74;

typedef struct UnkStruct_sub_02078C18 {
    u8 unk0[0x34];
    SaveData* unk34;
    u8 unk38;
    u8 unk39;
} UnkStruct_sub_02078C18;

typedef struct UnkStruct_sub_02078834 {
    UnkStruct_ov44_0222A758_args* overlayArgs0;
    u32 unk4;
    u16* unk8;
    u8 unkC;
    u8 unkD;
    void* overlayArgs1;
    u32 unk14;
} UnkStruct_sub_02078834;

BOOL sub_02078834(TaskManager* taskManager);
UnkStruct_sub_02078834* sub_02078B2C(void);
void sub_02078B58(TaskManager* taskManager);
void sub_02078B78(TaskManager* taskManager, u16* arg1);
void sub_02078B9C(UnkStruct_sub_02078834* arg0, FieldSystem* fieldSystem, enum HeapID arg2, s32 arg3);
s32 sub_02078BD8(UnkStruct_sub_02078834* arg0);
UnkStruct_sub_02078C18* sub_02078C18(FieldSystem* fieldSystem, enum HeapID arg1, s32 arg2);
void sub_02078C60(void* arg0);
UnkStruct_sub_02078C74* sub_02078C74(FieldSystem* fieldSystem, enum HeapID arg1, s32 arg2);
void sub_02078CB4(void* arg0);
UnkStruct_sub_02078C18* sub_02078CC8(FieldSystem* fieldSystem, enum HeapID arg1, s32 arg2);
void sub_02078D10(void* arg0);
s32 sub_02078D24(s32 arg0);

#endif // POKEHEARTGOLD_UNK_02078834_H
