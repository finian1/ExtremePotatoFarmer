// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFGameState.h"
#include "EPFBaseBuilding.h"
#include "EPFFarmBuilding.h"
#include "Minions/EPFCitizenMinion.h"
#include "Minions/EPFThiefMinion.h"


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
