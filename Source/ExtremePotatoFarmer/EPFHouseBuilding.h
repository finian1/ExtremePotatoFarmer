// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFHouseBuilding.generated.h"

class AEPFBaseMinion;
/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFHouseBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:

	AEPFHouseBuilding()
	{
		mName = "House";
		mBuildingCost = { 0, 5, 0, 6 };
	}

	void BeginPlay();

	UFUNCTION(BlueprintCallable)
	void SpawnNewMinion();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFBaseMinion> mMinionClassToSpawn;
};
