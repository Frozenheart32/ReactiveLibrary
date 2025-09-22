/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionVector.h"

bool UReactiveCollectionVector::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<FVector>& UReactiveCollectionVector::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionVector::SetCollection(TArray<FVector> NewCollection)
{
	Collection = MoveTemp(NewCollection);
	OnCollectionChanged.Broadcast(Collection);
}

const FVector& UReactiveCollectionVector::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionVector::PushBack(const FVector& NewElement)
{
	Collection.Push(NewElement);
	OnCollectionChanged.Broadcast(Collection);
}

bool UReactiveCollectionVector::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);
	
	OnCollectionChanged.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionVector::TrySetValueByIndex(int32 Index, const FVector& NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	const auto OldValue = Collection[Index];
	Collection[Index] = NewElement;
	
	OnElementReplaced.Broadcast(Index, OldValue, NewElement);
	return true;
}

int32 UReactiveCollectionVector::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionVector::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();
	OnCollectionChanged.Broadcast(Collection);
}
