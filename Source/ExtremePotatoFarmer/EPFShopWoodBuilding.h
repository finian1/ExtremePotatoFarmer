// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFShopBuilding.h"
#include "EPFShopWoodBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFShopWoodBuilding : public AEPFShopBuilding
{
	GENERATED_BODY()

public:
	void SellProduct() override;
};
