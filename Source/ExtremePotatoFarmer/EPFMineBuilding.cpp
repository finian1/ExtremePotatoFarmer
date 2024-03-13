// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFMineBuilding.h"
#include "EPFGameState.h"

void AEPFMineBuilding::GenerateIron(int quantity)
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mIron += quantity;
	}
}

void AEPFMineBuilding::GenerateStone(int quantity)
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mStone += quantity;
	}
}

void AEPFMineBuilding::Work()
{
	GenerateIron(FMath::RandRange(0, mMaxAmountOfIronToGenerate));
	GenerateStone(FMath::RandRange(0, mMaxAmountOfStoneToGenerate));
}