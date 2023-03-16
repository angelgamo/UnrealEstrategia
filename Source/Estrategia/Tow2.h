// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Tow2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESTRATEGIA_API UTow2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTow2();
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class AGIMP* aguinp;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName TowName;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UPaperSprite* TowSprite;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UStaticMesh* TowMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class ATowWrapper* selfActor;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool towerActive;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float closestDistance;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int closestIndex;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	class UParticleSystem* ParticlesTemplate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Damage;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DelayAttack;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RangeAttack;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<class AEnemy*> EnemiesInRange;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Gold;
	FTimerHandle th;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void Shoot(class AActor* enemy);
	UFUNCTION(BlueprintCallable)
	void StopShoot(class AEnemy* enemy);
	UFUNCTION(BlueprintCallable)
	virtual void EndTick() {};
};
