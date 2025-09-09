#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Projectile.generated.h"   // must always be last

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
    GENERATED_BODY()

public:
    AProjectile();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    UStaticMeshComponent* ProjectileMesh;
    
    UPROPERTY(VisibleAnywhere, Category = "Movement")
    class UProjectileMovementComponent* ProjectileMovementComponent;

    UFUNCTION()
    void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
   
    UPROPERTY(EditAnywhere)
    float Damage = 50.f;

    UPROPERTY(EditAnywhere,  Category = "Combat")
    class UParticleSystem* HitParticles;

    UPROPERTY(VisibleAnywhere, Category = "Combat")
    class UParticleSystemComponent* ProjectileTrail;

public:
    virtual void Tick(float DeltaTime) override;
};
