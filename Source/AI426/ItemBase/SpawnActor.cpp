// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/SpawnActor.h"

void ASpawnActor::BeginPLay()
{
	
}

void ASpawnActor::Tick(float DeltaTime)
{
	SpawnTime += DeltaTime;

	if (SpawnTime >= TimerToSpawn)
	{
		switch (SpawnerMode)
		{
		case eSpawnerMode::SINGLE_SPAWN:

			//Change with the pool implementation
			GetWorld()->SpawnActor(ActorToSpawn);

			break;
		case eSpawnerMode::MULTIPLE_SPAWN:
			break;
		case eSpawnerMode::MAX:
			break;
		default:
			break;
		}
	}
}
