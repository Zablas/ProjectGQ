// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePortal.h"
#include "Components/BoxComponent.h"
#include "NiagaraComponent.h"
#include "WallWalkerCharacter.h"

// Sets default values
ABasePortal::ABasePortal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TeleportationDelay = 0.1f;

	CustomRoot = CreateDefaultSubobject<USceneComponent>(TEXT("CustomRoot"));
	SetRootComponent(CustomRoot);
	EntryCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("EntryCollisionBox"));
	EntryCollisionBox->SetupAttachment(GetRootComponent());
	ExitCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ExitCollisionBox"));
	ExitCollisionBox->SetupAttachment(GetRootComponent());

	EntryPortalParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("EntryPortalParticleSystem"));
	EntryPortalParticleSystem->SetupAttachment(EntryCollisionBox);
	ExitPortalParticleSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ExitPortalParticleSystem"));
	ExitPortalParticleSystem->SetupAttachment(ExitCollisionBox);

	EntryCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABasePortal::EntryBeginOverlap);
	ExitCollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ABasePortal::ExitBeginOverlap);
}

// Called when the game starts or when spawned
void ABasePortal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePortal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABasePortal::AllowCharacterTeleportation(AWallWalkerCharacter* character) const
{
	character->bReadyToBeTeleported = true;
}

void ABasePortal::SetupTeleportationResetTimer(AWallWalkerCharacter* character) const
{
	FTimerDelegate TimerDel = FTimerDelegate::CreateUObject(this, &ABasePortal::AllowCharacterTeleportation, character);
	FTimerHandle TimerHandle;
	//TimerDel.BindUFunction(this, FName("AllowCharacterTeleportation"), character);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, TeleportationDelay, false);
}

void ABasePortal::EntryBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWallWalkerCharacter* character = Cast<AWallWalkerCharacter>(OtherActor);
	if(character && character->bReadyToBeTeleported)
	{
		character->bReadyToBeTeleported = false;
		character->SetActorLocation(ExitCollisionBox->GetComponentLocation(), false, nullptr, ETeleportType::TeleportPhysics);
		SetupTeleportationResetTimer(character);
	}
}

void ABasePortal::ExitBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AWallWalkerCharacter* character = Cast<AWallWalkerCharacter>(OtherActor);
	if(character && character->bReadyToBeTeleported)
	{
		character->bReadyToBeTeleported = false;
		character->SetActorLocation(EntryCollisionBox->GetComponentLocation(), false, nullptr, ETeleportType::TeleportPhysics);
		SetupTeleportationResetTimer(character);
	}
}

