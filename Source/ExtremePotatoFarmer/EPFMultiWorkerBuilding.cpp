#include "EPFMultiWorkerBuilding.h"
#include "Minions/EPFCitizenMinion.h"
#include "EPFGameState.h"

void AEPFMultiWorkerBuilding::AssignWorker()
{

	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mUnemployedTrainedCitizens.Num() > 0)
		{
			mWorkers.Add(state->mUnemployedTrainedCitizens[0]);
			state->mUnemployedTrainedCitizens[0]->mMinionStats.workBuilding = this;
			state->mUnemployedTrainedCitizens.RemoveAt(0);
			mNumberOfWorkers++;
		}
	}
}

void AEPFMultiWorkerBuilding::RemoveWorker()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (mNumberOfWorkers > 0)
		{
			state->mUnemployedTrainedCitizens.Add(mWorkers[0]);
			mWorkers[0]->mMinionStats.workBuilding = nullptr;
			mWorkers.RemoveAt(0);
			mNumberOfWorkers--;
		}
	}
}