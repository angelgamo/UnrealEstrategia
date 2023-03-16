// Fill out your copyright notice in the Description page of Project Settings.


#include "Tesla2.h"

#include "Enemy.h"
#include "GIMP.h"
#include "TowWrapper.h"

void UTesla2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!towerActive) return;

	if (!aguinp->enemies.IsEmpty())
	{
		EnemiesInRange.Empty();
		for (auto& enemy : aguinp->enemies)
			if (RangeAttack > FVector::Dist(selfActor->GetActorLocation(), enemy->GetActorLocation()))
				EnemiesInRange.Add(enemy);
		if (!EnemiesInRange.IsEmpty())
		{
			Shoot(nullptr);
			for (auto& enemy : EnemiesInRange)
				if (enemy)
					enemy->evReceiveDamage.Broadcast(Damage);
			towerActive = false;
			GetWorld()->GetTimerManager().SetTimer(th, this, &UTesla2::EndTick, DelayAttack, false);
		}
		else
		{
			StopShoot(nullptr);
		}
	}
}

void UTesla2::EndTick()
{
	Super::EndTick();
	
	towerActive = true;
	StopShoot(nullptr);
}
