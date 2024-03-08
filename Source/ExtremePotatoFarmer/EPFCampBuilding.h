// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFCampBuilding.generated.h"

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
	
};
