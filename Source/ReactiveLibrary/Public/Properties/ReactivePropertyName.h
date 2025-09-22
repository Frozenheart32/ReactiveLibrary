/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyName.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeNameValue, const FName&, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyName : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyName();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeNameValue OnValueChanged;
	
private:

	UPROPERTY(EditDefaultsOnly)
	FName Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	const FName& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FName& NewValue);

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool IsNone() const;
};
