// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSObjective.h"
#include "ProjectLoki/ProjectLokiCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFPSObjective::AFPSObjective()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

	SetReplicates(true);
}

// Called when the game starts or when spawned
void AFPSObjective::BeginPlay()
{
	Super::BeginPlay();

	PlayEffects();
	
}

// Called every frame


void AFPSObjective::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	PlayEffects();

	if(HasAuthority())
	{
		AProjectLokiCharacter* MyCharacter = Cast<AProjectLokiCharacter>(OtherActor);
		if (MyCharacter)
		{
			MyCharacter->bIsCarryingObjective = true;

			Destroy();
		}
	}
	
}

void AFPSObjective::PlayEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this, PickupFX, GetActorLocation());
}


