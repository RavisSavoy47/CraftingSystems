// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayController.h"
#include "Interactable.h"
#include "Components/InputComponent.h"
#include "GameplayGameMode.h"
#include "Pickups.h"


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

	InputComponent->BindAction("Use", IE_Pressed, this, &AGameplayController::Interact);
}


void AGameplayController::AddItemToInventoryByID()
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
	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(itemID->GetID(), "", true);

	/// <summary>
	/// Adds the item to the inventory
	/// </summary>
	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}

}