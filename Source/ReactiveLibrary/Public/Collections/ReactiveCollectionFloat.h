/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionFloat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeFloatCollection, const TArray<float>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnReplaceFloatElement, int32, ElementIndex, float, OldElementValue, float, NewElementValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionFloat : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnChangeFloatCollection OnCollectionChanged;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnReplaceFloatElement OnElementReplaced;
	
private:

	UPROPERTY()
	TArray<float> Collection;

	bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const TArray<float>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<float> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	float GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(float NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, float NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
