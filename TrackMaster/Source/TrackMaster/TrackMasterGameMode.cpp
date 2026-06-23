// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrackMasterGameMode.h"
#include "TrackMasterPlayerController.h"

ATrackMasterGameMode::ATrackMasterGameMode()
{
	PlayerControllerClass = ATrackMasterPlayerController::StaticClass();
}
