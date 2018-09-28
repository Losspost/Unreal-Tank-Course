// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealTank.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		
		UE_LOG(LogTemp, Warning, TEXT("No Tank Possesed"));
	}
	UE_LOG(LogTemp, Warning, TEXT("You posses: %s"), *(ControlledTank->GetName()));
}

ATank* ATankPlayerController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
    
}


