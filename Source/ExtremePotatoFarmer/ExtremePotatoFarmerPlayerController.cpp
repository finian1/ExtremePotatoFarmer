// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtremePotatoFarmerPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "NiagaraSystem.h"
#include "NiagaraFunctionLibrary.h"
#include "ExtremePotatoFarmerCharacter.h"
#include "Engine/World.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "EPFBaseBuilding.h"
#include "EPFFarmBuilding.h"
#include "EPFGameState.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

AExtremePotatoFarmerPlayerController::AExtremePotatoFarmerPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	CachedDestination = FVector::ZeroVector;
	FollowTime = 0.f;
}

void AExtremePotatoFarmerPlayerController::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
}

void AExtremePotatoFarmerPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Setup mouse input events
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Started, this, &AExtremePotatoFarmerPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Triggered, this, &AExtremePotatoFarmerPlayerController::OnSetDestinationTriggered);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Completed, this, &AExtremePotatoFarmerPlayerController::OnSetDestinationReleased);
		EnhancedInputComponent->BindAction(SetDestinationClickAction, ETriggerEvent::Canceled, this, &AExtremePotatoFarmerPlayerController::OnSetDestinationReleased);

		// Setup touch input events
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Started, this, &AExtremePotatoFarmerPlayerController::OnInputStarted);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Triggered, this, &AExtremePotatoFarmerPlayerController::OnTouchTriggered);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Completed, this, &AExtremePotatoFarmerPlayerController::OnTouchReleased);
		EnhancedInputComponent->BindAction(SetDestinationTouchAction, ETriggerEvent::Canceled, this, &AExtremePotatoFarmerPlayerController::OnTouchReleased);
	
		EnhancedInputComponent->BindAction(AttemptBuildingSpawnClickAction, ETriggerEvent::Started, this, &AExtremePotatoFarmerPlayerController::AttemptBuildingPlacement);
		
		EnhancedInputComponent->BindAction(CycleThroughBuildingsAction, ETriggerEvent::Started, this, &AExtremePotatoFarmerPlayerController::CycleSelectedBuilding);
		EnhancedInputComponent->BindAction(CycleThroughBuildingsAction, ETriggerEvent::Triggered, this, &AExtremePotatoFarmerPlayerController::CycleSelectedBuilding);
		EnhancedInputComponent->BindAction(CycleThroughBuildingsAction, ETriggerEvent::Completed, this, &AExtremePotatoFarmerPlayerController::CycleSelectedBuilding);

		CycleActionBinding = &EnhancedInputComponent->BindActionValue(CycleThroughBuildingsAction);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void AExtremePotatoFarmerPlayerController::OnInputStarted()
{
	StopMovement();
}

// Triggered every frame when the input is held down
void AExtremePotatoFarmerPlayerController::OnSetDestinationTriggered()
{
	// We flag that the input is being pressed
	FollowTime += GetWorld()->GetDeltaSeconds();
	
	// We look for the location in the world where the player has pressed the input
	FHitResult Hit;
	bool bHitSuccessful = false;
	if (bIsTouch)
	{
		bHitSuccessful = GetHitResultUnderFinger(ETouchIndex::Touch1, ECollisionChannel::ECC_Visibility, true, Hit);
	}
	else
	{
		bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);
	}

	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		CachedDestination = Hit.Location;
	}
	
	// Move towards mouse pointer or touch
	APawn* ControlledPawn = GetPawn();
	if (ControlledPawn != nullptr)
	{
		FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
		ControlledPawn->AddMovementInput(WorldDirection, 1.0, false);
	}
}

void AExtremePotatoFarmerPlayerController::OnSetDestinationReleased()
{
	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We move there and spawn some particles
		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, CachedDestination);
		UNiagaraFunctionLibrary::SpawnSystemAtLocation(this, FXCursor, CachedDestination, FRotator::ZeroRotator, FVector(1.f, 1.f, 1.f), true, true, ENCPoolMethod::None, true);
	}

	FollowTime = 0.f;
}

// Triggered every frame when the input is held down
void AExtremePotatoFarmerPlayerController::OnTouchTriggered()
{
	bIsTouch = true;
	OnSetDestinationTriggered();
}

void AExtremePotatoFarmerPlayerController::OnTouchReleased()
{
	bIsTouch = false;
	OnSetDestinationReleased();
}

void AExtremePotatoFarmerPlayerController::AttemptBuildingPlacement()
{
	// We look for the location in the world where the player has pressed the input
	FVector buildingSpawnLocation;
	FHitResult Hit;
	bool bHitSuccessful = false;
	bHitSuccessful = GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, Hit);


	// If we hit a surface, cache the location
	if (bHitSuccessful)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			if (AEPFBaseBuilding* building = dynamic_cast<AEPFBaseBuilding*>(Hit.GetActor()))
			{
				building->Interact();
			}
			else
			{
				buildingSpawnLocation = Hit.Location;
				FActorSpawnParameters params;
				FRotator rotation;
				if (state->CanAffordBuilding(state->mBuildingTypes[state->mCurrentSelectedBuildingIndex]))
				{
					GetWorld()->SpawnActor<AEPFBaseBuilding>(state->mBuildingTypes[state->mCurrentSelectedBuildingIndex], buildingSpawnLocation, rotation, params);
					FBuildingCost cost = state->mBuildingTypes[state->mCurrentSelectedBuildingIndex].GetDefaultObject()->mBuildingCost;
					if (state->mBuildingTypes[state->mCurrentSelectedBuildingIndex]->IsChildOf(AEPFFarmBuilding::StaticClass()))
					{
						cost.gold += 25 * state->mNumberOfFarms;
						state->mNumberOfFarms++;
					}
					state->mGold -= cost.gold;
					state->mIron -= cost.iron;
					state->mWood -= cost.wood;
					state->mStone -= cost.stone;
				}
			}
		}
	}
}

void AExtremePotatoFarmerPlayerController::CycleSelectedBuilding()
{
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		float scroll = CycleActionBinding->GetValue().GetMagnitude();

		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			if (scroll > 0)
			{
				state->CycleSelectedBuildingForward();
			}
			else if (scroll < 0)
			{
				state->CycleSelectedBuildingBackwards();
			}
		}
	}
}
