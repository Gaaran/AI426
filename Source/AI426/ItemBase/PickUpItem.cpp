// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/PickUpItem.h"
#include <Components/BoxComponent.h>

APickUpItem::APickUpItem()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(SceneComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &APickUpItem::OnOverlapBegin);
}

void APickUpItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}
