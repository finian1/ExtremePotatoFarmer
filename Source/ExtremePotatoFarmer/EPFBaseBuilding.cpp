// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBaseBuilding.h"

// Sets default values
AEPFBaseBuilding::AEPFBaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mBuildingMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Building Mesh");
	mBuildingMeshComponent->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AEPFBaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEPFBaseBuilding::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer += DeltaTime;
	if(timer > 2.0)
	{
		Work();
		timer = 0;
	}
}

void AEPFBaseBuilding::Work()
{

}

