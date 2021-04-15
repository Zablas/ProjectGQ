// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SceneComponent.h"
#include "ProjectGQCharacter.h"

// Sets default values
APickup::APickup()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CustomRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	CustomMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionZone"));

	SetRootComponent(CustomRoot);
	CustomMesh->SetupAttachment(GetRootComponent());
	CollisionBox->SetupAttachment(GetRootComponent());

	CollisionBox->SetCollisionObjectType(ECC_WorldDynamic);
	CollisionBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	CustomMesh->SetCollisionObjectType(ECC_WorldDynamic);
	CustomMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CustomMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	
	RotationSpeed = 10.f;
	bIsActive = true;
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FRotator CurrentRotation = CustomMesh->GetComponentRotation();
	FRotator NewRotation = FMath::RInterpTo(CurrentRotation, CurrentRotation + FRotator(0.f, 10.f, 0.f), DeltaTime, RotationSpeed);
	CustomMesh->SetWorldRotation(NewRotation);
}
