// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseProjectile.h"
#include "WallWalkerCharacter.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABaseProjectile::ABaseProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bCanBeDestroyed = false;
	bIsInitialized = false;
	
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionZone"));
	NiagaraParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ParticleSystem"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	SetRootComponent(CollisionBox);
	NiagaraParticleSystem->SetupAttachment(CollisionBox);

	CollisionBox->SetNotifyRigidBodyCollision(true); // Simulates Hit events
	CollisionBox->SetCollisionObjectType(ECC_PhysicsBody);
	CollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionBox->SetCollisionResponseToAllChannels(ECR_Block);
	CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABaseProjectile::BeginOverlap);
	CollisionBox->OnComponentHit.AddDynamic(this, &ABaseProjectile::OnHit);

	ProjectileMovement->InitialSpeed = 5000.f;
	ProjectileMovement->MaxSpeed = 6000.f;
	ProjectileMovement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void ABaseProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(bCanBeDestroyed && bIsInitialized) Destroy();
}

void ABaseProjectile::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWallWalkerCharacter* character = Cast<AWallWalkerCharacter>(OtherActor);
	if(character)
	{
		character->AddHealth(-20.f);
		bCanBeDestroyed = true;
	}
}

void ABaseProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
        FVector NormalImpulse, const FHitResult& Hit)
{
	ABaseProjectile* projectile = Cast<ABaseProjectile>(OtherActor);
	if(!projectile) bCanBeDestroyed = true;
}


