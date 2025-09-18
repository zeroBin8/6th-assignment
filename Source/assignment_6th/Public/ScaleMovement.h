// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScaleMovement.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API AScaleMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScaleMovement();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Scaling")
	float MaxScaleZ = 2.f; // 최대 스케일

	UPROPERTY(EditAnywhere, Category = "Scaling")
	float MinScaleZ = 0.5f; // 최소 스케일

	UPROPERTY(EditAnywhere, Category = "Scaling")
	float Period = 2.f; // 한 사이클 시간

	float ElapsedTime = 0.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
