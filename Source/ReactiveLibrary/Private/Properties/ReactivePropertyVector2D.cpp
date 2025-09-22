/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyVector2D.h"

UReactivePropertyVector2D::UReactivePropertyVector2D()
{
	Value = FVector2D{};
}

const FVector2D& UReactivePropertyVector2D::GetValue() const
{
	return Value;
}

void UReactivePropertyVector2D::SetValue(const FVector2D& NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
