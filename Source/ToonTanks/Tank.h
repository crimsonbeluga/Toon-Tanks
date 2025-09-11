#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void HandleDestruction();

	APlayerController* GetTankPlayerControllerPointer() const { return TankPlayerControllerPointer; }


	bool bAlive = true;
protected:
	virtual void BeginPlay() override;

private:
	void Move(float Value);
	void Turn(float Value);

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MovementSpeed = 200.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float RotationSpeed = 200.f;

	APlayerController* TankPlayerControllerPointer;

	

};
