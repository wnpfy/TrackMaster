// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrackMasterWheelRear.h"
#include "UObject/ConstructorHelpers.h"

UTrackMasterWheelRear::UTrackMasterWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}