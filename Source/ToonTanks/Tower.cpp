// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Find the distance to the Tank
    if (InFireRange())
    {

        RotateTurret(Tank->GetActorLocation());

    }
  
    

    // If in range, rotate turret toward Tank
}


void ATower::BeginPlay()
{

	Super::BeginPlay();



	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

    // Ask this Actor's world for its Timer Manager, then schedule a repeating timer
    GetWorldTimerManager().SetTimer(
        FireRateTimerHandle,              // Handle: an ID tag for this timer (lets you pause/clear/check it later)
        this,                             // Object: the specific instance of ATower the function will be called on
        &ATower::CheckFireCondition,      // Function: pointer to the member function to call when the timer fires
        FireRate,                         // Rate: how many seconds between calls (the interval)
        true                              // Looping: true = repeat forever, false = call once then stop
    );


}

void ATower::CheckFireCondition()
{
    if (Tank == nullptr)
    {
        return;
    }
    if (InFireRange() && Tank->bAlive)
    {
        Fire();
    }
    
}

bool ATower::InFireRange()
{
    if (Tank)
    {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        if (Distance <= FireRange)
        {
            return true;
        }

    }
    return false;
}

void ATower::HandleDestruction()
{
    Super::HandleDestruction();
    Destroy();
}