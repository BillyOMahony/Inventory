// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include "StatsComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

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
	EquipWeapon();
	Destroy();
}

void AWeapon::EquipWeapon() const
{
	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	UStatsComponent * StatsComponent = PlayerController->GetCharacter()->FindComponentByClass<UStatsComponent>();
	if (StatsComponent)
	{
		StatsComponent->EquipWeapon(ItemData);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AWeapon::EquipWeapon- Stats Component cannot be found"));
	}
}
