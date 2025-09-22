/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyCharacter.generated.h"


class ACharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeCharacterValue, ACharacter*, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyCharacter : public UObject
{
	GENERATED_BODY()

public:
	
	UReactivePropertyCharacter();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeCharacterValue OnValueChanged;
	
private:

	UPROPERTY()
	ACharacter* Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	ACharacter* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool SetValue(ACharacter* NewValue);
};


//-----------------------------------------------------------------------------


UCLASS(NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyCharacter : public UObject
{
	GENERATED_BODY()

public:
	
	UWeakReactivePropertyCharacter();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeCharacterValue OnValueChanged;
	
private:

	UPROPERTY()
	TWeakObjectPtr<ACharacter> Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	ACharacter* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool SetValue(ACharacter* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool IsValidPtr() const;
};
