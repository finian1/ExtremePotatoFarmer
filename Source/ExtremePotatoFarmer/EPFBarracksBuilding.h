// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFBarracksBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFBarracksBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:
	AEPFBarracksBuilding()
	{
		mName = "Barracks";
	}
	
};
