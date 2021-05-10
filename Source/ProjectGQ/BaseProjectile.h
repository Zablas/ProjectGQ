// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "WallWalkerCharacter.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class PROJECTGQ_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Lifespan")
	bool bIsInitialized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Lifespan")
	bool bCanBeDestroyed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Combat")
	float Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Collision")
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Particles")
	class UNiagaraComponent* NiagaraParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Movement")
	class UProjectileMovementComponent* ProjectileMovement;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, 
	                     AActor* OtherActor, 
	                     UPrimitiveComponent* OtherComp, 
	                     int32 OtherBodyIndex, 
	                     bool bFromSweep, 
	                     const FHitResult &SweepResult);

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit);

	UFUNCTION(BlueprintImplementableEvent)
	void PostHit(AWallWalkerCharacter* Character);

	UFUNCTION(BlueprintImplementableEvent)
	void Portal(AActor* Actor);
};
