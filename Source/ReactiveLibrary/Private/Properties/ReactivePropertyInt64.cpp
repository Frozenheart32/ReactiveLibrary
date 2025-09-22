/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyInt64.h"

int64 UReactivePropertyInt64::GetValue() const
{
	return Value;
}

void UReactivePropertyInt64::SetValue(int64 NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
