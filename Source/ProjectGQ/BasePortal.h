// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePortal.generated.h"

UCLASS()
class PROJECTGQ_API ABasePortal : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABasePortal();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	class UBoxComponent* EntryCollisionBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Collision")
	UBoxComponent* ExitCollisionBox;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	class UNiagaraComponent* EntryPortalParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Particles")
	UNiagaraComponent* ExitPortalParticleSystem;

	UPROPERTY(EditAnywhere, Category="Root")
	class USceneComponent* CustomRoot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay")
	float TeleportationDelay;

	UFUNCTION()
	void AllowCharacterTeleportation(class AWallWalkerCharacter* character) const;

	void SetupTeleportationResetTimer(AWallWalkerCharacter* character) const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void EntryBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
                     AActor* OtherActor, 
                     UPrimitiveComponent* OtherComp, 
                     int32 OtherBodyIndex, 
                     bool bFromSweep, 
                     const FHitResult &SweepResult);

	UFUNCTION()
	void ExitBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
                     AActor* OtherActor, 
                     UPrimitiveComponent* OtherComp, 
                     int32 OtherBodyIndex, 
                     bool bFromSweep, 
                     const FHitResult &SweepResult);
};
