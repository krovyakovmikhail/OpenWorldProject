// Copyright Epic Games, Inc. All Rights Reserved.
#include "MyOpenWorldGameModeBase.h"
#include "OpenWorld_Character.h"
#include "OpenWorld_PlayerController.h"



AMyOpenWorldGameModeBase::AMyOpenWorldGameModeBase()
{
	DefaultPawnClass = AOpenWorld_Character::StaticClass();
	PlayerControllerClass = AOpenWorld_PlayerController::StaticClass();


}
