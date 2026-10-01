#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "event_data.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "item.h"
#include "item_use.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "pokemon.h"
#include "script.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"

#include "number_picker.h"

// Slot numbers -- plain ints, safe to pass as function arguments.
#define SLOT_MIN 0
#define SLOT_MAX 1
#define SLOT_INPUT 2
#define SLOT_CALLER 3
#define SLOT_CB_HI 4
#define SLOT_CB_LO 5
#define SLOT_DRAW_HI 6
#define SLOT_DRAW_LO 7
#define SLOT_INITIALIZING 8
#define tInitializing data[SLOT_INITIALIZING]

// Direct field-access macros -- only ever used as task->tMin etc.
#define tMin data[SLOT_MIN]
#define tMax data[SLOT_MAX]
#define tInput data[SLOT_INPUT]
#define tCallerTaskId data[SLOT_CALLER]

static void SetPtr(u8 taskId, u8 hiSlot, u8 loSlot, void *ptr)
{
    u32 val = (u32)ptr;
    gTasks[taskId].data[hiSlot] = val >> 16;
    gTasks[taskId].data[loSlot] = val & 0xFFFF;
}

static void *GetPtr(u8 taskId, u8 hiSlot, u8 loSlot)
{
    u32 val = ((u32)(u16)gTasks[taskId].data[hiSlot] << 16) | (u16)gTasks[taskId].data[loSlot];
    return (void *)val;
}

static void DrawCurrentValue(u8 taskId)
{
    NumberPickerDrawCallback drawCallback = (NumberPickerDrawCallback)GetPtr(taskId, SLOT_DRAW_HI, SLOT_DRAW_LO);
    if (drawCallback != NULL)
        drawCallback(gTasks[taskId].tInput);
}

static void Task_NumberPicker(u8 taskId)
{
    struct Task *task = &gTasks[taskId];
    bool8 changed = FALSE;

    if (task->tInitializing)
    {
        task->tInitializing = FALSE;
        return;
    }

    if (JOY_NEW(DPAD_UP) && task->tInput < task->tMax)
    {
        task->tInput++;
        changed = TRUE;
    }

    if (JOY_NEW(DPAD_DOWN) && task->tInput > task->tMin)
    {
        task->tInput--;
        changed = TRUE;
    }

    if (JOY_NEW(DPAD_RIGHT))
    {
        task->tInput += 10;
        if (task->tInput > task->tMax)
            task->tInput = task->tMax;
        changed = TRUE;
    }

    if (JOY_NEW(DPAD_LEFT))
    {
        task->tInput -= 10;
        if (task->tInput < task->tMin)
            task->tInput = task->tMin;
        changed = TRUE;
    }

    if (changed)
        DrawCurrentValue(taskId);

    if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
    {
        bool8 cancelled = JOY_NEW(B_BUTTON);
        NumberPickerCallback callback = (NumberPickerCallback)GetPtr(taskId, SLOT_CB_HI, SLOT_CB_LO);
        u8 callerTaskId = task->tCallerTaskId;
        s16 result = task->tInput;

        DestroyTask(taskId);

        if (callback != NULL)
            callback(callerTaskId, result, cancelled);
    }
}

u8 StartNumberPicker(u8 callerTaskId, s16 min, s16 max, s16 start,
                     NumberPickerCallback callback, NumberPickerDrawCallback drawCallback)
{
    u8 taskId = CreateTask(Task_NumberPicker, 8);
    struct Task *task = &gTasks[taskId];

    task->tMin = min;
    task->tMax = max;
    task->tInput = start;
    task->tCallerTaskId = callerTaskId;
    SetPtr(taskId, SLOT_CB_HI, SLOT_CB_LO, (void *)callback);
    SetPtr(taskId, SLOT_DRAW_HI, SLOT_DRAW_LO, (void *)drawCallback);

    task->tInitializing = TRUE;
    DrawCurrentValue(taskId);
    return taskId;
}

static u8 sNumberPickerWindowId;
static const u8 *sNumberPickerLabel;

static void NumberPickerSpecial_Draw(s16 currentValue)
{
    FillWindowPixelBuffer(sNumberPickerWindowId, PIXEL_FILL(1));
    ConvertIntToDecimalStringN(gStringVar1, currentValue, STR_CONV_MODE_LEFT_ALIGN, 3);
    StringCopy(gStringVar2, sNumberPickerLabel);
    StringExpandPlaceholders(gStringVar4, COMPOUND_STRING("{STR_VAR_2}\n{STR_VAR_1}"));
    AddTextPrinterParameterized(sNumberPickerWindowId, FONT_NORMAL, gStringVar4, 8, 2, 0, NULL);
    CopyWindowToVram(sNumberPickerWindowId, COPYWIN_FULL);
}

static void NumberPickerSpecial_OnComplete(u8 callerTaskId, s16 result, bool8 cancelled)
{
    ClearWindowTilemap(sNumberPickerWindowId);
    CopyWindowToVram(sNumberPickerWindowId, COPYWIN_GFX);
    RemoveWindow(sNumberPickerWindowId);

    gSpecialVar_Result = cancelled ? MULTI_B_PRESSED : result;
    ScriptContext_Enable();
}

void ShowNumberPicker(void)
{
    struct WindowTemplate template = CreateWindowTemplate(0, 20, 14, 8, 4, 0xF, 0x64);
    sNumberPickerWindowId = AddWindow(&template);
    SetStandardWindowBorderStyle(sNumberPickerWindowId, FALSE);

    sNumberPickerLabel = COMPOUND_STRING("Custom HP%");
    StartNumberPicker(TASK_NONE, gSpecialVar_0x8009, gSpecialVar_0x800A, gSpecialVar_0x800B,
                      NumberPickerSpecial_OnComplete, NumberPickerSpecial_Draw);
}

void ShowCustomHPPicker(void)
{
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];
    u16 maxHp = GetMonData(mon, MON_DATA_MAX_HP);

    struct WindowTemplate template = CreateWindowTemplate(0, 20, 14, 8, 4, 0xF, 0x64);
    sNumberPickerWindowId = AddWindow(&template);
    SetStandardWindowBorderStyle(sNumberPickerWindowId, FALSE);

    sNumberPickerLabel = COMPOUND_STRING("Custom HP");
    StartNumberPicker(TASK_NONE, 1, maxHp, maxHp,
                      NumberPickerSpecial_OnComplete, NumberPickerSpecial_Draw);
}
