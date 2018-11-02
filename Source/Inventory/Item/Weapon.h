// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item/Item.h"
#include "Weapon.generated.h"

UCLASS()
class INVENTORY_API AWeapon : public AItem
{
	GENERATED_BODY()

public:
	virtual void UseItem() override;

	/*
	 *	@return - The amount of damage this weapon does per shot
	 */
	int32 GetWeaponDamage();

	/*
	 *	@return - The number of shots per second this weapon fires
	 */
	int32 GetWeaponRateOfFire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
