// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFForestBuilding.h"
#include "EPFGameState.h"

void AEPFForestBuilding::GenerateWood(int quantity)
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mWood += quantity;
	}
}

void AEPFForestBuilding::Work()
{
	GenerateWood(mAmountOfWoodToProduce);
}

