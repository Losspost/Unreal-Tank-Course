// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward Declaration
class UTankAimingComponent;
class UTankBarrel;
class UTurretTank;

UCLASS()
class UNREALTANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Aiming Objects
	UTankAimingComponent *TankAimingComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector Hitlocation);
	//Callabale as function in BluePrint
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel *BarrelToSet);

	//Callable as function in BluePrint
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTurretTank *TurretToSet);
	//Callable Variable in BluePrint
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000;
	
	
};
