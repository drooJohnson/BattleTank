// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_AIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATank_AIController : public AAIController
{
	GENERATED_BODY()

private:
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;

	virtual void BeginPlay() override;
};
