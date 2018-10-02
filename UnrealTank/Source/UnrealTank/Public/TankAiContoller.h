// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "TankAiContoller.generated.h"

//Forward Declaration
class ATank;
/**
 * 
 */
UCLASS()
class UNREALTANK_API ATankAiContoller : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	ATank* GetControlledAi() const;
	ATank* GetPlayerTank() const;
	void AimTowardsPlayer();
	void Tick(float DeltaTime) override;


	
	
	
};
