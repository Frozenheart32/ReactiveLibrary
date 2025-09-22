/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyVector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeVectorValue, const FVector&, NewValue);
/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyVector : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyVector();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeVectorValue OnValueChanged;

private:

	UPROPERTY(EditDefaultsOnly)
	FVector Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	const FVector& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FVector& NewValue);
};
