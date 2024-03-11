// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBaseBuilding.h"

// Sets default values
AEPFBaseBuilding::AEPFBaseBuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mBuildingMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Building Mesh");
	mBuildingMeshComponent->SetupAttachment(GetRootComponent());

	mBuildingMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AEPFBaseBuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEPFBaseBuilding::Tick(float DeltaTime)
{
}

void AEPFBaseBuilding::Work()
{

}

