// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Item/Item.h"
#include "StatsComponent.generated.h"

class AInventoryComponent;

USTRUCT(BlueprintType)
struct FStatsStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float HealthPoints = 50;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHealthPoints = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ShieldPoints = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxShieldPoints = 100;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FItemStructure EquippedWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FItemStructure EquippedArmor;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStatsComponent();

	/*
	 *	Sets the new equipped weapon and returns the old weapon to the inventory
	 *	@param EquippedWeapon - The new weapon which will be equipped
	 */
	void EquipWeapon(FItemStructure EquippedWeapon);

	/*
	 *	Sets the new equipped armor and returns the old weapon to the inventory
	 *	@param EquippedArmor - The new armor which will be equipped
	 */
	void EquipArmor(FItemStructure EquippedArmor);

	/*
	 *	Sets a new value for health points. Health cannot exceed MaxHealth.
	 *	@param ChangeInHealth - Value added to original HealthPoints
	 */
	UFUNCTION(BlueprintCallable)
	void SetNewHealthPoints(float ChangeInHealth);

	/*
	*	Sets a new value for shield points. Health cannot exceed MaxShield.
	*	@param ChangeInShield - Value added to original ShieldPoints
	*/
	UFUNCTION(BlueprintCallable)
	void SetNewShieldPoints(float ChangeInShield);

	/*
	 *	@return FStatsStruct the struct of stats for this actor component
	 */
	UFUNCTION(BlueprintCallable)
	FStatsStruct GetStatsStruct() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	FStatsStruct StatsStruct;
	
};
