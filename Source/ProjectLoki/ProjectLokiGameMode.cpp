// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectLokiGameMode.h"
#include "ProjectLokiHUD.h"
#include "ProjectLokiCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "FPSGameState.h"

AProjectLokiGameMode::AProjectLokiGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectLokiHUD::StaticClass();

	GameStateClass = AFPSGameState::StaticClass();
}

void AProjectLokiGameMode::CompleteMission(APawn* InstigatorPawn, bool bMissionSuccess)
{
	if(InstigatorPawn)
	{
		//InstigatorPawn->DisableInput(nullptr);

		if(SpectatingViewPointClass)
		{
			TArray<AActor*> ReturnedActors;
			UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewPointClass, ReturnedActors);

			//change view target if any valid actor found
			if (ReturnedActors.Num() > 0)
			{
				AActor* NewViewTarget = ReturnedActors[0];

				for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator(); It; It++)
				{
					APlayerController* PC = It->Get();

					if(PC)
					{
						PC->SetViewTargetWithBlend(NewViewTarget, 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
					}
				}

			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Spectatingviewclass is null ptr, plase update game mode"));
		}

	}

	
	AFPSGameState* GS = GetGameState<AFPSGameState>();
	if(GS)
	{
		GS->MulticastOnMissionComplete(InstigatorPawn, bMissionSuccess);
	}

	OnMissionCompleted(InstigatorPawn, bMissionSuccess);

	
}
