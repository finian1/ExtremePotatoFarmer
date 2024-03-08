// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBaseMinion.h"
#include "../EPFBaseBuilding.h"

// Sets default values
AEPFBaseMinion::AEPFBaseMinion()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mMinionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Minion Mesh");
	mMinionMeshComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AEPFBaseMinion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEPFBaseMinion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEPFBaseMinion::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

