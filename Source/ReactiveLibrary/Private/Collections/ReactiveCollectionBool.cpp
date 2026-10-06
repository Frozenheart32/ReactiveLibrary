/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionBool.h"

bool UReactiveCollectionBool::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<bool>& UReactiveCollectionBool::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionBool::SetCollection(TArray<bool> NewCollection)
{
	Collection = MoveTemp(NewCollection);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionBool::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionBool::PushBack(bool NewElement)
{
	Collection.Push(NewElement);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionBool::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionBool::TrySetValueByIndex(int32 Index, bool NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	if(Collection[Index] == NewElement) return false;
	
	Collection[Index] = NewElement;

	if(OnElementReplaced.IsBound())
		OnElementReplaced.Broadcast(Index, NewElement);

	OnElementReplacedEvent.Broadcast(Index, NewElement);
	return true;
}

int32 UReactiveCollectionBool::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionBool::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}
