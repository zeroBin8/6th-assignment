// Fill out your copyright notice in the Description page of Project Settings.


#include "StickRotation.h"

// Sets default values
AStickRotation::AStickRotation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(SceneComp);

}

// Called when the game starts or when spawned
void AStickRotation::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStickRotation::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator DeltaRotation = FRotator(RotationSpeed.X, RotationSpeed.Y, RotationSpeed.Z) * DeltaTime;
	StaticMesh->AddLocalRotation(DeltaRotation);
}

