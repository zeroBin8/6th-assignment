// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndPointStar.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API AEndPointStar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEndPointStar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	float RotationSpeed = 90.f;

	UPROPERTY(EditAnywhere, Category = "CircularMove")
	float Period = 2.f;

	UPROPERTY(EditAnywhere, Category = "CircularMove")
	float Radius = 200.f;

	FVector CenterLocation;

	float ElapseTime = 0.f;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
