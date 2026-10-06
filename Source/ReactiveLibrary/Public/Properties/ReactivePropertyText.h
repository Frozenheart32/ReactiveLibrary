/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyText.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTextValue, const FText&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeTextValueCppDelegate, const FText&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyText : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeTextValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeTextValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	FText Value = {};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FText& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FText& NewValue);

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] bool IsEmpty() const;
};
