// Fill out your copyright notice in the Description page of Project Se
#include "EPFCitizenMinion.h"
#include "../EPFGameState.h"

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