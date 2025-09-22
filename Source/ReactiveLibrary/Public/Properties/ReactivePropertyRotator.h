/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyRotator.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeRotatorValue, const FRotator&, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyRotator : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyRotator();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeRotatorValue OnValueChanged;

private:

	UPROPERTY(EditDefaultsOnly)
	FRotator Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	const FRotator& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FRotator& NewValue);
	
};
