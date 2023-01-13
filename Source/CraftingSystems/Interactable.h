// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

UCLASS()
class CRAFTINGSYSTEMS_API AInteractable : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/// <summary>
	/// The function is called when the player interacts with an interactable
	/// </summary>
	UFUNCTION(BlueprintImplementableEvent)
	void Interact(AGameplayController* Controller);

	/// <summary>
	/// The name of the item
	/// </summary>
	UPROPERTY(EditDefaultsOnly)
	FString Name;

	/// <summary>
	/// What the item is used for
	/// </summary>
	UPROPERTY(EditDefaultsOnly)
	FString Action;

	/// <summary>
	/// Called when the item is used
	/// </summary>
	UFUNCTION(BlueprintCallable, Category = "Pickups")
	FString GetUseText() const { return FString::Printf(TEXT("%s : Press E to %s"), *Name, *Action); }
};
