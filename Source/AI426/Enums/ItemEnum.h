// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemEnum.generated.h"

UENUM(BlueprintType, Category = "AI426 | Enums")
enum class eItemBuff : uint8
{
	HEALTH_UP,
	ATTACK_UP,
	DEF_UP,
	MAX
};

UENUM(BlueprintType, Category = "AI426 | Enums")
enum class eSpawnerMode : uint8
{
	SINGLE_SPAWN,
	MULTIPLE_SPAWN,
	MAX
};