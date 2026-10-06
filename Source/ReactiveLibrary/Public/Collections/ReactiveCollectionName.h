/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionName.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeNameCollection, const TArray<FName>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReplaceNameElement, int32, ElementIndex, const FName&, NewElementValue);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeNameCollectionCppDelegate, const TArray<FName>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnReplaceNameElementCppDelegate, int32, const FName&);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionName : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeNameCollectionCppDelegate OnCollectionChanged;
	FOnReplaceNameElementCppDelegate OnElementReplaced;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnCollectionChanged")
	FOnChangeNameCollection OnCollectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnElementReplaced")
	FOnReplaceNameElement OnElementReplacedEvent;
	
private:

	UPROPERTY()
	TArray<FName> Collection;

	[[nodiscard]] bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const TArray<FName>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FName> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const FName& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(const FName& NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FName& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
