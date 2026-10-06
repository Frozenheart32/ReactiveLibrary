/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/
 
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyBool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeBoolValue, bool, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeBoolValueCppDelegate, bool);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyBool : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeBoolValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeBoolValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	bool Value = false;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] bool GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(bool NewValue);
};