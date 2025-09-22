/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionText.h"

bool UReactiveCollectionText::CheckOutOfRange(int32 Index) const
{
	return Index >= Collection.Num();
}

const TArray<FText>& UReactiveCollectionText::GetCollection() const
{
	return Collection;
}

void UReactiveCollectionText::SetCollection(TArray<FText> NewCollection)
{
	Collection = MoveTemp(NewCollection);
	OnCollectionChanged.Broadcast(Collection);
}

const FText& UReactiveCollectionText::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionText::PushBack(FText NewElement)
{
	Collection.Push(MoveTemp(NewElement));
	OnCollectionChanged.Broadcast(Collection);
}

bool UReactiveCollectionText::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	const auto& Element = Collection[Index];
	Collection.Remove(Element);
	
	OnCollectionChanged.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionText::TrySetValueByIndex(int32 Index, const FText& NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	const auto OldValue = Collection[Index];
	Collection[Index] = NewElement;
	
	OnElementReplaced.Broadcast(Index, OldValue, NewElement);
	return true;
}

int32 UReactiveCollectionText::Num() const
{
	return Collection.Num();
}

void UReactiveCollectionText::ClearCollection()
{
	if(Collection.IsEmpty()) return;

	Collection.Empty();
	OnCollectionChanged.Broadcast(Collection);
}
