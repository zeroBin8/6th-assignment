// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrollOrb.h"

// Sets default values
APatrollOrb::APatrollOrb()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(MeshComp);

}

// Called when the game starts or when spawned
void APatrollOrb::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrollOrb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTIme += DeltaTime;

	float SinValue = FMath::Sin(ElapsedTIme * (2.0f * PI) / Period); //Period로 주기 조절

	float Alpha = (SinValue + 1.0f) * 0.5f;

	FVector NewLocation = FMath::Lerp(StartLocation, EndLocation, Alpha);

	SetActorLocation(NewLocation);
}

