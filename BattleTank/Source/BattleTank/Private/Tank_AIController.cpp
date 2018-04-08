// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_AIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "BattleTank.h"

void ATank_AIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATank_AIController::Tick(float DeltaSeconds) 
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!PlayerTank) { return; }
	if (!ControlledTank) { return; }
	if (PlayerTank)
	{
		// Move toward player
		// Aim toward player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		// Fire if ready
		ControlledTank->Fire();
	}
}