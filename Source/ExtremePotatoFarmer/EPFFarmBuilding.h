// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFFarmBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFFarmBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()
	
public:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumOfPotatoesToFarm = 3;

	UFUNCTION(BlueprintCallable)
	void GeneratePotatoes(int quantity);

	void Work() override;


};
