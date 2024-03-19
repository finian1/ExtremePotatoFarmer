// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFShopStoneBuilding.h"
#include "EPFGameState.h"

void AEPFShopStoneBuilding::SellProduct()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mStone >= mAmountToSell)
		{
			state->mStone -= mAmountToSell;
			state->mGold += mGoldToEarn;
		}
	}
}