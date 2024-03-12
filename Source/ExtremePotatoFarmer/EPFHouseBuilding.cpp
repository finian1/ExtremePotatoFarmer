// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFHouseBuilding.h"
#include "Minions/EPFCitizenMinion.h"

void AEPFHouseBuilding::BeginPlay()
{
	//Create new citizen with this as home
	SpawnNewMinion();
}

void AEPFHouseBuilding::SpawnNewMinion()
{
	AEPFCitizenMinion* newMinion = GetWorld()->SpawnActor<AEPFCitizenMinion>(mMinionClassToSpawn, this->GetTransform().GetLocation() + FVector{5, 5, 5}, FRotator::ZeroRotator);
	if (IsValid(newMinion))
	{
		newMinion->mMinionStats.homeBuilding = this;
		newMinion->mIsAdult = false;
		newMinion->mIsTrained = false;
	}
}