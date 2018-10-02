// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "UnrealTank.h"





void UTankBarrel::Elevate(float RealtiveSpeed) 
{
	
	//Move the Barrels to the right Height
	RealtiveSpeed = FMath::Clamp<float>(RealtiveSpeed, -1, 1);
	auto ElevationChange = RealtiveSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

		
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}


