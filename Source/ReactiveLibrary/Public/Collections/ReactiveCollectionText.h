/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionText.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTextCollection, const TArray<FText>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReplaceTextElement, int32, ElementIndex, const FText&, NewElementValue);

DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeTextCollectionCppDelegate, const TArray<FText>&);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnReplaceTextElementCppDelegate, int32, const FText&);


inline bool operator==(const FText& Lhs, const FText& Rhs)
{
	return Lhs.EqualTo(Rhs);
}

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionText : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeTextCollectionCppDelegate OnCollectionChanged;
	FOnReplaceTextElementCppDelegate OnElementReplaced;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnCollectionChanged")
	FOnChangeTextCollection OnCollectionChangedEvent;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection", DisplayName = "OnElementReplaced")
	FOnReplaceTextElement OnElementReplacedEvent;
	
private:

	UPROPERTY()
	TArray<FText> Collection;

	[[nodiscard]] bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const TArray<FText>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FText> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] const FText& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(FText NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FText& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	[[nodiscard]] int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
