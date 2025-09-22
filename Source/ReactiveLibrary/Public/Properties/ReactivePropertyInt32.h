/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyInt32.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeInt32Value, int32, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyInt32 : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyInt32();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeInt32Value OnValueChanged;
	
private:

	UPROPERTY(EditDefaultsOnly)
	int32 Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	int32 GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(int32 NewValue);
};
