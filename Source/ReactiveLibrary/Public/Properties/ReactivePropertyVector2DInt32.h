/*
* Copyright (c) 2025 Alexsander Khrapin
* Licensed under the MIT License. See LICENSE in the project root for license information.
*/

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ReactivePropertyVector2DInt32.generated.h"


USTRUCT(BlueprintType)
struct FVector2DInt32
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 X = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Y = 0;
};

inline bool operator==(const FVector2DInt32& Lhs, const FVector2DInt32& Rhs)
{
	return Lhs.X == Rhs.X && Lhs.Y == Rhs.Y;
}

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVector2DInt32ValueChanged, const FVector2DInt32&, NewValue);

/**
 * 
 */
UCLASS(EditInlineNew, DefaultToInstanced, NotBlueprintable, BlueprintType)
class REACTIVELIBRARY_API UReactivePropertyVector2DInt32 : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable, Category = "Reactive Property")
	FOnVector2DInt32ValueChanged OnValueChanged;

private:

	UPROPERTY(EditDefaultsOnly)
	FVector2DInt32 Value = FVector2DInt32{};

public:

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	FVector2DInt32 GetValue() const;

	UFUNCTION(BlueprintCallable, Category = "Reactive Property")
	void SetValue(FVector2DInt32 NewValue);
};
