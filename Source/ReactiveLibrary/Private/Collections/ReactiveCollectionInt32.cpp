/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionInt32.h"


bool UReactiveCollectionInt32::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<int32>& UReactiveCollectionInt32::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionInt32::SetCollection(TArray<int32> NewCollection)
{
	Collection = MoveTemp(NewCollection);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

int32 UReactiveCollectionInt32::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionInt32::PushBack(int32 NewElement)
{
	Collection.Push(NewElement);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionInt32::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionInt32::TrySetValueByIndex(int32 Index, int32 NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	if(Collection[Index] == NewElement) return  false;
	
	Collection[Index] = NewElement;

	if(OnElementReplaced.IsBound())
		OnElementReplaced.Broadcast(Index, NewElement);

	OnElementReplacedEvent.Broadcast(Index, NewElement);
	return true;
}

int32 UReactiveCollectionInt32::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionInt32::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}
