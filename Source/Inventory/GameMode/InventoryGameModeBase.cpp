// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryGameModeBase.h"

FColorScheme AInventoryGameModeBase::GetColorScheme(EItemRarity Rarity)
{
	for (uint8 i = 0; i < ColorSchemes.Num(); i++)
	{
		if(ColorSchemes[i].ItemRarity == Rarity)
		{
			return ColorSchemes[i];
		}
	}

	// If the colorscheme for the requested rarity does not exist just return the first one
	UE_LOG(LogTemp, Error, TEXT("Cannot find color scheme"));
	return ColorSchemes[0];
}
