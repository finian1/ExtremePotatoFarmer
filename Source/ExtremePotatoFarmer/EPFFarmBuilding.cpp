// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFFarmBuilding.h"
#include "EPFGameState.h"
#include "AIController.h"
#include "Minions/EPFCitizenMinion.h"


void AEPFFarmBuilding::BeginPlay()
{
	ShowAlertText();
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mNumberOfFarms++;
	}
}

void AEPFFarmBuilding::GeneratePotatoes(int quantity)
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mNumberOfPotatoes += quantity;
	}
}

void AEPFFarmBuilding::Work()
{
	GeneratePotatoes(mNumOfPotatoesToFarm);
}

AEPFBaseMinion* AEPFFarmBuilding::AssignWorker()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mUnemployedTrainedCitizens.Num() > 0 && mNumberOfWorkers == 0)
		{
			mWorker = state->mUnemployedTrainedCitizens[0];
			mWorker->GetController<AAIController>()->RunBehaviorTree(mBuildingWorkerAI);
			state->mUnemployedTrainedCitizens.RemoveAt(0);
			mWorker->mMinionStats.workBuilding = this;
			mNumberOfWorkers++;
			HideAlertText();
			return mWorker;
		}
	}
	return nullptr;
}

void AEPFFarmBuilding::RemoveWorker()
{
	if (mNumberOfWorkers > 0)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			state->mUnemployedTrainedCitizens.Add(mWorker);
			mWorker->RevertToDefaultBehaviour();
			mWorker->mMinionStats.workBuilding = nullptr;
			mWorker = nullptr;
			ShowAlertText();
			mNumberOfWorkers--;
		}
	}
}

void AEPFFarmBuilding::Interact()
{
	AssignWorker();
}

