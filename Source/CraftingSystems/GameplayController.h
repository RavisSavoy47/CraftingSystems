// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CraftingSystemsCharacter.h"
#include "GameplayController.generated.h"

/**
 * 
 */
UCLASS()
class CRAFTINGSYSTEMS_API AGameplayController : public APlayerController
{
	GENERATED_BODY()
	
public:
	
	/// <summary>
	/// Reloads the player's inventory 
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
	void ReloadInventory();

	/// <summary>
	/// Puts the item in the players inventory using its ID
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Utilties")
	void AddItemToInventoryByID(FName ID);
	/// <summary>
	/// Crafts the item by using 2 items to create a new one
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Utilties")
	void CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGameplayController* Controller);

	/// <summary>
	/// The current interactable the player is looking at
	/// </summary>
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	class AInteractable* CurrentInteractable;

	/// <summary>
	/// The inventory
	/// </summary>
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<FInventoryItem> Inventory;

protected:

	/// <summary>
	/// Interacts with any interactable
	/// </summary>
	void Interact();

	/// <summary>
	/// Sets new inputs for the player
	/// </summary>
	virtual void SetupInputComponent() override;

};
