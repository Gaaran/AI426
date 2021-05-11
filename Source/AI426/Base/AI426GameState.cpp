// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/Base/AI426GameState.h"
#include "AI426/Manager/PoolManager.h"

void AAI426GameState::BeginPlay()
{
	if (PoolManager)
	{
		GetWorld()->SpawnActor(PoolManager);
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
