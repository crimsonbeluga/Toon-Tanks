#include "SawTooth.h"

ASawTooth::ASawTooth()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASawTooth::BeginPlay()
{
	Super::BeginPlay();

	startLocation = GetActorLocation();
	endLocation = startLocation + FVector(xmoveDistance, ymoveDistance, zmoveDistance);
}

void ASawTooth::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SawToothMovement(DeltaTime);
}

void ASawTooth::SawToothMovement(float DeltaTime)
{
	FVector current = GetActorLocation();
	FVector target;

	// Choose target based on direction flags
	if (bMovingTowardEndX)
		target.X = endLocation.X;
	else
		target.X = startLocation.X;

	if (bMovingTowardEndY)
		target.Y = endLocation.Y;
	else
		target.Y = startLocation.Y;

	if (bMovingTowardEndZ)
		target.Z = endLocation.Z;
	else
		target.Z = startLocation.Z;

	//interpolate
	FVector newLocation;
	newLocation.X = FMath::FInterpConstantTo(current.X, target.X, DeltaTime, xMovementSpeed);
	newLocation.Y = FMath::FInterpConstantTo(current.Y, target.Y, DeltaTime, yMovementSpeed);
	newLocation.Z = FMath::FInterpConstantTo(current.Z, target.Z, DeltaTime, zMovementSpeed);

	SetActorLocation(newLocation);

	// Flip direction when close to target
	if (FMath::Abs(newLocation.X - target.X) < 0.5f)
	{
		bMovingTowardEndX = !bMovingTowardEndX;
	}

	if (FMath::Abs(newLocation.Y - target.Y) < 0.5f)
	{
		bMovingTowardEndY = !bMovingTowardEndY;
	}

	if (FMath::Abs(newLocation.Z - target.Z) < 0.5f)
	{
		bMovingTowardEndZ = !bMovingTowardEndZ;
	}


}
