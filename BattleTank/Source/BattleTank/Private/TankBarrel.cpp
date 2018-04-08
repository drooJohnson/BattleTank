// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move correct amount this frame
	// Give max rotations to constrain with
	UE_LOG(LogTemp, Warning, TEXT("Barrel Elevate called at speed %f"), DegreesPerSecond);
}


