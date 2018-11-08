// Fill out your copyright notice in the Description page of Project Settings.

#include "StatsComponent.h"
#include "InventoryComponent.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UStatsComponent::UStatsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UStatsComponent::EquipWeapon(FItemStructure EquippedWeapon)
{
	if(EquippedWeapon.ItemCategory!=EItemType::Weapon)
	{
		UE_LOG(LogTemp, Error, TEXT("UStatsComponent::EquipWeapon - EquippedWeapon is not of type Weapon"));
		return;
	}

	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	UInventoryComponent * InventoryComponent = PlayerController->GetCharacter()->FindComponentByClass<UInventoryComponent>();
	if(InventoryComponent)
	{
		if (StatsStruct.EquippedWeapon.ItemActor) {
			InventoryComponent->AddItem(StatsStruct.EquippedWeapon);
		}
		StatsStruct.EquippedWeapon = EquippedWeapon;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UStatsComponent::EquipWeapon - Inventory Component cannot be found"));
	}
}

void UStatsComponent::EquipArmor(FItemStructure EquippedArmor)
{
	if (EquippedArmor.ItemCategory != EItemType::Armor)
	{
		UE_LOG(LogTemp, Error, TEXT("UStatsComponent::EquipArmor - EquippedArmor is not of type Armor"));
		return;
	}

	APlayerController * PlayerController = GetWorld()->GetFirstPlayerController();
	UInventoryComponent * InventoryComponent = PlayerController->GetCharacter()->FindComponentByClass<UInventoryComponent>();
	if (InventoryComponent)
	{
		if (StatsStruct.EquippedArmor.ItemActor) {
			InventoryComponent->AddItem(StatsStruct.EquippedArmor);
		}
		StatsStruct.EquippedArmor = EquippedArmor;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("UStatsComponent::EquipArmor - Inventory Component cannot be found"));
	}
}

void UStatsComponent::SetNewHealthPoints(float ChangeInHealth)
{
	StatsStruct.HealthPoints += ChangeInHealth;
	if(StatsStruct.HealthPoints > StatsStruct.MaxHealthPoints)
	{
		StatsStruct.HealthPoints = StatsStruct.MaxHealthPoints;
	}
}

void UStatsComponent::SetNewShieldPoints(float ChangeInShield)
{
	StatsStruct.ShieldPoints += ChangeInShield;
	if(StatsStruct.ShieldPoints > StatsStruct.MaxShieldPoints)
	{
		StatsStruct.ShieldPoints = StatsStruct.MaxShieldPoints;
	}
}

FStatsStruct UStatsComponent::GetStatsStruct() const
{
	return StatsStruct;
}

// Called when the game starts
void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

