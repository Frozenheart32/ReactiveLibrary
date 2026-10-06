/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionVector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVectorCollection, const TArray<FVector>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReplaceVectorElement, int32, ElementIndex, const FVector&, NewElementValue);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeVectorCollectionCppDelegate, const TArray<FVector>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnReplaceVectorElementCppDelegate, int32, const FVector&);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionVector : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeVectorCollectionCppDelegate OnCollectionChanged;
	FOnReplaceVectorElementCppDelegate OnElementReplaced;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnCollectionChanged")
	FOnChangeVectorCollection OnCollectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnElementReplaced")
	FOnReplaceVectorElement OnElementReplacedEvent;
	
private:

	UPROPERTY()
	TArray<FVector> Collection;

	[[nodiscard]] bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const TArray<FVector>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FVector> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const FVector& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(const FVector& NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FVector& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
