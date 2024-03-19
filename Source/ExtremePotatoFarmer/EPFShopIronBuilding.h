// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFShopBuilding.h"
#include "EPFShopIronBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFShopIronBuilding : public AEPFShopBuilding
{
	GENERATED_BODY()
	
public:

	void SellProduct() override;
};
