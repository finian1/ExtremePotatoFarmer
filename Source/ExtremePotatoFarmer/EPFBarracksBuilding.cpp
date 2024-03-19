// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFBarracksBuilding.h"
#include "EPFGameState.h"
#include "Minions/EPFCitizenMinion.h"

AEPFBaseMinion* AEPFBarracksBuilding::AssignWorker()
{
	AEPFBaseMinion* minion = Super::AssignWorker();
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mGuardsAtBattleground.Add(static_cast<AEPFCitizenMinion*>(minion));
	}
	return minion;
}