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

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnGrowUp();
	UFUNCTION(BlueprintCallable)
	void OnTrained();

	void Damage(float amount) override;

	void EatFood();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mTimeToGrowUp = 4.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mTimeToTrain = 4.0f;

	UPROPERTY(BlueprintReadWrite)
	bool mIsAdult = false;
	UPROPERTY(BlueprintReadWrite)
	bool mIsTrained = false;

	FTimerHandle mGrowUpTimerHandle;
	FTimerHandle mTrainingTimerHandle;
	FTimerHandle mEatingTimerHandle;

	FVector mChildScale = { 0.2f, 0.2f, 0.2f };
	FVector mGrownScale = { 0.4f, 0.4f, 0.4f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterialInterface* mTrainedMaterial;

	float mDamageIfHungry = 5.0f;
	float mTimeBetweenEating = 10.0f;
	float mAmountToHealOnEating = 0.2f;
	int mNumOfPotatoesToEat = 1;
};
