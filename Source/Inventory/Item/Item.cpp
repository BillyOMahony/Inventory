// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Engine/World.h"
#include "InventoryComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(FName("Scene"));
	SetRootComponent(Scene);

	ItemMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("ItemMeshComponent"));
	ItemMeshComponent->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	ItemMeshComponent->SetupAttachment(Scene);
	ItemMeshComponent->SetCollisionProfileName("IgnoreOnlyPawn");

	InteractText = CreateDefaultSubobject<UChildActorComponent>(FName("Interact Text"));
	InteractText->AttachToComponent(Scene, FAttachmentTransformRules::KeepRelativeTransform);
	InteractText->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	if (InteractText) InteractText->SetVisibility(false);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnInteract_Implementation(AActor * Caller)
{
	UInventoryComponent * InventoryComponent = Caller->FindComponentByClass<UInventoryComponent>();
	if(InventoryComponent)
	{
		InventoryComponent->AddItem(ItemData);
	}

	// Destroy this actor after it has been picked up
	Destroy(this);
}

void AItem::StartFocus_Implementation()
{
	if(InteractText) InteractText->SetVisibility(true);
}

void AItem::EndFocus_Implementation()
{
	if (InteractText) InteractText->SetVisibility(false);
}

FItemStructure AItem::GetItemData() const
{
	return ItemData;
}

void AItem::SetInteractText(UChildActorComponent * InteractText)
{
	this->InteractText = InteractText;
}

void AItem::UseItem()
{
}

