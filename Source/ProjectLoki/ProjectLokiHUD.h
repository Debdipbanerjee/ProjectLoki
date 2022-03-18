// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ProjectLokiHUD.generated.h"

UCLASS()
class AProjectLokiHUD : public AHUD
{
	GENERATED_BODY()

public:
	AProjectLokiHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

