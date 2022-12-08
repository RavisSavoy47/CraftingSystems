// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickups.h"

APickups::APickups() 
{
	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");

	ItemID = FName("Please enter an ID");
}