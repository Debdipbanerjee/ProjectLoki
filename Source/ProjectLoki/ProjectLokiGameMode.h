// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectLokiGameMode.generated.h"

UCLASS(minimalapi)
class AProjectLokiGameMode : public AGameModeBase
{
	GENERATED_BODY()


protected:

	UPROPERTY(EditDefaultsOnly, Category= "Spectating")
	TSubclassOf< AActor> SpectatingViewPointClass;

public:
	AProjectLokiGameMode();

	void CompleteMission(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent, Category= "GameMode")
	void OnMissionCompleted(APawn* InstigatorPawn);
};



