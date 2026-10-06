/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyVector.h"


const FVector& UReactivePropertyVector::GetValue() const
{
	return Value;
}

void UReactivePropertyVector::SetValue(const FVector& NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}
