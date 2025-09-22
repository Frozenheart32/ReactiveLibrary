/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionActor.h"

bool UReactiveCollectionActor::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<AActor*>& UReactiveCollectionActor::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionActor::SetCollection(TArray<AActor*> NewCollection)
{
	Collection = MoveTemp(NewCollection);
	OnCollectionChanged.Broadcast(Collection);
}

AActor* UReactiveCollectionActor::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionActor::PushBack(AActor* NewElement)
{
	Collection.Push(NewElement);
	OnCollectionChanged.Broadcast(Collection);
}

bool UReactiveCollectionActor::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	AActor* Element = Collection[Index];
	Collection.Remove(Element);
	
	OnCollectionChanged.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionActor::TrySetValueByIndex(int32 Index, AActor* NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	const auto OldValue = Collection[Index];
	Collection[Index] = NewElement;
	
	OnElementReplaced.Broadcast(Index, OldValue, NewElement);
	return true;
}

int32 UReactiveCollectionActor::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionActor::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();
	OnCollectionChanged.Broadcast(Collection);
}
