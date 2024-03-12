#pragma once

#include "CoreMinimal.h"
#include "EPFBaseBuilding.h"
#include "EPFMultiWorkerBuilding.generated.h"

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

	void AssignWorker() override;

	void RemoveWorker() override;

	TArray<AEPFCitizenMinion*> mWorkers;

};