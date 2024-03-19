#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFMultiWorkerBuilding.generated.h"

class AEPFCitizenMinion;
/**
 *
 */
UCLASS()
class EXTREMEPOTATOFARMER_API AEPFMultiWorkerBuilding : public AEPFBaseBuilding
{
	GENERATED_BODY()

public:
	AEPFMultiWorkerBuilding()
	{
	}

	AEPFBaseMinion* AssignWorker() override;

	void RemoveWorker() override;

	void Interact() override;

	TArray<AEPFCitizenMinion*> mWorkers;

};