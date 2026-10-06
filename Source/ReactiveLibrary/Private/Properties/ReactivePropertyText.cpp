/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyText.h"


const FText& UReactivePropertyText::GetValue() const
{
	return Value;
}

void UReactivePropertyText::SetValue(const FText& NewValue)
{
	if(Value.EqualTo(NewValue)) return;
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}

bool UReactivePropertyText::IsEmpty() const
{
	return Value.IsEmpty();
}
