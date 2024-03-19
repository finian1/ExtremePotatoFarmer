// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFMultiWorkerBuilding.h"
#include "EPFBarracksBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFBarracksBuilding : public AEPFMultiWorkerBuilding
{
	GENERATED_BODY()

public:
	AEPFBarracksBuilding()
	{
		mName = "Barracks";
	}

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* mBattleGround;

	AEPFBaseMinion* AssignWorker();
	
};
