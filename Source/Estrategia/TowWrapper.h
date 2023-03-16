// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Particles/ParticleSystemComponent.h"
#include "TowWrapper.generated.h"

UCLASS()
class ESTRATEGIA_API ATowWrapper : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATowWrapper();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UParticleSystemComponent> mParicleSys;
	// UPROPERTY(BlueprintReadWrite, EditAnywhere)
	// UParticleSystemComponent mPart2;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	FORCEINLINE UParticleSystemComponent* GetParicleSystem() { return mParicleSys.Get(); }
};
