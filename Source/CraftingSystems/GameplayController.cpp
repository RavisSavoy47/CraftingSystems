// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayController.h"
#include "Interactable.h"
#include "Components/InputComponent.h"
#include "GameplayGameMode.h"


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


void AGameplayController::AddItemToInventoryByID(FName ID)
{
	/// <summary>
	/// sets the gamemode to the worlds current gamemode
	/// </summary>
	/// <param name="ID">The id for the item that is added</param>
	AGameplayGameMode* GameMode = Cast<AGameplayGameMode>(GetWorld()->GetAuthGameMode());
	UDataTable* ItemTable = GameMode->GetItemDB();

	FInventoryItem* ItemToAdd = ItemTable->FindRow<FInventoryItem>(ID, "");

	if (ItemToAdd)
	{
		Inventory.Add(*ItemToAdd);
	}

}