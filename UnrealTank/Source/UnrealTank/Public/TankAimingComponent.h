// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"



class UTankBarrel; //Forward Declaration
class UTurretTank;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALTANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector WoldSpaceAim,float LaunchSpeed);
	//Set The Reference in the BluePrints
	void SetBarrelReference(UTankBarrel *BarrelToSet);
	//Set The Reference for the Turret
	void setTurretReference(UTurretTank *TurretToSet);
private:
	UTankBarrel *Barrel = nullptr;
	UTurretTank *Turret = nullptr;
	void MoveBarrelTowards(FVector AimDirection);
};
