// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_AIController.generated.h"

/**
 * 
 */
class ATank;

UCLASS()
class BATTLETANK_API ATank_AIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
};
