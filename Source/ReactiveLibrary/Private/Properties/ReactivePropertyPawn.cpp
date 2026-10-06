/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyPawn.h"
#include "GameFramework/Pawn.h"


APawn* UReactivePropertyPawn::GetValue() const
{
	return Value;
}

void UReactivePropertyPawn::SetValue(APawn* NewValue)
{
	if(!IsValid(NewValue)) return;
	
	if(IsValid(Value))
	{
		if(Value == NewValue)
			return;
	}
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value);

	OnValueChangedEvent.Broadcast(Value);
}


//---------------------------------------------------------------------------------------
//Weak Reactive Property Pawn Class

APawn* UWeakReactivePropertyPawn::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

void UWeakReactivePropertyPawn::SetValue(APawn* NewValue)
{
	if(!IsValid(NewValue)) return;
	
	if(Value.IsValid())
	{
		if(Value == NewValue)
			return;
	}
	
	Value = NewValue;

	if(OnValueChanged.IsBound())
		OnValueChanged.Broadcast(Value.Get());

	OnValueChangedEvent.Broadcast(Value.Get());
}

bool UWeakReactivePropertyPawn::IsValidPtr() const
{
	return Value.IsValid();
}
