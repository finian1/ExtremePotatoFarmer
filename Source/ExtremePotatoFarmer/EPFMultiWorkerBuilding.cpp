#include "EPFMultiWorkerBuilding.h"
#include "Minions/EPFCitizenMinion.h"
#include "EPFGameState.h"
#include "AIController.h"

AEPFBaseMinion* AEPFMultiWorkerBuilding::AssignWorker()
{

	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mUnemployedTrainedCitizens.Num() > 0)
		{
			AEPFCitizenMinion* newWorker = state->mUnemployedTrainedCitizens[0];
			mWorkers.Add(state->mUnemployedTrainedCitizens[0]);
			state->mUnemployedTrainedCitizens[0]->GetController<AAIController>()->RunBehaviorTree(mBuildingWorkerAI);
			state->mUnemployedTrainedCitizens[0]->mMinionStats.workBuilding = this;
			state->mUnemployedTrainedCitizens.RemoveAt(0);
			mNumberOfWorkers++;
			return newWorker;
		}
	}
	return nullptr;
}

void AEPFMultiWorkerBuilding::RemoveWorker()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (mNumberOfWorkers > 0)
		{
			state->mUnemployedTrainedCitizens.Add(mWorkers[0]);
			mWorkers[0]->mMinionStats.workBuilding = nullptr;
			mWorkers[0]->RevertToDefaultBehaviour();
			mWorkers.RemoveAt(0);
			mNumberOfWorkers--;
		}
	}
}

void AEPFMultiWorkerBuilding::Interact()
{
	AssignWorker();
}