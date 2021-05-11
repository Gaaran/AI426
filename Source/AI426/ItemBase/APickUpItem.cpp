// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/APickUpItem.h"
#include <Components/BoxComponent.h>

AAPickUpItem::AAPickUpItem()
{
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	TriggerBox->SetupAttachment(SceneComponent);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AAPickUpItem::OnOverlapBegin);
}

void AAPickUpItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
}
