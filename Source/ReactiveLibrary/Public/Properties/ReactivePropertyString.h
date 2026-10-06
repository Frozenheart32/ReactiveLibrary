/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyString.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeStringValue, const FString&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeStringValueCppDelegate, const FString&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyString : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeStringValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeStringValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	FString Value = {};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FString& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FString& NewValue);

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] int32 Length() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] bool IsEmpty() const;
};
