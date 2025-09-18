// Fill out your copyright notice in the Description page of Project Settings.


#include "ScaleMovement.h"

// Sets default values
AScaleMovement::AScaleMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComp = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComp"));
	SetRootComponent(SceneComp);

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComp->SetupAttachment(SceneComp);

}

// Called when the game starts or when spawned
void AScaleMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScaleMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ElapsedTime += DeltaTime;

	float SinValue = FMath::Sin(ElapsedTime * (2.0f * PI) / Period);
	float Alpha = (SinValue + 1.0f) * 0.5f;

	float NewScaleX = FMath::Lerp(MinScaleZ, MaxScaleZ, Alpha);

	FVector CurrentScale = MeshComp->GetRelativeScale3D();

	MeshComp->SetRelativeScale3D(FVector(CurrentScale.X, CurrentScale.Y, NewScaleX));
}

