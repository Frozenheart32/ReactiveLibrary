/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyFloat.h"

#include "Kismet/KismetMathLibrary.h"

UReactivePropertyFloat::UReactivePropertyFloat()
{
	Value = 0.f;
}

float UReactivePropertyFloat::GetValue() const
{
	return Value;
}

void UReactivePropertyFloat::SetValue(float NewValue)
{
	if(UKismetMathLibrary::NearlyEqual_FloatFloat(Value, NewValue))
		return;
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
}
