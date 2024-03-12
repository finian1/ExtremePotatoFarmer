// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFFarmBuilding.h"
#include "EPFGameState.h"
#include "Minions/EPFCitizenMinion.h"



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

void AEPFFarmBuilding::AssignWorker()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mUnemployedTrainedCitizens.Num() > 0)
		{
			mWorker = state->mUnemployedTrainedCitizens[0];
			state->mUnemployedTrainedCitizens.RemoveAt(0);
			mWorker->mMinionStats.workBuilding = this;
			mNumberOfWorkers++;
		}
	}
}

void AEPFFarmBuilding::RemoveWorker()
{
	if (mNumberOfWorkers > 0)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			state->mUnemployedTrainedCitizens.Add(mWorker);
			mWorker->mMinionStats.workBuilding = nullptr;
			mWorker = nullptr;
			mNumberOfWorkers--;
		}
	}
}

