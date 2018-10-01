// Fill out your copyright notice in the Description page of Project Settings.

#include "UnrealTank.h"
#include "TankBarrel.h"



void UTankBarrel::Elevate(float DegreesPerSecond) 
{
	auto Time = GetWorld()->GetTimeSeconds();
	//Move the Barrels to the right Height
	UE_LOG(LogTemp,Warning,TEXT("%f :DEGRESS:%f"),Time , DegreesPerSecond)
}


