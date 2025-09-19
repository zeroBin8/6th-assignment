// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomSpawn.h"

// Sets default values
ARandomSpawn::ARandomSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

}

// Called when the game starts or when spawned
void ARandomSpawn::BeginPlay()
{
	Super::BeginPlay();

	if (SpawnPoints.Num() > 0 && ActorToSpawn)
	{
		int32 RandomIndex = FMath::RandRange(0, SpawnPoints.Num() - 1);
		FVector SpawnLocation = SpawnPoints[RandomIndex];
		FRotator Rotator = FRotator::ZeroRotator;

		AActor* Spawned = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, Rotator);

		if (Spawned)
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					5.f,
					FColor::Green,
					FString::Printf(
						TEXT("Spawned Actor: %s at %s"),
						*Spawned->GetName(),
						*SpawnLocation.ToString()
					)
				);
			}
		}
		else
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(
					-1,
					5.f,
					FColor::Red,
					TEXT("Spawn Failed!")
				);
			}
		}
	}
	
}

// Called every frame
void ARandomSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

