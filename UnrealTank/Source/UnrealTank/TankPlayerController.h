// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALTANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
		ATank* GetControlledTank() const;
		
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;
		bool GetSightRayHitLocation(FVector &HitLocation) const;

private:
	//Moving Barrels to Crosshair
	void AimTowardsCrosshair();
	UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.5;
	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
	

	
	
	
};

