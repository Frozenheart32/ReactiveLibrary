/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyString.h"

UReactivePropertyString::UReactivePropertyString()
{
	Value = FString{};
}

const FString& UReactivePropertyString::GetValue() const
{
	return Value;
}

void UReactivePropertyString::SetValue(const FString& NewValue)
{
	if(Value == NewValue)
		return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}

int32 UReactivePropertyString::Length() const
{
	return Value.Len();
}

bool UReactivePropertyString::IsEmpty() const
{
	return Value.IsEmpty();
}
