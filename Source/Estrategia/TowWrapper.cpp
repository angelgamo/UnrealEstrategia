// Fill out your copyright notice in the Description page of Project Settings.


#include "TowWrapper.h"

// Sets default values
ATowWrapper::ATowWrapper()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// mParicleSys = CreateDefaultSubobject<UParticleSystemComponent>(FName("Particles2"));
}

// Called when the game starts or when spawned
void ATowWrapper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATowWrapper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATowWrapper::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

