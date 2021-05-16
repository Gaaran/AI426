// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/SpawnActor.h"
#include <Components/ArrowComponent.h>
#include "../Base/AI426GameState.h"
#include "../Manager/GlobalEventManager.h"

ASpawnActor::ASpawnActor()
{
	SpawnPositionArrow = CreateDefaultSubobject<UArrowComponent>("Spawn Position Arrow");
	SpawnPositionArrow->SetupAttachment(RootComponent);
}

void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();

	GS = GetWorld()->GetGameState<AAI426GameState>();

	FTimerHandle timerHandler;
	GetWorldTimerManager().SetTimer(timerHandler, this, &ASpawnActor::SpawnNewActor, TimerToSpawn, false);

	if (SpawnerMode == eSpawnerMode::SINGLE_SPAWN && GS && GS->GetGEM())
	{
		GS->GetGEM()->EventItemPickUp.AddDynamic(this, &ASpawnActor::ItemPickedUp);
	}
}

void ASpawnActor::Tick(float DeltaTime)
{
	//SpawnTime += DeltaTime;

	//if (SpawnTime >= TimerToSpawn)
	//{
	//	AActor* ActorSpawn = nullptr;

	//	int32 DrawNumber = FMath::RandRange(0, ActorsToSpawn.Num() - 1);
	//	if (!ActorsToSpawn.IsValidIndex(DrawNumber))
	//	{
	//		return;
	//	}

	//	switch (SpawnerMode)
	//	{
	//	case eSpawnerMode::SINGLE_SPAWN:

	//		//Change with the pool implementation
	//		if (ActorsSpawn.Num() == 0)
	//		{
	//			ActorSpawn = GetWorld()->SpawnActor(ActorsToSpawn[DrawNumber]);
	//			if (ActorSpawn)
	//			{
	//				ActorSpawn->SetActorTransform(SpawnPositionArrow->GetComponentTransform());
	//				ActorSpawn->SetOwner(this);
	//				ActorsSpawn.Add(ActorSpawn);
	//			}
	//		}

	//		break;
	//	case eSpawnerMode::MULTIPLE_SPAWN:

	//		ActorSpawn = GetWorld()->SpawnActor(ActorsToSpawn[DrawNumber]);
	//		if (ActorSpawn)
	//		{
	//			ActorSpawn->SetOwner(this);
	//		}
	//		ActorsSpawn.Add(ActorSpawn);

	//		break;
	//	default:
	//		break;
	//	}

	//	SpawnTime = 0.0f;
	//}
}

void ASpawnActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	if (GS && GS->GetGEM())
	{
		GS->GetGEM()->EventItemPickUp.RemoveDynamic(this, &ASpawnActor::ItemPickedUp);
	}
}

void ASpawnActor::RemoveItemFromSpawn(AActor* ActorToRemove)
{
	ActorsSpawn.Remove(ActorToRemove);
}

void ASpawnActor::SpawnNewActor()
{
	AActor* ActorSpawn = nullptr;

	int32 DrawNumber = FMath::RandRange(0, ActorsToSpawn.Num() - 1);
	if (!ActorsToSpawn.IsValidIndex(DrawNumber))
	{
		return;
	}

	//Change with the pool implementation
	if (ActorsSpawn.Num() == 0)
	{
		ActorSpawn = GetWorld()->SpawnActor(ActorsToSpawn[DrawNumber]);
		if (ActorSpawn)
		{
			ActorSpawn->SetActorTransform(SpawnPositionArrow->GetComponentTransform());
			ActorSpawn->SetOwner(this);
			ActorsSpawn.Add(ActorSpawn);
		}
	}
}


void ASpawnActor::ItemPickedUp(AActor* ItemEventPickUp)
{
	if (ItemEventPickUp == ActorsSpawn[0])
	{
		FTimerHandle timerHandler;
		GetWorldTimerManager().SetTimer(timerHandler, this, &ASpawnActor::SpawnNewActor, TimerToSpawn, false);
	}
}
