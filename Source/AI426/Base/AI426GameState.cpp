// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/Base/AI426GameState.h"
#include "AI426/Manager/PoolManager.h"
#include "../Manager/GlobalEventManager.h"

void AAI426GameState::BeginPlay()
{
	Super::BeginPlay();

	if (TSubPoolManager)
	{
		AActor* ActorSpawn = GetWorld()->SpawnActor(TSubPoolManager);
		PoolManager = Cast<APoolManager>(ActorSpawn);
	}

	if (TSubGEM)
	{
		AActor* ActorSpawn = GetWorld()->SpawnActor(TSubGEM);
		GEM = Cast<AGlobalEventManager>(ActorSpawn);

		EventGEMCreated.Broadcast(GEM);
	}
}

void AAI426GameState::DebugMessage(FString Message /*= "Debug Message On Screen"*/, float MessageTimeOnScreen /*= 5.0f*/, FColor Messagecolor /*= FColor::Emerald*/)
{
#if WITH_EDITOR
	GEngine->AddOnScreenDebugMessage(-1, MessageTimeOnScreen, Messagecolor, Message);
#endif
}

void AAI426GameState::DebugLogMessage(FString LogMessage)
{
#if WITH_EDITOR
	UE_LOG(LogTemp, Warning, TEXT("%s"), *LogMessage);
#endif
}
