// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EPFBaseMinion.h"
#include "EPFThiefMinion.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFThiefMinion : public AEPFBaseMinion
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AttackGuard();
	
	UFUNCTION(BlueprintCallable)
	void StealPotatoes(int amount);

	void Damage(float amount) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int mAmountOfPotatoesToSteal = 2;
};
