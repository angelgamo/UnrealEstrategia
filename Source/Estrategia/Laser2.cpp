// Fill out your copyright notice in the Description page of Project Settings.


#include "Laser2.h"

#include "Enemy.h"
#include "GIMP.h"
#include "TowWrapper.h"

void ULaser2::EndTick()
{
	Super::EndTick();

	towerActive = true;
	StopShoot(EnemiesInRange[closestIndex]);
	if (EnemiesInRange[closestIndex])
		EnemiesInRange[closestIndex]->evReceiveDamage.Broadcast(Damage);
}

void ULaser2::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!towerActive) return;

	if (!aguinp->enemies.IsEmpty())
	{
		EnemiesInRange.Empty();
		closestDistance = RangeAttack;

		for (auto& enemy : aguinp->enemies)
		{
			float dist = FVector::Dist(selfActor->GetActorLocation(), enemy->GetActorLocation());
			if (closestDistance > dist)
			{
				closestDistance = dist;
				EnemiesInRange.Add(enemy);
			}
		}

		if (!EnemiesInRange.IsEmpty())
		{
			closestDistance = 10000000.0f;
			closestIndex = -1;
			int index = 0;
			for (auto& enemy : EnemiesInRange)
			{
				float dist = FVector::DistSquared(enemy->GetActorLocation(), FVector::Zero());
				if (closestDistance > dist)
				{
					closestDistance = dist;
					closestIndex = index;
				}
				index++;
			}
			Shoot(EnemiesInRange[closestIndex]);
			towerActive = false;
			GetWorld()->GetTimerManager().SetTimer(th, this, &ULaser2::EndTick, DelayAttack, false);
		}
		else
		{
			StopShoot(nullptr);
		}
	}
}