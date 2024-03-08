// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFForestBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFForestBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:
	AEPFForestBuilding()
	{
		mName = "Forest";
	}
	
};
