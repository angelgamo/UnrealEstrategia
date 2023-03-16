// Fill out your copyright notice in the Description page of Project Settings.


#include "Tow2.h"

#include "TowWrapper.h"
#include "Enemy.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values for this component's properties
UTow2::UTow2()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTow2::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTow2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTow2::Shoot(class AActor* enemy)
{
	if(!selfActor) return;
	
	if (enemy)
		selfActor->GetParicleSystem()->SetActorParameter(FName("Target"), enemy);
	selfActor->GetParicleSystem()->SetActive(true);
}

void UTow2::StopShoot(class AEnemy* enemy)
{
	if (!enemy)
		selfActor->GetParicleSystem()->SetActive(false, true);
}