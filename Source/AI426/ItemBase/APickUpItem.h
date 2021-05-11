// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426/ItemBase/APlaceable.h"
#include "APickUpItem.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API AAPickUpItem : public AAPlaceable
{
	GENERATED_BODY()

public:
	AAPickUpItem();

protected:
	
	
	UPROPERTY(EditAnywhere, Category = "AI426")
	class UBoxComponent* TriggerBox;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
};
