// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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

	UE_LOG(LogTemp, Warning, TEXT("Spawning Item"));

	TSubclassOf<AItem> ItemToDrop = InventoryData[ItemIndex].ItemActor;

	FVector Location = FindFloor();
	FRotator Rotation = FRotator(0);

	GetWorld()->SpawnActor(ItemToDrop, &Location, &Rotation);

	InventoryData.RemoveAt(ItemIndex);
}

FVector UInventoryComponent::FindFloor()
{
	FHitResult HitResult;

	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerViewPointLocation, PlayerViewPointRotation);
	FVector RaycastLineEnd = PlayerViewPointLocation + FVector::UpVector * DropItemDistance * -1; // *-1 to get down vector

	FCollisionQueryParams TraceParams;

	GetWorld()->LineTraceSingleByChannel(
		HitResult,
		PlayerViewPointLocation,
		RaycastLineEnd,
		ECC_Visibility,
		TraceParams
	);

	if (HitResult.GetActor()) {
		UE_LOG(LogTemp, Warning, TEXT("%s"), *(HitResult.GetActor()->GetName()));
	}
	return HitResult.ImpactPoint;
}

