// Fill out your copyright notice in the Description page of Project Settings.


#include "EPFThiefMinion.h"
#include "../EPFGameState.h"
#include "EPFCitizenMinion.h"

void AEPFThiefMinion::AttackGuard()
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		int guardCount = state->mGuardsAtBattleground.Num();
		FRandomStream rand;
		int rndAttackIndex = rand.RandRange(0, guardCount - 1);
		state->mGuardsAtBattleground[rndAttackIndex]->Damage(mMinionStats.damageToDeal);
	}
}

void AEPFThiefMinion::StealPotatoes(int amount)
{
	if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
	{
		state->mNumberOfPotatoes -= amount;
	}
}

void AEPFThiefMinion::Damage(float amount)
{
	Super::Damage(amount);
	if (mMinionStats.HP < 0)
	{
		if (AEPFGameState* state = GetWorld()->GetGameState<AEPFGameState>())
		{
			state->mThievesAtBattleground.Remove(this);
		}
	}
}

