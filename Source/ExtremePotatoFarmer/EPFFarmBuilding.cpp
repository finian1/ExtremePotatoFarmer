// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFFarmBuilding.h"
#include "EPFGameState.h"


void AEPFFarmBuilding::GeneratePotatoes(int quantity)
{
	AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>();
	if (IsValid(state))
	{
		state->mNumberOfPotatoes += quantity;
	}
}

void AEPFFarmBuilding::Work()
{
	GeneratePotatoes(mNumOfPotatoesToFarm);
}

