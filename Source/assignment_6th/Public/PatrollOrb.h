// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrollOrb.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API APatrollOrb : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrollOrb();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector EndLocation;

	UPROPERTY(EditAnywhere, Category = "Movement") //sin의 주기
	float Period = 2.0f;

	float ElapsedTIme = 0.f; //누적 시간

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
