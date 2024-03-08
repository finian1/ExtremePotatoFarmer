// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EPFBaseBuilding.generated.h"

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

	//Functions

	UFUNCTION(BlueprintCallable)
	virtual void Work();

	//Temp variables
	float timer = 0.0f;

};
