// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Pickups.generated.h"

/**
 * 
 */
UCLASS()
class CRAFTINGSYSTEMS_API APickups : public AInteractable
{
	GENERATED_BODY()

public:

	/// <summary>
	/// The constructor
	/// </summary>
	APickups();

	/// <summary>
	/// the items id
	/// </summary>
	UPROPERTY(EditAnywhere)
	FName ItemID;

	/// <summary>
	/// Gets the id of the item
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	FName GetID() { return ItemID; }

protected:
	/// <summary>
	/// The mesh of the item
	/// </summary>
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	
};
