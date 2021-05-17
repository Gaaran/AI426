// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "AI426GameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGEMCreated, class AGlobalEventManager*, EventManager);

/**
 * 
 */
UCLASS()
class AI426_API AAI426GameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = "AI426 | Manager")
	FORCEINLINE class AGlobalEventManager* GetGEM() const
	{
		return GEM;
	}
	UFUNCTION(BlueprintCallable, Category = "AI426 | Manager")
	FORCEINLINE class APoolManager* GetPoolManager() const
	{
		return PoolManager;
	}

	FGEMCreated EventGEMCreated;

#pragma region DEBUGMESSAGE

	static void DebugMessage(FString Message = "Debug Message On Screen", float MessageTimeOnScreen = 5.0f,
		FColor Messagecolor = FColor::Emerald);
	static void DebugLogMessage(FString LogMessage);
#pragma endregion

protected:

	UPROPERTY(EditAnywhere, Category = "AI426 | Managers")
	TSubclassOf<class APoolManager> TSubPoolManager;

	UPROPERTY()
	class APoolManager* PoolManager;

	UPROPERTY(EditAnywhere, Category = "AI426 | Managers")
		TSubclassOf<class AGlobalEventManager> TSubGEM;

	UPROPERTY()
		class AGlobalEventManager* GEM;


};
