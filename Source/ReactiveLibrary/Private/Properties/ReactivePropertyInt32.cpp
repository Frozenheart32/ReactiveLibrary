/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyInt32.h"

UReactivePropertyInt32::UReactivePropertyInt32()
{
	Value = 0;
}

int32 UReactivePropertyInt32::GetValue() const
{
	return Value;
}

void UReactivePropertyInt32::SetValue(int32 NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}

