// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StickRotation.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API AStickRotation : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStickRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Rotation")
	FVector RotationSpeed;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
