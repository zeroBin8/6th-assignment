// Fill out your copyright notice in the Description page of Project Settings.


#include "Elevator.h"

// Sets default values
AElevator::AElevator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(MeshComp);
}

// Called when the game starts or when spawned
void AElevator::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AElevator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	FVector TargetLocation;

	if (bMoveToStart)
	{
		TargetLocation = StartLocation;
	}
	else
	{
		TargetLocation = EndLocation;
	}

	FVector NewLocation = FMath::VInterpTo(CurrentLocation, TargetLocation, DeltaTime, MoveSpeed);
	SetActorLocation(NewLocation);

	if (FVector::Dist(CurrentLocation, TargetLocation) < 1.f)
	{
		bMoveToStart = !bMoveToStart;
	}
}

