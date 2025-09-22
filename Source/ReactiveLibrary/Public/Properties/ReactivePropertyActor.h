/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyActor.generated.h"


class AActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangeActorValue, AActor*, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyActor : public UObject
{
	GENERATED_BODY()

public:

	UReactivePropertyActor();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangeActorValue OnValueChanged;
	
private:

	UPROPERTY()
	AActor* Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	AActor* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool SetValue(AActor* NewValue);
};


//-----------------------------------------------------------------------------------


UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyActor : public UObject
{
	GENERATED_BODY()

public:

	UWeakReactivePropertyActor();

	UPROPERTY(BlueprintAssignable, Category = "Weak Reactive Property")
	FOnChangeActorValue OnValueChanged;
	
private:

	UPROPERTY()
	TWeakObjectPtr<AActor> Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	AActor* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool SetValue(AActor* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool IsValidPtr() const;
};
