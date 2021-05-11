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
