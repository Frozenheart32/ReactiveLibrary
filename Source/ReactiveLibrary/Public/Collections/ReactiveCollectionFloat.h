/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionFloat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeFloatCollection, const TArray<float>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReplaceFloatElement, int32, ElementIndex, float, NewElementValue);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeFloatCollectionCppDelegate, const TArray<float>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnReplaceFloatElementCppDelegate, int32, float);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionFloat : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeFloatCollectionCppDelegate OnCollectionChanged;
	FOnReplaceFloatElementCppDelegate OnElementReplaced;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnCollectionChanged")
	FOnChangeFloatCollection OnCollectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnElementReplaced")
	FOnReplaceFloatElement OnElementReplacedEvent;
	
private:

	UPROPERTY()
	TArray<float> Collection;

	[[nodiscard]] bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const TArray<float>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<float> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] float GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(float NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, float NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
