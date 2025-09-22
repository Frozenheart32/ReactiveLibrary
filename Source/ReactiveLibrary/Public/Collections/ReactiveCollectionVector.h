/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionVector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVectorCollection, const TArray<FVector>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnReplaceVectorElement, int32, ElementIndex, const FVector&, OldElementValue, const FVector&, NewElementValue);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionVector : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnChangeVectorCollection OnCollectionChanged;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnReplaceVectorElement OnElementReplaced;
	
private:

	UPROPERTY()
	TArray<FVector> Collection;

	bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const TArray<FVector>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FVector> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const FVector& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(const FVector& NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FVector& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
