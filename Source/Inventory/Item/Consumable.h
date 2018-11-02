// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "Consumable.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API AConsumable : public AItem
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	void UseItem() override;

	/*
	 *	Functionality for this method should be defined in blueprint
	 */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void UseConsumable();
};
