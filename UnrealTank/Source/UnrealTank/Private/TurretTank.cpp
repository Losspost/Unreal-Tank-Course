// Fill out your copyright notice in the Description page of Project Settings.
#include "TurretTank.h"
#include "UnrealTank.h"




void UTurretTank::Turn(float RelativeSpeed)
{

	//Move the Barrels to the right Height
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecondTurret * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
//	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);


	SetRelativeRotation(FRotator(0, RawNewElevation, 0));
}
