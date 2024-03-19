// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFShopBuilding.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFShopBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mAmountToSell;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int mGoldToEarn;

	virtual void Interact() override 
	{
		SellProduct();
	};

	UFUNCTION(BlueprintCallable)
	virtual void SellProduct() {};
};
