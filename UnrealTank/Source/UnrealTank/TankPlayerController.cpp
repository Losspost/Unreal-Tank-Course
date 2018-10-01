// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "UnrealTank.h"

//OnTick
	//Super
	//AimTowardsCrosshairs()

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		
		UE_LOG(LogTemp, Warning, TEXT("No Tank Possesed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("You posses: %s"), *(ControlledTank->GetName()));
	}
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}


void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//Get the neccessarry location to trace the crosshair
	//Fector of the CrossHair
	FVector HitLocation;//Out Parameter
	if (GetSightRayHitLocation(HitLocation)) {
		//Todo Aim at Tank
		
		GetControlledTank()->AimAt(HitLocation);
	}
	
}
//Ray Traycing through Crosshair, true if its hit Landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX,ViewportSizeY);
	
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	FVector LookDirection;
	
	if (GetLookDirection(ScreenLocation, LookDirection))
	{

		//if We hit Linetrace at hitpoint
		GetLookVectorHitLocation(LookDirection, HitLocation);

	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const
{

	//Get The Worlddirection we are looking at
	FVector MyWorldLocation;//To be Discarded
	DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		MyWorldLocation,
		LookDirection);

	return  true;

}
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
	
}

