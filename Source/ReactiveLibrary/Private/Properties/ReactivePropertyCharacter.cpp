/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyCharacter.h"

#include "GameFramework/Character.h"

UReactivePropertyCharacter::UReactivePropertyCharacter()
{
	Value = nullptr;
}

ACharacter* UReactivePropertyCharacter::GetValue() const
{
	return Value;
}

bool UReactivePropertyCharacter::SetValue(ACharacter* NewValue)
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


//---------------------------------------------------------------------------------------------------
//Weak Reactive Property Character Class

UWeakReactivePropertyCharacter::UWeakReactivePropertyCharacter()
{
	Value = nullptr;
}

ACharacter* UWeakReactivePropertyCharacter::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

bool UWeakReactivePropertyCharacter::SetValue(ACharacter* NewValue)
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

bool UWeakReactivePropertyCharacter::IsValidPtr() const
{
	return Value.IsValid();
}
