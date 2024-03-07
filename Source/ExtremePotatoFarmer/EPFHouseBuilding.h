// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFHouseBuilding.generated.h"

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
	}
	
};
