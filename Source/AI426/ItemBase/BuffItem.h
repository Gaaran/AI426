// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426/ItemBase/PickUpItem.h"
#include "AI426/Enums/ItemEnum.h"
#include "BuffItem.generated.h"
/**
 * 
 */
UCLASS()
class AI426_API ABuffItem : public APickUpItem
{
	GENERATED_BODY()
	
public:

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "AI426")
	eItemBuff ItemBuffType = eItemBuff::HEALTH_UP;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

};
