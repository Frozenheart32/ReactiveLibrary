/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Properties/ReactivePropertyActor.h"

AActor* UReactivePropertyActor::GetValue() const
{
	return Value;
}

bool UReactivePropertyActor::SetValue(AActor* NewValue)
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

//--------------------------------------------------------------------------------------------

//Weak Reactive Property Actor Class

AActor* UWeakReactivePropertyActor::GetValue() const
{
	return Value.IsValid() ? Value.Get() : nullptr;
}

bool UWeakReactivePropertyActor::SetValue(AActor* NewValue)
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

bool UWeakReactivePropertyActor::IsValidPtr() const
{
	return Value.IsValid();
}
