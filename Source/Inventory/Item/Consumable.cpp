// Fill out your copyright notice in the Description page of Project Settings.

#include "Consumable.h"


void AConsumable::BeginPlay()
{
	Super::BeginPlay();

	ItemData.ItemCategory = EItemType::Consumable;
}

void AConsumable::UseItem()
{
	UseConsumable();
}

void AConsumable::UseConsumable_Implementation()
{
	
}
