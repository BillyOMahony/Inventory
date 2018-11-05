// Fill out your copyright notice in the Description page of Project Settings.

#include "Armor.h"

void AArmor::BeginPlay()
{
	Super::BeginPlay();
	this->ItemData.ItemCategory = EItemType::Armor;
}

int32 AArmor::GetArmorRating() const
{
	return ItemData.ArmorStructure.ArmorRating;
}
