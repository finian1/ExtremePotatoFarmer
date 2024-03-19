// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExtremePotatoFarmerGameMode.h"
#include "ExtremePotatoFarmerPlayerController.h"
#include "ExtremePotatoFarmerCharacter.h"
#include "EPFBaseBuilding.h"
#include "UObject/ConstructorHelpers.h"

AExtremePotatoFarmerGameMode::AExtremePotatoFarmerGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AExtremePotatoFarmerPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}