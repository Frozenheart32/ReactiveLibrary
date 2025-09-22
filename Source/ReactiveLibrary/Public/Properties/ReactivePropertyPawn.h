/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyPawn.generated.h"


class APawn;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangePawnValue, APawn*, NewValue);
/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyPawn : public UObject
{
	GENERATED_BODY()

public:
	
	UReactivePropertyPawn();

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnChangePawnValue OnValueChanged;
	
private:

	UPROPERTY()
	APawn* Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	APawn* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	bool SetValue(APawn* NewValue);
};


//--------------------------------------------------------------------------------------


UCLASS(NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UWeakReactivePropertyPawn : public UObject
{
	GENERATED_BODY()

public:
	
	UWeakReactivePropertyPawn();

	UPROPERTY(BlueprintAssignable, Category = "Weak Reactive Property")
	FOnChangePawnValue OnValueChanged;
	
private:

	UPROPERTY()
	TWeakObjectPtr<APawn> Value;

public:

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	APawn* GetValue() const;
	
	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool SetValue(APawn* NewValue);

	UFUNCTION(BlueprintCallable, Category = "Weak Reactive Property")
	bool IsValidPtr() const;
};
