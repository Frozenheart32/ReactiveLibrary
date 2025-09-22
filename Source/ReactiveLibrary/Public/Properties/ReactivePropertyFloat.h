/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyFloat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeFloatValue, float, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyFloat : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyFloat();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeFloatValue OnValueChanged;
	
private:

	UPROPERTY(EditDefaultsOnly)
	float Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	float GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(float NewValue);
};
