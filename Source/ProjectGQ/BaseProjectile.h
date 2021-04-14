// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseProjectile.generated.h"

UCLASS()
class PROJECTGQ_API ABaseProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseProjectile();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lifespan")
	bool bIsInitialized;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Lifespan")
	bool bCanBeDestroyed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	class UNiagaraComponent* NiagaraParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
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
	void PlayHitSound();
};
