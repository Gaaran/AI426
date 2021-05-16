// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/PickUpItem.h"
#include <Components/BoxComponent.h>
#include "../Base/AI426GameState.h"

APickUpItem::APickUpItem()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(SceneComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &APickUpItem::OnOverlapBegin);
}

void APickUpItem::BeginPlay()
{
	GS = GetWorld()->GetGameState<AAI426GameState>();
}

void APickUpItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}
