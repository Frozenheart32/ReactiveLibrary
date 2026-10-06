/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyRotator.h"

const FRotator& UReactivePropertyRotator::GetValue() const
{
	return Value;
}

void UReactivePropertyRotator::SetValue(const FRotator& NewValue)
{
	if(Value == NewValue) return;

	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}
