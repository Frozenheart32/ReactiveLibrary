/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyInt32.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeInt32Value, int32, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeInt32ValueCppDelegate, int32);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyInt32 : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeInt32ValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeInt32Value OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	int32 Value = 0;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] int32 GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(int32 NewValue);
};
