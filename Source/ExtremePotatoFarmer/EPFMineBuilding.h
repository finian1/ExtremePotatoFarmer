// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFMultiWorkerBuilding.h"
#include "EPFMineBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFMineBuilding : public AEPFMultiWorkerBuilding
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintCallable)
	void GenerateStone(int quantity);
	UFUNCTION(BlueprintCallable)
	void GenerateIron(int quantity);
	

	void Work() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mMaxAmountOfStoneToGenerate = 6;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mMaxAmountOfIronToGenerate = 3;
};
