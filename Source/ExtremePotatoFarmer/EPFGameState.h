// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EPFGameState.generated.h"

class AEPFBaseBuilding;
/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<TSubclassOf<AEPFBaseBuilding>> mBuildingTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int mCurrentSelectedBuildingIndex = 0;

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

	void CycleSelectedBuildingForward()
	{
		mCurrentSelectedBuildingIndex = (mCurrentSelectedBuildingIndex + 1) % mBuildingTypes.Num();
	}

	void CycleSelectedBuildingBackwards()
	{
		(mCurrentSelectedBuildingIndex - 1) < 0 ? mCurrentSelectedBuildingIndex = mBuildingTypes.Num() - 1 : mCurrentSelectedBuildingIndex -= 1;
	}
};
