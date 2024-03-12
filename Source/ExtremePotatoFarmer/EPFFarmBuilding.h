// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFFarmBuilding.generated.h"

class AEPFCitizenMinion;
/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFFarmBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:

	AEPFFarmBuilding()
	{
		mName = "Farm";
	}

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumOfPotatoesToFarm = 3;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFCitizenMinion* mWorker;

	UFUNCTION(BlueprintCallable)
	void GeneratePotatoes(int quantity);

	void Work() override;

	void AssignWorker() override;

	void RemoveWorker() override;
};
