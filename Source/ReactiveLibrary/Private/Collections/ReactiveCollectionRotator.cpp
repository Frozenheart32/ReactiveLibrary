/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#include "Collections/ReactiveCollectionRotator.h"

bool UReactiveCollectionRotator::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<FRotator>& UReactiveCollectionRotator::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionRotator::SetCollection(TArray<FRotator> NewCollection)
{
	Collection = MoveTemp(NewCollection);
	OnCollectionChanged.Broadcast(Collection);
}

const FRotator& UReactiveCollectionRotator::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionRotator::PushBack(const FRotator& NewElement)
{
	Collection.Push(NewElement);
	OnCollectionChanged.Broadcast(Collection);
}

bool UReactiveCollectionRotator::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);
	
	OnCollectionChanged.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionRotator::TrySetValueByIndex(int32 Index, const FRotator& NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	const auto OldValue = Collection[Index];
	Collection[Index] = NewElement;
	
	OnElementReplaced.Broadcast(Index, OldValue, NewElement);
	return true;
}

int32 UReactiveCollectionRotator::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionRotator::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();
	OnCollectionChanged.Broadcast(Collection);
}
