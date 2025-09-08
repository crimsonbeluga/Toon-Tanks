// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GameFramework/DamageType.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// were setting the projectile mesh pointer to have a static mesh component called projectile mesh whenever the actor becomes active 
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projectile Mesh"));

	// setting the root component of this game object to the projectile mesh
	RootComponent = ProjectileMesh;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Movement Component"));
	ProjectileMovementComponent->MaxSpeed = 1300.f;
	ProjectileMovementComponent->InitialSpeed = 1300.f;


}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	ProjectileMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::OnHit(
	UPrimitiveComponent* HitComponent,   // The projectile's own mesh/collision component
	AActor* OtherActor,                    // The actor that we collided with
	UPrimitiveComponent* HitActorComponent, // The specific component on the other actor we hit
	FVector ImpactForce,                 // The impulse/force applied by the hit
	const FHitResult& Hit
)

{
	auto MyOwner = GetOwner();

	if (MyOwner == nullptr) return;
	
	auto MyOwnerInstigator = MyOwner->GetInstigatorController();

	auto DamageTypeClass = UDamageType::StaticClass();

	if (OtherActor && OtherActor != this && OtherActor != MyOwner)
	{
		UGameplayStatics::ApplyDamage( OtherActor, Damage, MyOwnerInstigator, this, DamageTypeClass

		);
		Destroy();

	}
}

