// Fill out your copyright notice in the Description page of Project Settings.

#include "Armor.h"
#include "StatsComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

void AArmor::BeginPlay()
{
	Super::BeginPlay();
	this->ItemData.ItemCategory = EItemType::Armor;
}

int32 AArmor::GetArmorRating() const
{
	return ItemData.ArmorStructure.ArmorRating;
}

void AArmor::UseItem()
{
	EquipArmor();
	Destroy();
}

void AArmor::EquipArmor() const
{
	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	UStatsComponent * StatsComponent = PlayerController->GetCharacter()->FindComponentByClass<UStatsComponent>();
	if (StatsComponent)
	{
		StatsComponent->EquipArmor(ItemData);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AArmor::EquipArmor - Stats Component cannot be found"));
	}
}
