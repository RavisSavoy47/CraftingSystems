// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
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
	/// The current interactable the player is looking at
	/// </summary>
	UPROPERTY(BlueprintReadWrite,VisibleAnywhere)
	class AInteractable* CurrentInteractable;
};
