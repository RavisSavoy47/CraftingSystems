// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayController.h"
#include "Interactable.h"
#include "Components/InputComponent.h"

void AGameplayController::Interact()
{
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
