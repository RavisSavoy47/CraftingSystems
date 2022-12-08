// Copyright Epic Games, Inc. All Rights Reserved.

#include "CraftingSystemsGameMode.h"
#include "CraftingSystemsHUD.h"
#include "CraftingSystemsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACraftingSystemsGameMode::ACraftingSystemsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACraftingSystemsHUD::StaticClass();
}
