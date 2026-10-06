/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/


#include "Collections/ReactiveCollectionActor.h"
#include "GameFramework/Actor.h"

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

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

AActor* UReactiveCollectionActor::GetElementByIndex(int32 Index) const
{
	check(!CheckOutOfRange(Index));
	return Collection[Index];
}

void UReactiveCollectionActor::PushBack(AActor* NewElement)
{
	Collection.Push(NewElement);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}

bool UReactiveCollectionActor::TryRemoveElementByIndex(int32 Index)
{
	if(CheckOutOfRange(Index)) return false;

	AActor* Element = Collection[Index];
	Collection.Remove(Element);

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
	return true;
}

bool UReactiveCollectionActor::TrySetValueByIndex(int32 Index, AActor* NewElement)
{
	if(CheckOutOfRange(Index)) return false;

	if(Collection[Index] == NewElement) return false;
	
	Collection[Index] = NewElement;

	if(OnElementReplaced.IsBound())
		OnElementReplaced.Broadcast(Index, NewElement);

	OnElementReplacedEvent.Broadcast(Index, NewElement);
	
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

	if(OnCollectionChanged.IsBound())
		OnCollectionChanged.Broadcast(Collection);

	OnCollectionChangedEvent.Broadcast(Collection);
}
