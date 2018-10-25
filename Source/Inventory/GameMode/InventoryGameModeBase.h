// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Item/Item.h"
#include "InventoryGameModeBase.generated.h"

USTRUCT(BlueprintType)
struct FColorScheme
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString SchemeName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor PrimaryColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor SecondaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FColor TextColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemRarity ItemRarity;
};

/**
 * 
 */
UCLASS()
class INVENTORY_API AInventoryGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TArray<FColorScheme> ColorSchemes;

public:
	UFUNCTION(BlueprintCallable)
	FColorScheme GetColorScheme(EItemRarity Rarity);
	
};
