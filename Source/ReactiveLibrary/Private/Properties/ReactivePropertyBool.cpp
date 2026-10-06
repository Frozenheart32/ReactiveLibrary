/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyBool.h"

bool UReactivePropertyBool::GetValue() const
{
	return Value;
}

void UReactivePropertyBool::SetValue(bool NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}
