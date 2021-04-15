// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class PROJECTGQ_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

	UPROPERTY(EditAnywhere, Category="Root")
	class USceneComponent* CustomRoot;
	
	UPROPERTY(EditAnywhere, Category="Mesh")
	class UStaticMeshComponent* CustomMesh;

	UPROPERTY(EditAnywhere, Category="Collision")
	class UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere, Category="Rotation")
	float RotationSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Usage")
	bool bIsActive;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
