/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyVector2DInt32.h"

FVector2DInt32 UReactivePropertyVector2DInt32::GetValue() const
{
	return Value;
}

void UReactivePropertyVector2DInt32::SetValue(FVector2DInt32 NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}
