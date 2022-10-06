// Copyright Epic Games, Inc. All Rights Reserved.

#include "AmberGameMode.h"
#include "AmberCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAmberGameMode::AAmberGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_AmberPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
