// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectLokiGameMode.h"
#include "ProjectLokiHUD.h"
#include "ProjectLokiCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectLokiGameMode::AProjectLokiGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectLokiHUD::StaticClass();
}
