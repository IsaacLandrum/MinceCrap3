// Copyright Epic Games, Inc. All Rights Reserved.

#include "MinceCrap3GameMode.h"
#include "MinceCrap3Character.h"
#include "UObject/ConstructorHelpers.h"

AMinceCrap3GameMode::AMinceCrap3GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
