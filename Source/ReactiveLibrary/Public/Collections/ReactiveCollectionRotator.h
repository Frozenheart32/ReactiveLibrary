/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionRotator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeRotatorCollection, const TArray<FRotator>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReplaceRotatorElement, int32, ElementIndex, const FRotator&, NewElementValue);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeRotatorCollectionCppDelegate, const TArray<FRotator>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnReplaceRotatorElementCppDelegate, int32, const FRotator&);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionRotator : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeRotatorCollectionCppDelegate OnCollectionChanged;
	FOnReplaceRotatorElementCppDelegate OnElementReplaced;
	
protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnCollectionChanged")
	FOnChangeRotatorCollection OnCollectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnElementReplaced")
	FOnReplaceRotatorElement OnElementReplacedEvent;
	
private:

	UPROPERTY()
	TArray<FRotator> Collection;

	[[nodiscard]] bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const TArray<FRotator>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FRotator> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const FRotator& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(const FRotator& NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FRotator& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
