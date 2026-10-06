/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyRotator.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeRotatorValue, const FRotator&, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeRotatorValueCppDelegate, const FRotator&);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyRotator : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeRotatorValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeRotatorValue OnValueChangedEvent;

private:

	UPROPERTY(EditDefaultsOnly)
	FRotator Value = {};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] const FRotator& GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(const FRotator& NewValue);
	
};
