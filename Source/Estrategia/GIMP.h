// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GIMP.generated.h"

/**
 * 
 */
UCLASS()
class ESTRATEGIA_API AGIMP : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<class AEnemy*> enemies;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void AddEnemy(class AEnemy* enemy)
	{
		if (enemy)
			enemies.Add(&*enemy);
	}

	UFUNCTION(BlueprintCallable)
	FORCEINLINE void RemoveEnemy(class AEnemy* enemy)
	{
		if (enemy)
			enemies.Remove(&*enemy);
	}
};
