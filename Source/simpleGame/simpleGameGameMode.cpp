// Copyright Epic Games, Inc. All Rights Reserved.

#include "simpleGameGameMode.h"
#include "simpleGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AsimpleGameGameMode::AsimpleGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
