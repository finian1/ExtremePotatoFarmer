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

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void SpawnThief();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* mBattleGround;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mTimeUntilInitialActivation = 50.0f;
	FTimerHandle mInitialSpawnTimer;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mTimeBetweenSpawns = 40.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mTimeBetweenAggroDecrease = 5.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mNumberOfThievesToSpawn;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mAggroLevel;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mAggroDrain = 5;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mAdditionalThievesPerAggroLevel = 0.2f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mMaxThieves = 10;
	//The maximum spawn timer decrease based on how many potatoes the player has
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mMaxDecreaseForSpawnTime = 30.0f;
	//How many seconds is added to the aggro decrease timer for each guard
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float mAggroDecreaseTimerShiftPerGuard = 5.0f;


	UPROPERTY()
	float mTimeSinceLastSpawn = 0.0f;
	UPROPERTY()
	float mTimeSinceLastAggroDecrease = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEPFThiefMinion> mMinionClassToSpawn;

	bool mIsSpawning = false;
	
	void BeginSpawning();
	void PauseSpawning();
};
