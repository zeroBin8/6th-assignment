// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWall.h"

// Sets default values
ATimerWall::ATimerWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);
}

// Called when the game starts or when spawned
void ATimerWall::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorld()->GetTimerManager().SetTimer(
		SpawnTimerHandle,
		this,
		&ATimerWall::SpawnActorAfterDelay,
		Time,
		false
	);
}

// Called every frame
void ATimerWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpawnedActor)
	{
		FVector CurrentLocation = SpawnedActor->GetActorLocation();
		FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation,DeltaTime, MoveSpeed);

		SpawnedActor->SetActorLocation(NewLocation);

		float DistanceToTarget = FVector::Dist(CurrentLocation, TargetLocation);

		if (DistanceToTarget <= DeletionDistance)
		{
			SpawnedActor->Destroy(); // 스폰된 액터 삭제
			SpawnedActor = nullptr;  // Tick에서 접근하지 않도록 null 처리
		}
	}
}

void ATimerWall::SpawnActorAfterDelay()
{
	if (ActorToSpawn)
	{
		FRotator SpawnRotation = FRotator::ZeroRotator;
		SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, SpawnRotation);
	}
}

