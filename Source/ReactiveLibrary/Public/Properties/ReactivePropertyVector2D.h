/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyVector2D.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVector2DValue, const FVector2D&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeVector2DValueCppDelegate, const FVector2D&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyVector2D : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeVector2DValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeVector2DValue OnValueChangedEvent;

private:

	UPROPERTY(EditDefaultsOnly)
	FVector2D Value = {};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FVector2D& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FVector2D& NewValue);
};
