// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_AIController.h"
#include "Engine/World.h"
#include "BattleTank.h"

void ATank_AIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
	}

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController couldn't find Player Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Tank: %s"), *(PlayerTank->GetName()));
	}
}

void ATank_AIController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank())
	{
		// Move toward player
		// Aim toward player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank* ATank_AIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATank_AIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}