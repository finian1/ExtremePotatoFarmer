// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBaseBuilding.h"
#include "BehaviorTree/BehaviorTree.h"
#include "EPFGameState.h"


// Sets default values
AEPFBaseBuilding::AEPFBaseBuilding()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mBuildingMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Building Mesh");
	mBuildingMeshComponent->SetupAttachment(GetRootComponent());

	mBuildingMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	
	FCollisionResponseContainer collision;
	collision.SetResponse(ECC_Visibility, ECR_Block);
	collision.SetResponse(ECC_Camera, ECR_Block);
	collision.SetResponse(ECC_WorldStatic, ECR_Ignore);
	collision.SetResponse(ECC_WorldDynamic, ECR_Ignore);
	collision.SetResponse(ECC_Pawn, ECR_Ignore);
	collision.SetResponse(ECC_PhysicsBody, ECR_Ignore);
	collision.SetResponse(ECC_Vehicle, ECR_Ignore);
	collision.SetResponse(ECC_Destructible, ECR_Ignore);

	mBuildingMeshComponent->SetCollisionResponseToChannels(collision);

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
}

void AEPFBaseBuilding::Work()
{

}

void AEPFBaseBuilding::AssignWorker()
{
	
}

void AEPFBaseBuilding::RemoveWorker()
{
}

bool AEPFBaseBuilding::CanAfford()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		if (mBuildingCost.gold <= state->mGold &&
			mBuildingCost.iron <= state->mIron &&
			mBuildingCost.stone <= state->mStone &&
			mBuildingCost.wood <= state->mWood)
		{
			return true;
		}
	}
	return false;
}

