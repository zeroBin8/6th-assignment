// Fill out your copyright notice in the Description page of Project Settings.


#include "EndPointStar.h"

// Sets default values
AEndPointStar::AEndPointStar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
}

// Called when the game starts or when spawned
void AEndPointStar::BeginPlay()
{
	Super::BeginPlay();

	CenterLocation = GetActorLocation();
	
}

// Called every frame
void AEndPointStar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapseTime += DeltaTime;

	FRotator Rotation(0.f, -RotationSpeed * DeltaTime, 0.f);
	AddActorLocalRotation(Rotation);

	float Angle = ElapseTime * (2.0f * PI) / Period;

	float NewX = CenterLocation.X + Radius * FMath::Cos(Angle);
	float NewY = CenterLocation.Y + Radius * FMath::Sin(Angle);

	SetActorLocation(FVector(NewX, NewY, CenterLocation.Z));
}

