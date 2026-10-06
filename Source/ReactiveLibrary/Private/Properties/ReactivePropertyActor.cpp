/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyActor.h"
#include "GameFramework/Actor.h"

AActor* UReactivePropertyActor::GetValue() const
{
	return Value;
}

void UReactivePropertyActor::SetValue(AActor* NewValue)
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

//--------------------------------------------------------------------------------------------

//Weak Reactive Property Actor Class

AActor* UWeakReactivePropertyActor::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

void UWeakReactivePropertyActor::SetValue(AActor* NewValue)
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

bool UWeakReactivePropertyActor::IsValidPtr() const
{
	return Value.IsValid();
}
