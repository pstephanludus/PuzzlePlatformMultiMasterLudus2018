// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Puzzle_Multi_MasterGameMode.h"
#include "Puzzle_Multi_MasterCharacter.h"
#include "UObject/ConstructorHelpers.h"

APuzzle_Multi_MasterGameMode::APuzzle_Multi_MasterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
