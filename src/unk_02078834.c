#include "unk_02078834.h"

#include "encounter.h"
#include "field_system.h"
#include "launch_application.h"
#include "overlay_13_thumb_1.h"
#include "overlay_91.h"
#include "overlay_92.h"
#include "overlay_93_thumb_1.h"
#include "overlay_manager.h"
#include "save_vars_flags.h"
#include "sys_flags.h"
#include "unk_02037C94.h"
#include "unk_020915B0.h"
#include "unk_020968B0.h"

FS_EXTERN_OVERLAY(OVY_90);
FS_EXTERN_OVERLAY(OVY_91);
FS_EXTERN_OVERLAY(OVY_92);
FS_EXTERN_OVERLAY(OVY_93);
FS_EXTERN_OVERLAY(OVY_44);

const u8 _0210125C[] = { 3, 4, 4, 4 };
const OverlayManagerTemplate _02101280 = {
    .init = ov44_02232EA8,
    .exec = ov44_02232F64,
    .exit = ov44_022330A8,
    .ovy_id = FS_OVERLAY_ID(OVY_44)
};
const OverlayManagerTemplate _02101270 = {
    .init = ov92_0225CAB4,
    .exec = ov92_0225CDF4,
    .exit = ov92_0225D36C,
    .ovy_id = FS_OVERLAY_ID(OVY_92)
};
const OverlayManagerTemplate _02101260 = {
    .init = ov91_0225C540,
    .exec = ov91_0225C58C,
    .exit = ov91_0225C9EC,
    .ovy_id = FS_OVERLAY_ID(OVY_91)
};
const OverlayManagerTemplate _02101290 = {
    .init = ov44_0222A4B4,
    .exec = ov44_0222A60C,
    .exit = ov44_0222A758,
    .ovy_id = FS_OVERLAY_ID(OVY_44)
};
const OverlayManagerTemplate _021012A0 = {
    .init = ov93_0225C540,
    .exec = ov93_0225C574,
    .exit = ov93_0225C6C0,
    .ovy_id = FS_OVERLAY_ID(OVY_93)
};

BOOL sub_02078834(TaskManager *taskManager) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    UnkStruct_sub_02078834 *temp_r0 = TaskManager_GetEnvironment(taskManager);
    switch (temp_r0->unk4) {
    case 0:
        temp_r0->overlayArgs0->unk0 = fieldSystem->saveData;
    case 1:
        temp_r0->unk4++;
        if ((temp_r0->overlayArgs0->unk4 == 1) && (sub_0203A05C(fieldSystem->saveData) != 0)) {
            temp_r0->unk4 = 10;
            temp_r0->unk8[0] = 0;
        }
        break;
    case 2:
        CallApplicationAsTask(taskManager, &_02101290, temp_r0->overlayArgs0);
        temp_r0->unk4++;
        break;
    case 3:
        if (sub_0203A05C(fieldSystem->saveData) != 0) {
            SetFlag970(Save_VarsFlags_Get(fieldSystem->saveData));
        }
        switch (temp_r0->overlayArgs0->unk4) {
        case 3:
            temp_r0->unkC = 0;
            temp_r0->unkD = 0;
            temp_r0->unk4 = 4;
            break;
        case 1:
            temp_r0->unkC = 50;
            temp_r0->unkD = 0;
            temp_r0->unk4 = 4;
            break;
        case 2:
            temp_r0->unkC = 100;
            temp_r0->unkD = 0;
            temp_r0->unk4 = 4;
            break;
        case 6:
            temp_r0->unkC = 0;
            temp_r0->unkD = 1;
            temp_r0->unk4 = 4;
            break;
        case 4:
            temp_r0->unkC = 50;
            temp_r0->unkD = 1;
            temp_r0->unk4 = 4;
            break;
        case 5:
            temp_r0->unkC = 100;
            temp_r0->unkD = 1;
            temp_r0->unk4 = 4;
            break;
        case 7:
            temp_r0->unk4 = 6;
            break;
        case 10:
            temp_r0->unk8[0] = 1;
            temp_r0->unk4 = 11;
            break;
        case 8:
            temp_r0->unk4 = 9;
            break;
        case 12:
            temp_r0->unk4 = 12;
            break;
        case 13:
            temp_r0->unk4 = 14;
            break;
        case 14:
            temp_r0->unk4 = 18;
            break;
        case 15:
            temp_r0->unk4 = 22;
            break;
        case 9:
            temp_r0->unk4 = 8;
            break;
        }
        break;
    case 4:
        CallTask_02050960(taskManager, temp_r0->overlayArgs0->unk8, temp_r0->unkC, temp_r0->unkD);
        temp_r0->unk4++;
        break;
    case 5:
        temp_r0->unk4 = 2;
        break;
    case 6:
        CallTask_WirelessTrade(taskManager);
        temp_r0->unk4++;
        break;
    case 7:
        temp_r0->unk4 = 2;
        break;
    case 8:
        Heap_Create(HEAP_ID_3, HEAP_ID_53, 0x40100);
        LoadOVY13();
        ov13_0221BA00(HEAP_ID_53);
        OS_ResetSystem(0);
        break;
    case 9:
    case 10:
    case 11:
        Heap_Free(temp_r0->overlayArgs0);
        Heap_Free(temp_r0);
        temp_r0->unk4++;
        return 1;
    case 12:
        sub_020378E4(0);
        temp_r0->overlayArgs1 = sub_020968B0(fieldSystem, NULL);
        temp_r0->unk4++;
        break;
    case 13:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            Heap_Free(temp_r0->overlayArgs1);
            temp_r0->unk4 = 2;
        }
        break;
    case 14:
        sub_02078B9C(temp_r0, fieldSystem, HEAP_ID_FIELD2, 1);
        temp_r0->unk4++;
        break;
    case 15:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = sub_02078BD8(temp_r0);
        }
        break;
    case 16:
        temp_r0->overlayArgs1 = sub_02078C18(fieldSystem, HEAP_ID_FIELD2, temp_r0->unk14);
        temp_r0->unk4++;
        break;
    case 17:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = 2;
            sub_02078C60(temp_r0->overlayArgs1);
        }
        break;
    case 18:
        sub_02078B9C(temp_r0, fieldSystem, HEAP_ID_FIELD2, 2);
        temp_r0->unk4++;
        break;
    case 19:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = sub_02078BD8(temp_r0);
        }
        break;
    case 20:
        temp_r0->overlayArgs1 = sub_02078C74(fieldSystem, HEAP_ID_FIELD2, temp_r0->unk14);
        temp_r0->unk4++;
        break;
    case 21:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = 2;
            sub_02078CB4(temp_r0->overlayArgs1);
        }
        break;
    case 22:
        sub_02078B9C(temp_r0, fieldSystem, HEAP_ID_FIELD2, 3);
        temp_r0->unk4++;
        break;
    case 23:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = sub_02078BD8(temp_r0);
        }
        break;
    case 24:
        temp_r0->overlayArgs1 = sub_02078CC8(fieldSystem, HEAP_ID_FIELD2, temp_r0->unk14);
        temp_r0->unk4++;
        break;
    case 25:
        if (FieldSystem_ApplicationIsRunning(fieldSystem) == 0) {
            temp_r0->unk4 = 2;
            sub_02078D10(temp_r0->overlayArgs1);
        }
        break;
    default:
        return 1;
    }
    return 0;
}

UnkStruct_sub_02078834 *sub_02078B2C(void) {
    UnkStruct_sub_02078834 *temp_r0 = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(UnkStruct_sub_02078834));
    MI_CpuFill8(temp_r0, 0, sizeof(UnkStruct_sub_02078834));
    UnkStruct_ov44_0222A758_args *temp_r0_2 = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(UnkStruct_ov44_0222A758_args));
    temp_r0->overlayArgs0 = temp_r0_2;
    MI_CpuFill8(temp_r0_2, 0, sizeof(UnkStruct_ov44_0222A758_args));
    return temp_r0;
}

void sub_02078B58(TaskManager *taskManager) {
    UnkStruct_sub_02078834 *temp_r0 = sub_02078B2C();
    temp_r0->overlayArgs0->unk4 = 2;
    TaskManager_Call(taskManager, sub_02078834, temp_r0);
}

void sub_02078B78(TaskManager *taskManager, u16 *arg1) {
    UnkStruct_sub_02078834 *temp_r0 = sub_02078B2C();
    temp_r0->overlayArgs0->unk4 = 1;
    temp_r0->unk8 = arg1;
    TaskManager_Call(taskManager, sub_02078834, temp_r0);
}

void sub_02078B9C(UnkStruct_sub_02078834 *arg0, FieldSystem *fieldSystem, enum HeapID arg2, s32 arg3) {
    UnkStruct_ov44_args *temp_r0 = Heap_Alloc(arg2, 0xC);
    temp_r0->unk0 = arg3;
    temp_r0->unk1 = 2;
    temp_r0->unk2 = _0210125C[arg3];
    temp_r0->unk3 = 0;
    temp_r0->unk4 = 0;
    temp_r0->unk8 = fieldSystem->saveData;
    arg0->overlayArgs1 = temp_r0;
    FieldSystem_LaunchApplication(fieldSystem, &_02101280, temp_r0);
}

s32 sub_02078BD8(UnkStruct_sub_02078834 *arg0) {
    UnkStruct_ov44_args *temp_r0 = arg0->overlayArgs1;
    if (temp_r0->unk3 == 1) {
        switch (temp_r0->unk0) {
        case 1:
            arg0->unk4 = 16;
            break;
        case 2:
            arg0->unk4 = 20;
            break;
        case 3:
        default:
            arg0->unk4 = 24;
            break;
        }
    } else {
        arg0->unk4 = 1;
    }
    arg0->unk14 = temp_r0->unk4;
    Heap_Free(arg0->overlayArgs1);
    return arg0->unk4;
}

UnkStruct_sub_02078C18 *sub_02078C18(FieldSystem *fieldSystem, enum HeapID arg1, s32 arg2) {
    UnkStruct_sub_02078C18 *temp_r0 = Heap_Alloc(arg1, 0x3C);
    memset(temp_r0, 0, 0x3C);
    temp_r0->unk38 = arg2;
    temp_r0->unk39 = 0;
    temp_r0->unk34 = fieldSystem->saveData;
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    FieldSystem_LaunchApplication(fieldSystem, &_02101260, temp_r0);
    return temp_r0;
}

void sub_02078C60(void *arg0) {
    Heap_Free(arg0);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

UnkStruct_sub_02078C74 *sub_02078C74(FieldSystem *fieldSystem, enum HeapID arg1, s32 arg2) {
    UnkStruct_sub_02078C74 *temp_r0 = Heap_Alloc(arg1, 0x40);
    memset(temp_r0, 0, 0x40);
    temp_r0->unk3C = arg2;
    temp_r0->unk38 = 0;
    temp_r0->unk34 = fieldSystem->saveData;
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    FieldSystem_LaunchApplication(fieldSystem, &_02101270, temp_r0);
    return temp_r0;
}

void sub_02078CB4(void *arg0) {
    Heap_Free(arg0);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

UnkStruct_sub_02078C18 *sub_02078CC8(FieldSystem *fieldSystem, enum HeapID arg1, s32 arg2) {
    UnkStruct_sub_02078C18 *temp_r0 = Heap_Alloc(arg1, 0x3C);
    MI_CpuFill8(temp_r0, 0, 0x3C);
    temp_r0->unk38 = arg2;
    temp_r0->unk39 = 0;
    temp_r0->unk34 = fieldSystem->saveData;
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_90), OVY_LOAD_ASYNC);
    FieldSystem_LaunchApplication(fieldSystem, &_021012A0, temp_r0);
    return temp_r0;
}

void sub_02078D10(void *arg0) {
    Heap_Free(arg0);
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_90));
}

s32 sub_02078D24(s32 arg0) {
    UnkStruct_ov44_0223197C *tempStruct = sub_020398C8();
    u8 temp_r2 = tempStruct->unk0.unk1B;
    u8 temp_r0 = tempStruct->unk24[arg0].unk1B;
    if (temp_r2 == 12 && temp_r0 == 5) {
        return 1;
    }
    if (temp_r2 == 13 && temp_r0 == 6) {
        return 1;
    }
    if (temp_r2 == 14 && temp_r0 == 7) {
        return 1;
    }
    if (temp_r2 == 9 && temp_r0 == 2) {
        return 1;
    }
    if (temp_r2 == 10 && temp_r0 == 3) {
        return 1;
    }
    if (temp_r2 == 11 && temp_r0 == 4) {
        return 1;
    }
    if (temp_r2 == 15 && temp_r0 == 8) {
        return 1;
    }
    if (temp_r2 == 19 && temp_r0 == 0x12) {
        return 1;
    }
    if (temp_r2 == 21 && temp_r0 == 0x14) {
        return 1;
    }
    if (temp_r2 == 23 && temp_r0 == 0x16) {
        return 1;
    }
    if (temp_r2 == 25 && temp_r0 == 0x18) {
        return 1;
    }
    if (temp_r2 == 0x1B && temp_r0 == 0x1A) {
        return 1;
    }
    if (temp_r2 == 0x10 && temp_r0 == 1) {
        return 1;
    }
    return 0;
}