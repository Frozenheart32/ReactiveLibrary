/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyVector2D.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVector2DValue, const FVector2D&, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyVector2D : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyVector2D();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeVector2DValue OnValueChanged;

private:

	UPROPERTY(EditDefaultsOnly)
	FVector2D Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	const FVector2D& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FVector2D& NewValue);
};
