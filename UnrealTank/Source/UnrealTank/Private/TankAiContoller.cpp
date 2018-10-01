// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAiContoller.h"

void ATankAiContoller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank()) {
		//TODO move Towards Player
		AimTowardsPlayer();
		//TODO Fire if Ready

	}
	
}


ATank* ATankAiContoller::GetControlledAi() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAiContoller::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledAiTank = GetControlledAi();

	if (!ControlledAiTank) {

		UE_LOG(LogTemp, Warning, TEXT("No Tank Possesed"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("The AI posses: %s"), *(ControlledAiTank->GetName()));
	}
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {

		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Ai Spotted Player: %s"), *(PlayerTank->GetName()));
	}

}

ATank* ATankAiContoller::GetPlayerTank() const
{
	auto PlayerTankPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTankPawn) { return nullptr; }
	return Cast<ATank>(PlayerTankPawn);
}

void ATankAiContoller::AimTowardsPlayer()
{
	//Aim at the Player location
	GetControlledAi()->AimAt(GetPlayerTank()->GetActorLocation());
}


