// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawn.generated.h"

UCLASS()
class ASSIGNMENT_6TH_API ARandomSpawn : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Component")
	USceneComponent* SceneComp;

	UPROPERTY(EditAnywhere, Category = "Spawn") //스폰 좌표 저장
	TArray<FVector> SpawnPoints;

	UPROPERTY(EditAnywhere, Category = "Spawn") //스폰할 액터를 지정할 변수
	TSubclassOf<AActor> ActorToSpawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
