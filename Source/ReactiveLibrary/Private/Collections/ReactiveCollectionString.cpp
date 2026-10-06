/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionString.h"

bool UReactiveCollectionString::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<FString>& UReactiveCollectionString::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionString::SetCollection(TArray<FString> NewCollection)
{
	Collection = MoveTemp(NewCollection);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

const FString& UReactiveCollectionString::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionString::PushBack(FString NewElement)
{
	Collection.Push(MoveTemp(NewElement));

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionString::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionString::TrySetValueByIndex(int32 Index, const FString& NewElement)
{
	if(CheckOutOfRange(Index)) return false;
	
	Collection[Index] = NewElement;

	if(OnElementReplaced.IsBound())
		OnElementReplaced.Broadcast(Index, NewElement);

	OnElementReplacedEvent.Broadcast(Index, NewElement);
	return true;
}

int32 UReactiveCollectionString::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionString::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}
