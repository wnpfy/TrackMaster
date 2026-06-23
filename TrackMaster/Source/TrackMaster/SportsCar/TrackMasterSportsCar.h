// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "TrackMasterPawn.h"
#include "TrackMasterSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class ATrackMasterSportsCar : public ATrackMasterPawn
{
	GENERATED_BODY()
	
public:

	ATrackMasterSportsCar();
};
