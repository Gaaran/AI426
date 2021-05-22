// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426Character.h"
#include "AI426PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API AAI426PlayerCharacter : public AAI426Character
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	

protected:
	UPROPERTY()
	class AAI426GameState* GS;
	
	UPROPERTY(EditAnywhere, Category = "AI426")
	int32 TraceDistance = 25;
	UPROPERTY()
	class AInteractable* CurrentInteractable;

	//Interaction
	UFUNCTION()
	void GetInteractable();

};
