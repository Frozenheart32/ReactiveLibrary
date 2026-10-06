/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyFloat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeFloatValue, float, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeFloatValueCppDelegate, float);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyFloat : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeFloatValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeFloatValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	float Value = 0.f;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] float GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(float NewValue);
};
