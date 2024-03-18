// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFCampBuilding.h"
#include "Minions/EPFThiefMinion.h"

void AEPFCampBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float currentSpawnTime = mTimeBetweenSpawns;
	mTimeSinceLastSpawn += DeltaTime;

	if (mTimeSinceLastSpawn >= currentSpawnTime)
	{
		for (int i = 0; i < mNumberOfThievesToSpawn; i++)
		{
			SpawnThief();
			mTimeSinceLastSpawn = 0;
		}
	}
}

void AEPFCampBuilding::SpawnThief()
{
	AEPFThiefMinion* newMinion = GetWorld()->SpawnActor<AEPFThiefMinion>(mMinionClassToSpawn, this->GetTransform().GetLocation() + FVector{ 5, 5, 5 }, FRotator::ZeroRotator);
	if (IsValid(newMinion))
	{
		newMinion->mMinionStats.workBuilding = this;
	}
}