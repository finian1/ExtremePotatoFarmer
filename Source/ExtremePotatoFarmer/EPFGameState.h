// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EPFGameState.generated.h"

UENUM()
enum BUILDING_TYPE
{
	FARM,
	HOUSE,
	MINE,
	FOREST,
	BARRACKS,
	CAMP
};

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TEnumAsByte<BUILDING_TYPE> mSelectedBuilding = FARM;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfPotatoes = 0;

	//Materials
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mWood = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mStone = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mIron = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mGold = 0;
};
