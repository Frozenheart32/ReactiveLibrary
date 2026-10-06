/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyName.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeNameValue, const FName&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeNameValueCppDelegate, const FName&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyName : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeNameValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeNameValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	FName Value = NAME_None;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FName& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FName& NewValue);

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] bool IsNone() const;
};
