// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/item.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	TArray<FItemStructure> GetInventory();

	/*
	 *	Adds an item to InventoryData
	 *	@param Item - the item to add
	 */
	UFUNCTION(BlueprintCallable)
	void AddItem(FItemStructure Item);

	/*
	 *	Spawns the ItemActor associated with the item at index ItemIndex
	 *	Removes the item at index ItemIndex from the InventoryData array
	 *	@param ItemIndex - The index of the item which will be spawned and removed
	 */
	UFUNCTION(BlueprintCallable)
	void DropItem(int ItemIndex);

private:
	UPROPERTY(VisibleAnywhere)
	TArray<FItemStructure> InventoryData;

	UPROPERTY(EditAnywhere)
	float DropItemDistance = 500.f;

	FVector FindFloor();
};
