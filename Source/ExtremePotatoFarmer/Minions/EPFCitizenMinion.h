// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseMinion.h"
#include "EPFCitizenMinion.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFCitizenMinion : public AEPFBaseMinion
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mTimeToGrowUp = 10.0f;
	UPROPERTY()
	bool mIsAdult = false;
	UPROPERTY()
	bool mIsTrained = false;
};
