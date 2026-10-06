/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyCharacter.h"

#include "GameFramework/Character.h"

ACharacter* UReactivePropertyCharacter::GetValue() const
{
	return Value;
}

void UReactivePropertyCharacter::SetValue(ACharacter* NewValue)
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


//---------------------------------------------------------------------------------------------------
//Weak Reactive Property Character Class

ACharacter* UWeakReactivePropertyCharacter::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

void UWeakReactivePropertyCharacter::SetValue(ACharacter* NewValue)
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

bool UWeakReactivePropertyCharacter::IsValidPtr() const
{
	return Value.IsValid();
}
