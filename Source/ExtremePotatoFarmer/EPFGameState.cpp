// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFGameState.h"
#include "EPFBaseBuilding.h"
#include "EPFFarmBuilding.h"
#include "Kismet/GameplayStatics.h"
#include "Minions/EPFCitizenMinion.h"
#include "Minions/EPFThiefMinion.h"

void AEPFGameState::BeginPlay()
{
	Super::BeginPlay();
	mTownSchoolBuilding = static_cast<AEPFBaseBuilding*>(UGameplayStatics::GetActorOfClass(GetWorld(), mTownSchoolBuildingClass));
	mTownMineBuilding = static_cast<AEPFBaseBuilding*>(UGameplayStatics::GetActorOfClass(GetWorld(), mTownMineBuildingClass));
	mTownForestBuilding = static_cast<AEPFBaseBuilding*>(UGameplayStatics::GetActorOfClass(GetWorld(), mTownForestBuildingClass));
	mTownBarracksBuilding = static_cast<AEPFBaseBuilding*>(UGameplayStatics::GetActorOfClass(GetWorld(), mTownBarracksBuildingClass));
}

bool AEPFGameState::CanAffordBuilding(TSubclassOf<AEPFBaseBuilding> BuildingType)
{
	FBuildingCost cost = BuildingType.GetDefaultObject()->mBuildingCost;
	if (BuildingType->IsChildOf(AEPFFarmBuilding::StaticClass()))
	{
		//Add 25 gold to cost for each farm
		cost.gold += 25 * mNumberOfFarms;
	}
	if (cost.gold > mGold   || 
		cost.iron > mIron   || 
		cost.stone > mStone || 
		cost.wood > mWood)
	{
		return false;
	}
	return true;
}

void AEPFGameState::RemovePotatoes(int amount)
{
	mNumberOfPotatoes -= amount;
	if (mNumberOfPotatoes <= 0)
	{
		mGameOver = true;
	}
}
