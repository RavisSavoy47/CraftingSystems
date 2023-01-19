// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayController.h"
#include "Interactable.h"
#include "Components/InputComponent.h"
#include "GameplayGameMode.h"
#include "Pickups.h"


void AGameplayController::CraftItem(FInventoryItem ItemA, FInventoryItem ItemB, AGameplayController* Controller)
{

	//checks the craft combinations for the item ids
	for (auto Craft : ItemB.CraftCombinations)
	{
		//checks the item ids match and crafts the new object
		if (Craft.ComponentID == ItemA.ItemID)
		{
			//removes itemA 
			if (Craft.bDestroyItemA)
			{
				Inventory.RemoveSingle(ItemA);
			}
			//removes itemb
			if (Craft.bDestroyItemB)
			{
				Inventory.RemoveSingle(ItemB);
			}
			//then adds the product to the inventory
			AddItemToInventoryByID(Craft.ProductID);
			//reloads the inventory
			ReloadInventory();
		}
	}

}

void AGameplayController::Interact()
{
	/// <summary>
	/// If its an interactable interacts with that object
	/// </summary>
	if (CurrentInteractable)
	{
		CurrentInteractable->Interact(this);
	}
}

void AGameplayController::SetupInputComponent()
{
	Super::SetupInputComponent();
	/// <summary>
	/// Sets the use button to the controller
	/// </summary>
	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}


void AGameplayController::AddItemToInventoryByID(FName ID)
{
	/// <summary>
	/// sets the gamemode to the worlds current gamemode
	/// </summary>
	/// <param name="ID">The id for the item that is added</param>
	AGameplayGameMode* GameMode = Cast<AGameplayGameMode>(GetWorld()->GetAuthGameMode());
	/// <summary>
	/// Gets the data table from the gamemode
	/// </summary>
	UDataTable* ItemTable = GameMode->GetItemDB();
	
	/// <summary>
	/// gets the items id from the current item
	/// </summary>
	APickups* itemID = Cast<APickups>(CurrentInteractable);

	/// <summary>
	/// Finds the row in the data table for that item
	/// </summary>
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "", true);

	/// <summary>
	/// Adds the item to the inventory
	/// </summary>
	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}

}