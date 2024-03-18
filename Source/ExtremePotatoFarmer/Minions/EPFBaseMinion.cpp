// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBaseMinion.h"
#include "EPFCitizenMinion.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "../EPFBaseBuilding.h"
#include "AIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "../EPFGameState.h"

// Sets default values
AEPFBaseMinion::AEPFBaseMinion()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mMinionMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Minion Mesh");
	mMinionMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	mMinionMeshComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEPFBaseMinion::BeginPlay()
{
	Super::BeginPlay();
	GetController<AAIController>()->RunBehaviorTree(mDefaultBehaviourTree);
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

void AEPFBaseMinion::RevertToDefaultBehaviour()
{
	RunNewBehaviour(mDefaultBehaviourTree);
}

void AEPFBaseMinion::RunNewBehaviour(UBehaviorTree* newBehaviour)
{
	GetController<AAIController>()->BrainComponent->DestroyComponent();
	GetController<AAIController>()->RunBehaviorTree(newBehaviour);
}

void AEPFBaseMinion::Damage(float amount)
{
	mMinionStats.HP -= amount;
	if (mMinionStats.HP < 0.0f)
	{
		Destroy();
	}
}

