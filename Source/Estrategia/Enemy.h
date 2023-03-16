// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceiveDamage, int, damage);

UCLASS()
class ESTRATEGIA_API AEnemy : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class AGIMP* aguinp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable)
	FReceiveDamage evReceiveDamage;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
