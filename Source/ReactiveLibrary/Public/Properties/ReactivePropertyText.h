/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyText.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeTextValue, const FText&, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyText : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyText();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeTextValue OnValueChanged;
	
private:

	UPROPERTY(EditDefaultsOnly)
	FText Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	const FText& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FText& NewValue);

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool IsEmpty() const;
};
