// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<FItemStructure> UInventoryComponent::GetInventory()
{
	return InventoryData;
}

void UInventoryComponent::AddItem(FItemStructure Item)
{
	InventoryData.Add(Item);
}

void UInventoryComponent::DropItem(int ItemIndex)
{
	if (InventoryData.Num() - 1 < ItemIndex) return; // This index is out of bounds

	TSubclassOf<AItem> ItemToDrop = InventoryData[ItemIndex].ItemActor;

	FVector Location = GetOwner()->GetActorLocation();
	FRotator Rotation = GetOwner()->GetActorRotation();

	GetWorld()->SpawnActor(ItemToDrop, &Location, &Rotation);

	InventoryData.RemoveAt(ItemIndex);
}

