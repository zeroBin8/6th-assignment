// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerWall.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API ATimerWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, Category = "Timer")
	float Time = 5.f;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, Category = "Spawn")
	FVector SpawnLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector TargetLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 100.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float DeletionDistance = 10.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle SpawnTimerHandle;
	AActor* SpawnedActor = nullptr; // 스폰된 액터 추적

	void SpawnActorAfterDelay(); //timer에서 사용할 함수
};
