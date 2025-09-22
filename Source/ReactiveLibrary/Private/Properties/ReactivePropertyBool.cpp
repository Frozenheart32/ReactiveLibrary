/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyBool.h"

UReactivePropertyBool::UReactivePropertyBool()
{
	Value = false;
}

bool UReactivePropertyBool::GetValue() const
{
	return Value;
}

void UReactivePropertyBool::SetValue(bool NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
