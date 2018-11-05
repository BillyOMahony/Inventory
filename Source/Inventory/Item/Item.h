// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable/Interactable.h"
#include "Item.generated.h"

class UParticleSystemComponent;
class AItem;

UENUM(BlueprintType)
enum class EItemRarity : uint8 {
	Common UMETA(DisplayName = "Common"),
	Uncommon UMETA(DisplayName = "Uncommon"),
	Rare UMETA(DisplayName = "Rare")
};

UENUM(BlueprintType)
enum class EItemType : uint8 {
	Weapon UMETA(DisplayName = "Weapon"),
	Armor UMETA(DisplayName = "Armor"),
	Consumable UMETA(DisplayName = "Consumable")
};

USTRUCT(BlueprintType)
struct FWeaponStructure
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 WeaponDamage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 WeaponRateOfFire;
};

USTRUCT(BlueprintType)
struct FArmorStructure
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 ArmorRating;
};


USTRUCT(BlueprintType)
struct FItemStructure
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D * ItemTexture;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemType ItemCategory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EItemRarity ItemRarity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AItem> ItemActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FWeaponStructure WeaponStructure;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FArmorStructure ArmorStructure;
};

UCLASS()
class INVENTORY_API AItem : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void OnInteract(AActor* Caller);
	virtual void OnInteract_Implementation(AActor* Caller) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void StartFocus();
	virtual void StartFocus_Implementation() override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interaction")
	void EndFocus();
	virtual void EndFocus_Implementation() override;

	/*
	 *	@returns ItemData, the structure containing data of this item
	 */
	UFUNCTION(BlueprintCallable)
	FItemStructure GetItemData() const;

	/*
	 *	TODO Document
	 */
	UFUNCTION(BlueprintCallable)
	void SetInteractText(UChildActorComponent * InteractText);

	UFUNCTION(BlueprintCallable)
	virtual void UseItem();

protected:
	UPROPERTY(EditAnywhere, Category = "Item Data")
	FItemStructure ItemData;

private:
	USceneComponent * Scene;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent * ItemMeshComponent;

	UPROPERTY(VisibleAnywhere)
	UChildActorComponent * InteractText;
};
