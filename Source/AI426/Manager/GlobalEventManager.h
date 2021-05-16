// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlobalEventManager.generated.h"

//Item Event
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FItemPickUp, class AActor*, ItemPickedUp);

UCLASS()
class AI426_API AGlobalEventManager : public AActor
{
	GENERATED_BODY()
	
public:	

	FItemPickUp EventItemPickUp;

};
