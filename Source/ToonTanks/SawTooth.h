#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SawTooth.generated.h"

UCLASS()
class TOONTANKS_API ASawTooth : public AActor
{
	GENERATED_BODY()

public:
	ASawTooth();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	void SawToothMovement(float DeltaTime);

	UPROPERTY(EditInstanceOnly)
	float xMovementSpeed = 20.f;

	UPROPERTY(EditInstanceOnly)
	float yMovementSpeed = 20.f;

	UPROPERTY(EditInstanceOnly)
	float zMovementSpeed = 20.f;

	UPROPERTY(EditInstanceOnly)
	float xmoveDistance = 100.f;

	UPROPERTY(EditInstanceOnly)
	float ymoveDistance = 0.f;

	UPROPERTY(EditInstanceOnly)
	float zmoveDistance = 0.f;

	UPROPERTY()
	FVector startLocation;

	UPROPERTY()
	FVector endLocation;

private:
	bool bMovingTowardEndX = true;
	bool bMovingTowardEndY = true;
	bool bMovingTowardEndZ = true;
};
