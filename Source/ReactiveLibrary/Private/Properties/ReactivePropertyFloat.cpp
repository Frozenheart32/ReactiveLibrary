/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyFloat.h"

#include "Kismet/KismetMathLibrary.h"

float UReactivePropertyFloat::GetValue() const
{
	return Value;
}

void UReactivePropertyFloat::SetValue(float NewValue)
{
	if(UKismetMathLibrary::NearlyEqual_FloatFloat(Value, NewValue))
		return;
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}
