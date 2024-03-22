// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "EPFGameState.generated.h"

class AEPFBaseBuilding;
class AEPFCitizenMinion;
class AEPFThiefMinion;
/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFGameState : public AGameStateBase
{
	GENERATED_BODY()
public:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TArray<TSubclassOf<AEPFBaseBuilding>> mBuildingTypes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int mCurrentSelectedBuildingIndex = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfPotatoes = 300;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfCitizens = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfHouses = 0;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfFarms = 0;

	//Materials
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mWood = 20;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mStone = 10;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mIron = 9;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mGold = 25;

	//Primary town buildings
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFBaseBuilding> mTownSchoolBuildingClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownSchoolBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFBaseBuilding> mTownMineBuildingClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownMineBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFBaseBuilding> mTownForestBuildingClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* mTownForestBuilding;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFBaseBuilding> mTownBarracksBuildingClass;
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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AEPFCitizenMinion*> mGuardsAtBattleground;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<AEPFThiefMinion*> mThievesAtBattleground;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool mGameOver = false;

	UFUNCTION(BlueprintCallable)
	int GetNumberOfCitizens()
	{
		return mOverallCitizens.Num();
	}

	UFUNCTION(BlueprintCallable)
	int GetNumberOfThieves()
	{
		return mThievesAtBattleground.Num();
	}
	UFUNCTION(BlueprintCallable)
	int GetNumberOfGuards()
	{
		return mGuardsAtBattleground.Num();
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

	bool CanAffordBuilding(TSubclassOf<AEPFBaseBuilding> BuildingType);

	void RemovePotatoes(int amount);
};
