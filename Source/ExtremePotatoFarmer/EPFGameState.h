// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EPFGameState.generated.h"

class AEPFBaseBuilding;
class AEPFCitizenMinion;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfCitizens = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfHouses = 0;

	//Materials
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mWood = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mStone = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mIron = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mGold = 0;

	//Primary town buildings
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownSchoolBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownMineBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownForestBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownBarracksBuilding;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AEPFCitizenMinion*> mOverallCitizens;
	//A list of citizens that still need to go to school.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AEPFCitizenMinion*> mUntrainedCitizens;
	//List of minions that are trained but unemployed.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AEPFCitizenMinion*> mUnemployedTrainedCitizens;

	UFUNCTION(BlueprintCallable)
	int GetNumberOfCitizens()
	{
		return mOverallCitizens.Num();
	}

	UFUNCTION(BlueprintCallable)
	int GetNumberOfUnemployedTrainedCitizens()
	{
		return mUnemployedTrainedCitizens.Num();
	}

	void CycleSelectedBuildingForward()
	{
		mCurrentSelectedBuildingIndex = (mCurrentSelectedBuildingIndex + 1) % mBuildingTypes.Num();
	}

	void CycleSelectedBuildingBackwards()
	{
		(mCurrentSelectedBuildingIndex - 1) < 0 ? mCurrentSelectedBuildingIndex = mBuildingTypes.Num() - 1 : mCurrentSelectedBuildingIndex -= 1;
	}
};
