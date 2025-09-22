/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/
 
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyBool.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeBoolValue, bool, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyBool : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyBool();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeBoolValue OnValueChanged;
	
private:

	UPROPERTY(EditDefaultsOnly)
	bool Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(bool NewValue);
};