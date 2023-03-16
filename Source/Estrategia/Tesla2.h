// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tow2.h"
#include "Tesla2.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ESTRATEGIA_API UTesla2 : public UTow2
{
	GENERATED_BODY()

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void EndTick() override;
};
