/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyText.h"

UReactivePropertyText::UReactivePropertyText()
{
	Value = FText{};
}

const FText& UReactivePropertyText::GetValue() const
{
	return Value;
}

void UReactivePropertyText::SetValue(const FText& NewValue)
{
	if(Value.EqualTo(NewValue)) return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}

bool UReactivePropertyText::IsEmpty() const
{
	return Value.IsEmpty();
}
