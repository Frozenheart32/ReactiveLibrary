/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyPawn.generated.h"

class APawn;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangePawnValue, APawn*, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangePawnValueCppDelegate, APawn*);


/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyPawn : public UObject
{
	GENERATED_BODY()

public:

	FOnChangePawnValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangePawnValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	APawn* Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] APawn* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(APawn* NewValue);
};


//--------------------------------------------------------------------------------------


UCLASS(NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyPawn : public UObject
{
	GENERATED_BODY()

public:

	FOnChangePawnValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangePawnValue OnValueChangedEvent;
	
private:

	UPROPERTY()
	TWeakObjectPtr<APawn> Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] APawn* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	void SetValue(APawn* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] bool IsValidPtr() const;
};
