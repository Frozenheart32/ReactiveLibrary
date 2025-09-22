/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyName.h"

UReactivePropertyName::UReactivePropertyName()
{
	Value = NAME_None;
}

const FName& UReactivePropertyName::GetValue() const
{
	return Value;
}

void UReactivePropertyName::SetValue(const FName& NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}

bool UReactivePropertyName::IsNone() const
{
	return Value.IsNone();
}
