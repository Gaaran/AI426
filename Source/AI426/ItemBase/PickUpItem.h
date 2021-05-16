// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426/ItemBase/Placeable.h"
#include "PickUpItem.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API APickUpItem : public APlaceable
{
	GENERATED_BODY()

public:
	APickUpItem();

	virtual void BeginPlay() override;
protected:
	
	UPROPERTY()
	class AAI426GameState* GS;

	UPROPERTY(EditAnywhere, Category = "AI426")
	class UBoxComponent* TriggerBox;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
