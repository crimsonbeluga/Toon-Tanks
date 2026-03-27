// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTanksPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank)
	{
		Tank->HandleDestruction();
		if (ToonTanksPlayerController)
		{
			ToonTanksPlayerController->SetPlayerEnabledState(false);
		}
		EndGame(false);
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor))
	{
		DestroyedTower->HandleDestruction();

		TargetTowers--;
		if (TargetTowers == 0)
		{
			EndGame(true);
		}
	}
}


void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	HandleGameStart();
	// Inside your class function:
	

	// -----------------------------------------------------------------------------
	// 1. UGameplayStatics::GetPlayerPawn(this, 0)
	//    - Calls a static helper function from Unreal's GameplayStatics class.
	//    - 'this' provides the world context (so the function knows *which world* to look in).
	//    - The '0' means we’re asking for PlayerIndex 0 (the first/local player).
	//    - This function returns an APawn* (the base class for any controllable character).
	// -----------------------------------------------------------------------------

	// -----------------------------------------------------------------------------
	// 2. Cast<ATank>( ... )
	//    - 'Cast' is Unreal's safe casting function template.
	//    - We tell it: "Try to interpret this APawn* as an ATank*."
	//    - If the pawn returned is actually of type ATank (or a subclass of ATank):
	//         → the cast succeeds, and we get a valid pointer to that ATank object.
	//    - If it’s not actually a Tank (maybe it’s some other pawn type):
	//         → the cast fails safely and returns nullptr (instead of crashing).
	// -----------------------------------------------------------------------------

	// -----------------------------------------------------------------------------
	// 3. Tank = ...
	//    - 'Tank' is a member variable of type ATank* in your class.
	//    - We assign the result of the cast to Tank.
	//    - After this line:
	//         • If player 0’s pawn is an ATank, Tank now points to that object.
	//         • If not, Tank will be nullptr, and we can check (if(Tank)) later
	//           to avoid calling functions on an invalid pointer.
	// -----------------------------------------------------------------------------


	
}
void AToonTanksGameMode::HandleGameStart()
{
	TargetTowers = TrackTowerCount();
	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));

	ToonTanksPlayerController = Cast< AToonTanksPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	StartGame();

	if (ToonTanksPlayerController)
	{
		ToonTanksPlayerController->SetPlayerEnabledState(false);

		FTimerHandle PlayerEnableTiimerHandle;

		FTimerDelegate StartGameTimerDelegate = FTimerDelegate::CreateUObject(
			ToonTanksPlayerController,
			&AToonTanksPlayerController::SetPlayerEnabledState,
			true
		);

		GetWorldTimerManager().SetTimer(PlayerEnableTiimerHandle, StartGameTimerDelegate, StartDelay, false);

	}
}

int32 AToonTanksGameMode::TrackTowerCount()
{

	TArray <AActor*> Towers;  /*Were creating an array thats set to store a list of actors specifically are towers*/

	UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);

	return Towers.Num();
	
}