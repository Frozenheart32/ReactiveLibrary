/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyVector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVectorValue, const FVector&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeVectorValueCppDelegate, const FVector&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyVector : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeVectorValueCppDelegate OnValueChanged;

protected:
	
	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeVectorValue OnValueChangedEvent;

private:

	UPROPERTY(EditDefaultsOnly)
	FVector Value = {};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FVector& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FVector& NewValue);
};
