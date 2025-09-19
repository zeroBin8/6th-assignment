// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Elevator.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API AElevator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElevator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 100.f;

	bool bMoveToStart = false;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
