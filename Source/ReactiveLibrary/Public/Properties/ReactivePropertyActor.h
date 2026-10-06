/*
* Copyright (c) 2026 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyActor.generated.h"

class AActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeActorValue, AActor*, NewValue);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnChangeActorValueCppDelegate, AActor*);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyActor : public UObject
{
	GENERATED_BODY()

public:
	
	FOnChangeActorValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeActorValue OnValueChangedEvent;
	
private:

	UPROPERTY(EditDefaultsOnly)
	AActor* Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	[[nodiscard]] AActor* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(AActor* NewValue);
};


//-----------------------------------------------------------------------------------


UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyActor : public UObject
{
	GENERATED_BODY()

public:

	FOnChangeActorValueCppDelegate OnValueChanged;

protected:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property", DisplayName = "OnValueChanged")
	FOnChangeActorValue OnValueChangedEvent;
	
private:

	UPROPERTY()
	TWeakObjectPtr<AActor> Value = nullptr;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] AActor* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	void SetValue(AActor* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	[[nodiscard]] bool IsValidPtr() const;
};
