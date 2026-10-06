/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyCharacter.generated.h"

class ACharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeCharacterValue, ACharacter*, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeCharacterValueCppDelegate, ACharacter*);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyCharacter : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeCharacterValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeCharacterValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	ACharacter* Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] ACharacter* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(ACharacter* NewValue);
};


//-----------------------------------------------------------------------------


UCLASS(NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyCharacter : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeCharacterValueCppDelegate OnValueChanged;
	
protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeCharacterValue OnValueChangedEvent;
	
private:

	UPROPERTY()
	TWeakObjectPtr<ACharacter> Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] ACharacter* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	void SetValue(ACharacter* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] bool IsValidPtr() const;
};
