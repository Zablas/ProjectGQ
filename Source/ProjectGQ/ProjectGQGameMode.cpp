// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectGQGameMode.h"
#include "ProjectGQHUD.h"
#include "ProjectGQCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjectGQGameMode::AProjectGQGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjectGQHUD::StaticClass();
}
