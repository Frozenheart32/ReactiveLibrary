/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyInt64.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeInt64Value, int64, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeInt64ValueCppDelegate, int64);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyInt64 : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeInt64ValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeInt64Value OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	int64 Value = 0L;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] int64 GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(int64 NewValue);
};