// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFShopIronBuilding.h"
#include "EPFGameState.h"

void AEPFShopIronBuilding::SellProduct()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mIron >= mAmountToSell)
		{
			state->mIron -= mAmountToSell;
			state->mGold += mGoldToEarn;
		}
	}
}