// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFMultiWorkerBuilding.h"
#include "EPFForestBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFForestBuilding : public AEPFMultiWorkerBuilding
{
	GENERATED_BODY()

public:
	AEPFForestBuilding()
	{
		mName = "Forest";
		mTimeToWork = 5.0f;
	}
	int mAmountOfWoodToProduce = 3;

	UFUNCTION(BlueprintCallable)
	void GenerateWood(int quantity);

	void Work() override;
	
};
