// Fill out your copyright notice in the Description page of Project Se
#include "EPFCitizenMinion.h"
#include "../EPFGameState.h"
#include "EPFThiefMinion.h"
#include "../EPFBarracksBuilding.h"
#include "../EPFHouseBuilding.h"

void AEPFCitizenMinion::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(mGrowUpTimerHandle, this, &AEPFCitizenMinion::OnGrowUp, mTimeToGrowUp, false);
	GetWorld()->GetTimerManager().SetTimer(mEatingTimerHandle, this, &AEPFCitizenMinion::EatFood, mTimeBetweenEating, true);
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		SetActorScale3D(mChildScale);
		state->mOverallCitizens.Add(this);
	}
}

void AEPFCitizenMinion::OnGrowUp()
{
	mIsAdult = true;
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		SetActorScale3D(mGrownScale);
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
		mMinionMeshComponent->SetMaterial(0, mTrainedMaterial);
	}
}

void AEPFCitizenMinion::EatFood()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (state->mNumberOfPotatoes < mNumOfPotatoesToEat)
		{
			Damage(mDamageIfHungry);
		}
		else 
		{
			state->mNumberOfPotatoes -= mNumOfPotatoesToEat;
			mMinionStats.HP += mAmountToHealOnEating;
		}
	}
}

void AEPFCitizenMinion::Damage(float amount)
{
	Super::Damage(amount);
	if (mMinionStats.HP < 0)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{

			state->mOverallCitizens.Remove(static_cast<AEPFCitizenMinion*>(this));
			state->mUnemployedTrainedCitizens.Remove(static_cast<AEPFCitizenMinion*>(this));
			state->mUntrainedCitizens.Remove(static_cast<AEPFCitizenMinion*>(this));
			state->mGuardsAtBattleground.Remove(this);
			static_cast<AEPFHouseBuilding*>(mMinionStats.homeBuilding)->SpawnNewMinion();
			Destroy();
		}
	}
}