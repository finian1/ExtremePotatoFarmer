// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFShopBuilding.h"
#include "EPFShopStoneBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFShopStoneBuilding : public AEPFShopBuilding
{
	GENERATED_BODY()
public:
	void SellProduct() override;
};
