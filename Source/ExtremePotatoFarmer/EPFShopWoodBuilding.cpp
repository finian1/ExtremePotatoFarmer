// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFShopWoodBuilding.h"
#include "EPFGameState.h"

void AEPFShopWoodBuilding::SellProduct()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mWood >= mAmountToSell)
		{
			state->mWood -= mAmountToSell;
			state->mGold += mGoldToEarn;
		}
	}
}