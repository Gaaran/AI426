// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426/ItemBase/Placeable.h"
#include "AI426/Enums/ItemEnum.h"
#include "SpawnActor.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API ASpawnActor : public APlaceable
{
	GENERATED_BODY()
	
public:
	ASpawnActor();

	UFUNCTION()
	void RemoveItemFromSpawn(AActor* ActorToRemove);

protected:


	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY()
	class AAI426GameState* GS;

	UPROPERTY(EditAnywhere, Category = "AI426")
	int32 LimitActorToSpawn = 1;

	UPROPERTY(EditAnywhere, Category = "AI426")
	float TimerToSpawn = 5.0f;

	/*UPROPERTY()
	float SpawnTime = 0.0f;*/

	UPROPERTY(EditAnywhere, Category = "AI426")
	class UArrowComponent* SpawnPositionArrow;

	UPROPERTY(EditAnywhere, Category = "AI426")
	eSpawnerMode SpawnerMode = eSpawnerMode::SINGLE_SPAWN;

	UPROPERTY(EditAnywhere, Category = "")
	TArray<TSubclassOf<AActor>> ActorsToSpawn;

	UPROPERTY()
	TArray<AActor*> ActorsSpawn;

	UFUNCTION()
	void SpawnNewActor();

	UFUNCTION()
	void ItemPickedUp(AActor* ItemEventPickUp);
};
