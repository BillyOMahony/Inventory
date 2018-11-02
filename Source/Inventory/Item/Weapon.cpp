// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


int32 AWeapon::GetWeaponDamage()
{
	return ItemData.WeaponStructure.WeaponDamage;
}

int32 AWeapon::GetWeaponRateOfFire()
{
	return ItemData.WeaponStructure.WeaponRateOfFire;
}

void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	this->ItemData.ItemCategory = EItemType::Weapon;
}

void AWeapon::UseItem()
{
}
