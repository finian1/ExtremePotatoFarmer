// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EPFBaseMinion.generated.h"

class AEPFBaseBuilding;

USTRUCT(BlueprintType)
struct FMinionStats
{
	GENERATED_BODY();

public:
	UPROPERTY()
	float HP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* homeBuilding;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEPFBaseBuilding* workBuilding;
};

UCLASS()
class EXTREMEPOTATOFARMER_API AEPFBaseMinion : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEPFBaseMinion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* mMinionMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FMinionStats mMinionStats;

};
