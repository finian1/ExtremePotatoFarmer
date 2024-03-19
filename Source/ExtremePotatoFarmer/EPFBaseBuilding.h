// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EPFBaseBuilding.generated.h"

class AEPFBaseMinion;
class UBehaviorTree;

/// <summary>
/// gold, wood, iron, stone
/// </summary>
USTRUCT(BlueprintType)
struct FBuildingCost
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int gold = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int wood = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int iron = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int stone = 0;
};

UCLASS()
class EXTREMEPOTATOFARMER_API AEPFBaseBuilding : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FString mName = "Base";
	
	// Sets default values for this actor's properties
	AEPFBaseBuilding();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mBuildingMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	int mNumberOfWorkers = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float mTimeToWork = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBehaviorTree* mBuildingWorkerAI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FBuildingCost mBuildingCost;

	//Functions
	UFUNCTION(BlueprintCallable)
	virtual void Interact() {};

	UFUNCTION(BlueprintCallable)
	virtual void Work();

	UFUNCTION(BlueprintCallable)
	virtual AEPFBaseMinion* AssignWorker();

	UFUNCTION(BlueprintCallable)
	virtual void RemoveWorker();

	UFUNCTION(BlueprintCallable)
	bool CanAfford();
};
