// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/ABuffItem.h"
#include "../AI426Character.h"



void AABuffItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	if (OtherActor->IsA<AAI426Character>())
	{
		switch (ItemBuffType)
		{
		case eItemBuff::HEALTH_UP:
			//Code
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Emerald, "Health Up !");
			}

			break;

		case eItemBuff::ATTACK_UP:
			//Code
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, "Attack Up !");
			}
			break;

		case eItemBuff::DEF_UP:
			//Code
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Orange, "Def Up !");
			}
			break;
		}

		this->Destroy();//Faire une pool
	}
}
