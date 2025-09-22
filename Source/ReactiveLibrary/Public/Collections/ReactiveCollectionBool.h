/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionBool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeBoolCollection, const TArray<bool>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnReplaceBoolElement, int32, ElementIndex, bool, OldElementValue, bool, NewElementValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionBool : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnChangeBoolCollection OnCollectionChanged;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnReplaceBoolElement OnElementReplaced;
	
private:

	UPROPERTY()
	TArray<bool> Collection;

	bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const TArray<bool>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<bool> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(bool NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, bool NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
