// Copyright Epic Games, Inc. All Rights Reserved.

#include "TrackMasterWheelFront.h"
#include "UObject/ConstructorHelpers.h"

UTrackMasterWheelFront::UTrackMasterWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}