/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionFloat.h"

bool UReactiveCollectionFloat::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<float>& UReactiveCollectionFloat::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionFloat::SetCollection(TArray<float> NewCollection)
{
	Collection = MoveTemp(NewCollection);
	OnCollectionChanged.Broadcast(Collection);
}

float UReactiveCollectionFloat::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionFloat::PushBack(float NewElement)
{
	Collection.Push(NewElement);
	OnCollectionChanged.Broadcast(Collection);
}

bool UReactiveCollectionFloat::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);
	OnCollectionChanged.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionFloat::TrySetValueByIndex(int32 Index, float NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	const auto OldValue = Collection[Index];
	Collection[Index] = NewElement;
	
	OnElementReplaced.Broadcast(Index, OldValue, NewElement);
	return true;
}

int32 UReactiveCollectionFloat::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionFloat::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();
	OnCollectionChanged.Broadcast(Collection);
}
