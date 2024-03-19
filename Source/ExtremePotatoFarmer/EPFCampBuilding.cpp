// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFCampBuilding.h"
#include "EPFGameState.h"
#include "Minions/EPFThiefMinion.h"

void AEPFCampBuilding::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(mInitialSpawnTimer, this, &AEPFCampBuilding::BeginSpawning, mTimeUntilInitialActivation, false);
}

void AEPFCampBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	mTimeSinceLastSpawn += DeltaTime;
	mTimeSinceLastAggroDecrease += DeltaTime;
	if (mIsSpawning)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			float currentSpawnTime = mTimeBetweenSpawns;
			currentSpawnTime -= FMath::Max(FMath::Min(mMaxDecreaseForSpawnTime, state->mNumberOfPotatoes - 300), 0);
			float currentAggroDecreaseTime = mTimeBetweenAggroDecrease;
			currentAggroDecreaseTime += state->GetNumberOfGuards() * mAggroDecreaseTimerShiftPerGuard;
			
			if (mTimeSinceLastSpawn >= currentSpawnTime)
			{
				int finalNumOfThievesToSpawn = mNumberOfThievesToSpawn;
				finalNumOfThievesToSpawn += mAdditionalThievesPerAggroLevel * mAggroLevel;

				if (finalNumOfThievesToSpawn + state->GetNumberOfThieves() > mMaxThieves)
				{
					finalNumOfThievesToSpawn = mMaxThieves - state->GetNumberOfThieves();
				}
				for (int i = 0; i < finalNumOfThievesToSpawn; i++)
				{
					SpawnThief();
				}
				mTimeSinceLastSpawn = 0;
			}
			if (mTimeSinceLastAggroDecrease >= currentAggroDecreaseTime)
			{
				mAggroLevel -= mAggroDrain;
				mAggroLevel = FMath::Max(mAggroLevel, 0);
				mTimeSinceLastAggroDecrease = 0.0f;
			}
		}
	}
}

void AEPFCampBuilding::SpawnThief()
{
	AEPFThiefMinion* newMinion = GetWorld()->SpawnActor<AEPFThiefMinion>(mMinionClassToSpawn, this->GetTransform().GetLocation() + FVector{ 5, 5, 5 }, FRotator::ZeroRotator);
	if (IsValid(newMinion))
	{
		GetWorld()->GetGameState<AEPFGameState>()->mThievesAtBattleground.Add(newMinion);
		newMinion->mMinionStats.workBuilding = this;
	}
}

void AEPFCampBuilding::BeginSpawning()
{
	mIsSpawning = true;
}

void AEPFCampBuilding::PauseSpawning()
{
	mIsSpawning = false;
}