#ifndef GUARD_NUMBER_PICKER_H
#define GUARD_NUMBER_PICKER_H

#include "global.h"

// Called when the player accepts (A) or cancels (B).
typedef void (*NumberPickerCallback)(u8 callerTaskId, s16 result, bool8 cancelled);

// Called once immediately when the picker starts, and again every time
// the value changes. Use this to redraw your window/text.
typedef void (*NumberPickerDrawCallback)(s16 currentValue);

u8 StartNumberPicker(u8 callerTaskId, s16 min, s16 max, s16 start,
                     NumberPickerCallback callback, NumberPickerDrawCallback drawCallback);

#endif // GUARD_NUMBER_PICKER_H
