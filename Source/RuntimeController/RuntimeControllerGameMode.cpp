// Copyright Epic Games, Inc. All Rights Reserved.

#include "RuntimeControllerGameMode.h"
#include "RuntimeControllerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARuntimeControllerGameMode::ARuntimeControllerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
