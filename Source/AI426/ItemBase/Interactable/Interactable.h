// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI426/ItemBase/Placeable.h"
#include "Interactable.generated.h"

/**
 * 
 */
UCLASS()
class AI426_API AInteractable : public APlaceable
{
	GENERATED_BODY()

public:
	virtual void OnInteraction();

protected:
	
};
