/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionActor.generated.h"

class AActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeActorCollection, const TArray<AActor*>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnReplaceActorElement, int32, ElementIndex, AActor*, OldElementValue, AActor*, NewElementValue);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionActor : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnChangeActorCollection OnCollectionChanged;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnReplaceActorElement OnElementReplaced;
	
private:

	UPROPERTY()
	TArray<AActor*> Collection;

	bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const TArray<AActor*>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<AActor*> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	AActor* GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(AActor* NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, AActor* NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
