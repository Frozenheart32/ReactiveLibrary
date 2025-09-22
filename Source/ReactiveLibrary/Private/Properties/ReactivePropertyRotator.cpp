/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyRotator.h"

UReactivePropertyRotator::UReactivePropertyRotator()
{
	Value = FRotator{};
}

const FRotator& UReactivePropertyRotator::GetValue() const
{
	return Value;
}

void UReactivePropertyRotator::SetValue(const FRotator& NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
