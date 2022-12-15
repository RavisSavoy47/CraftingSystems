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

	UPROPERTY(EditAnywhere)
	FName ItemID;

	UFUNCTION(BlueprintCallable, Category = "Pickups")
	FName GetID() { return ItemID; }

protected:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	
};
