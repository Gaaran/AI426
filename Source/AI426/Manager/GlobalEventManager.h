// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GlobalEventManager.generated.h"


DECLARE_DELEGATE(FItemPickUp)

UCLASS()
class AI426_API AGlobalEventManager : public AActor
{
	GENERATED_BODY()
	
public:	

	FItemPickUp EventItemPickUp;

};
