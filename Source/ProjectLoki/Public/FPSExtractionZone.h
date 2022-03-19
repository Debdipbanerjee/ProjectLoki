// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "FPSExtractionZone.generated.h"

UCLASS()
class PROJECTLOKI_API AFPSExtractionZone : public AActor
{

	GENERATED_BODY()



public:


	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	


	UPROPERTY(VisibleAnywhere, Category= "Components")
	UBoxComponent* OverlapComp;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	

};