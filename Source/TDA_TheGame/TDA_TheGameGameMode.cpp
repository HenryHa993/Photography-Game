// Copyright Epic Games, Inc. All Rights Reserved.

#include "TDA_TheGameGameMode.h"
#include "TDA_TheGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATDA_TheGameGameMode::ATDA_TheGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
