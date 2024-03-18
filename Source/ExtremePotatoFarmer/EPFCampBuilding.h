// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFCampBuilding.generated.h"

class AEPFThiefMinion;

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFCampBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:
	AEPFCampBuilding()
	{
		mName = "Bandit Camp";
	}

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnThief();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* mBattleGround;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mTimeBetweenSpawns;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mNumberOfThievesToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mAggroLevel;

	UPROPERTY()
	float mTimeSinceLastSpawn = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFThiefMinion> mMinionClassToSpawn;
	
};
