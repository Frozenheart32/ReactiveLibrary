/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyPawn.h"

UReactivePropertyPawn::UReactivePropertyPawn()
{
	Value =  nullptr;
}

APawn* UReactivePropertyPawn::GetValue() const
{
	return Value;
}

bool UReactivePropertyPawn::SetValue(APawn* NewValue)
{
	if(!IsValid(NewValue)) return false;
	
	if(IsValid(Value))
	{
		if(Value == NewValue)
			return false;
	}
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value);
	return true;
}


//---------------------------------------------------------------------------------------
//Weak Reactive Property Pawn Class

UWeakReactivePropertyPawn::UWeakReactivePropertyPawn()
{
	Value = nullptr;
}

APawn* UWeakReactivePropertyPawn::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

bool UWeakReactivePropertyPawn::SetValue(APawn* NewValue)
{
	if(!IsValid(NewValue)) return false;
	
	if(Value.IsValid())
	{
		if(Value == NewValue)
			return false;
	}
	
	Value = NewValue;
	OnValueChanged.Broadcast(Value.Get());
	return true;
}

bool UWeakReactivePropertyPawn::IsValidPtr() const
{
	return Value.IsValid();
}
