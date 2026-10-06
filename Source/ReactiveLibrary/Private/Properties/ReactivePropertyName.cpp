/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Properties/ReactivePropertyName.h"

const FName& UReactivePropertyName::GetValue() const
{
	return Value;
}

void UReactivePropertyName::SetValue(const FName& NewValue)
{
	if(Value == NewValue) return;
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}

bool UReactivePropertyName::IsNone() const
{
	return Value.IsNone();
}
