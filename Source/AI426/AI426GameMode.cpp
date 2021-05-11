// Copyright Epic Games, Inc. All Rights Reserved.

#include "AI426GameMode.h"
#include "AI426Character.h"
#include "UObject/ConstructorHelpers.h"

AAI426GameMode::AAI426GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
