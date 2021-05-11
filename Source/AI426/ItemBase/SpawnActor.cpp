// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/SpawnActor.h"
#include <Components/ArrowComponent.h>

ASpawnActor::ASpawnActor()
{
	SpawnPositionArrow = CreateDefaultSubobject<UArrowComponent>("Spawn Position Arrow");
	SpawnPositionArrow->SetupAttachment(RootComponent);
}

void ASpawnActor::BeginPLay()
{
	
}

void ASpawnActor::Tick(float DeltaTime)
{
	SpawnTime += DeltaTime;

	if (SpawnTime >= TimerToSpawn)
	{
		AActor* ActorSpawn = nullptr;
		switch (SpawnerMode)
		{
		case eSpawnerMode::SINGLE_SPAWN:

			//Change with the pool implementation
			if (ActorsSpawn.Num() == 0)
			{
				ActorSpawn = GetWorld()->SpawnActor(ActorToSpawn);
				ActorsSpawn.Add(ActorSpawn);
			}

			break;
		case eSpawnerMode::MULTIPLE_SPAWN:

			ActorSpawn = GetWorld()->SpawnActor(ActorToSpawn);
			ActorsSpawn.Add(ActorSpawn);

			break;
		default:
			break;
		}
	}
}
