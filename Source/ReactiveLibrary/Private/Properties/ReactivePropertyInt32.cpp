/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyInt32.h"

int32 UReactivePropertyInt32::GetValue() const
{
	return Value;
}

void UReactivePropertyInt32::SetValue(int32 NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}

