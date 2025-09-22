/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyVector.h"

UReactivePropertyVector::UReactivePropertyVector()
{
	Value = FVector{};
}

const FVector& UReactivePropertyVector::GetValue() const
{
	return Value;
}

void UReactivePropertyVector::SetValue(const FVector& NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
