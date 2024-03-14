// Fill out your copyright notice in the Description page of Project Se
#include "EPFCitizenMinion.h"
#include "../EPFGameState.h"
#include "EPFThiefMinion.h"
#include "../EPFBarracksBuilding.h"

void AEPFCitizenMinion::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(mGrowUpTimerHandle, this, &AEPFCitizenMinion::OnGrowUp, mTimeToGrowUp, false);
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mOverallCitizens.Add(this);
	}
}

void AEPFCitizenMinion::OnGrowUp()
{
	mIsAdult = true;
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mUntrainedCitizens.Add(this);
		GetWorld()->GetTimerManager().SetTimer(mTrainingTimerHandle, this, &AEPFCitizenMinion::OnTrained, mTimeToTrain, false);
	}
}

void AEPFCitizenMinion::OnTrained()
{
	mIsTrained = true;
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mUntrainedCitizens.Remove(this);
		state->mUnemployedTrainedCitizens.Add(this);
	}
}

void AEPFCitizenMinion::AttackThief()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		int guardCount = state->mThievesAtBattleground.Num();
		FRandomStream rand;
		int rndAttackIndex = rand.RandRange(0, guardCount - 1);
		state->mThievesAtBattleground[rndAttackIndex]->Damage(mMinionStats.damageToDeal);
	}
}

void AEPFCitizenMinion::Damage(float amount)
{
	Super::Damage(amount);
	if (mMinionStats.HP < 0 && mMinionStats.workBuilding->IsA(AEPFBarracksBuilding::StaticClass()))
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			state->mGuardsAtBattleground.Remove(this);
		}
	}
}