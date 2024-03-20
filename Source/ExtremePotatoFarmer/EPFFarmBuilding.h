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

	virtual void BeginPlay() override;

	AEPFFarmBuilding()
	{
		mName = "Farm";
		mBuildingCost = {50, 0, 0, 0};
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mNumOfPotatoesToFarm = 9;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AEPFCitizenMinion* mWorker;

	UFUNCTION(BlueprintCallable)
	void GeneratePotatoes(int quantity);

	void Work() override;

	AEPFBaseMinion* AssignWorker() override;

	void RemoveWorker() override;

	void Interact() override;
};
