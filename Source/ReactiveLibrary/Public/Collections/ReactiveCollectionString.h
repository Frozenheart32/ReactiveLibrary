/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactiveCollectionString.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeStringCollection, const TArray<FString>&, ChangedCollection);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnReplaceStringElement, int32, ElementIndex, const FString&, OldElementValue, const FString&, NewElementValue);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactiveCollectionString : public UObject
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnChangeStringCollection OnCollectionChanged;
	UPROPERTY(BlueprintAssignable, Category = "Reactive Collection")
	FOnReplaceStringElement OnElementReplaced;
	
private:

	UPROPERTY()
	TArray<FString> Collection;

	bool CheckOutOfRange(int32 Index) const;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const TArray<FString>& GetCollection() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void SetCollection(TArray<FString> NewCollection);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	const FString& GetElementByIndex(int32 Index) const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void PushBack(FString NewElement);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TryRemoveElementByIndex(int32 Index);
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	bool TrySetValueByIndex(int32 Index, const FString& NewElement);

	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	int32 Num() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Collection")
	void ClearCollection();
};
