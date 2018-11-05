// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "Armor.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API AArmor : public AItem
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	/*
	 *	@return - this piece of armor's rating
	 */
	int32 GetArmorRating() const;
	
	
};
