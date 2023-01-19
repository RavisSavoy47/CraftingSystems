// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "CraftingSystemsCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UMotionControllerComponent;
class UAnimMontage;
class USoundBase;

USTRUCT(BlueprintType)
struct FCraftingInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	/// <summary>
	/// The items id for each component
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ComponentID;
	/// <summary>
	/// The id of the product 
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ProductID;

	/// <summary>
	/// Removes the first item
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDestroyItemA;

	/// <summary>
	/// Removes the second item
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bDestroyItemB;
};

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

public:
	/// <summary>
	/// The base values of each item
	/// </summary>
	FInventoryItem()
	{
		Name = FText::FromString("Item");
		Action = FText::FromString("Use");
		Description = FText::FromString("Please enter a description for this item");
		Value = 10;
	}

	/// <summary>
	/// The ID for the item
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName ItemID;

	/// <summary>
	/// Gets the item that is a pickup
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class APickups> ItemPickup;

	/// <summary>
	/// The Name of the item
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;

	/// <summary>
	/// The action the item is used for
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Action;

	/// <summary>
	/// How much it would cost to craft
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Value;

	/// <summary>
	/// The display image for the item
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Thumbnail;

	/// <summary>
	/// Descrides what the item is and what it can do
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Description;

	/// <summary>
	/// What it takes to craft
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<FCraftingInfo> CraftCombinations;

	/// <summary>
	/// If the item is a usable or not
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanbeUsed;

	/// <summary>
	/// Checks if the items iD matches an item id in the inventory
	/// </summary>
	/// <param name="Item">The current item</param>
	/// <returns>if the items id is the same or not</returns>
	bool operator==(const FInventoryItem& Item) const
	{
		if (ItemID == Item.ItemID)
			return true;
		else return false;
	}
};

UCLASS(config=Game)
class ACraftingSystemsCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category=Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USceneComponent* FP_MuzzleLocation;

	/** Gun mesh: VR view (attached to the VR controller directly, no arm, just the actual gun) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* VR_Gun;

	/** Location on VR gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USceneComponent* VR_MuzzleLocation;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UMotionControllerComponent* L_MotionController;

public:
	ACraftingSystemsCharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ACraftingSystemsProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	uint8 bUsingMotionControllers : 1;

private:

	/// <summary>
	/// Checks if their is an interactable item in the players view
	/// </summary>
	void CheckForInteractables();

protected:

	/** Fires a projectile. */
	void OnFire();

	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

};

