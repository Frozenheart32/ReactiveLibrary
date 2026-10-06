/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionName.h"

bool UReactiveCollectionName::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<FName>& UReactiveCollectionName::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionName::SetCollection(TArray<FName> NewCollection)
{
	Collection = MoveTemp(NewCollection);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

const FName& UReactiveCollectionName::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionName::PushBack(const FName& NewElement)
{
	Collection.Push(NewElement);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionName::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionName::TrySetValueByIndex(int32 Index, const FName& NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	if(Collection[Index].Compare(NewElement)) return false;
	Collection[Index] = NewElement;

	if(OnElementReplaced.IsBound())
		OnElementReplaced.Broadcast(Index, NewElement);

	OnElementReplacedEvent.Broadcast(Index, NewElement);
	return true;
}

int32 UReactiveCollectionName::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionName::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}
