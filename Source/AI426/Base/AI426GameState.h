// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AI426GameState.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API AAI426GameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay();


protected:

	UPROPERTY(EditAnywhere, Category = "AI426 | Managers")
	TSubclassOf<class APoolManager> PoolManager;
};
