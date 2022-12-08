// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CraftingSystemsHUD.generated.h"

UCLASS()
class ACraftingSystemsHUD : public AHUD
{
	GENERATED_BODY()

public:
	ACraftingSystemsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

