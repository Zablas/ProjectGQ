// Fill out your copyright notice in the Description page of Project Settings.


#include "WallWalkerCharacter.h"

#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

AWallWalkerCharacter::AWallWalkerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MaxHealth = 100.f;
	Health = 100.f;
	bReadyToBeTeleported = true;
}

void AWallWalkerCharacter::AddHealth(float healthToAdd)
{
	if (Health + healthToAdd > MaxHealth)
	{
		Health = MaxHealth;
		return;
	}
	Health += healthToAdd;
	if (Health <= 0) Die();
}

void AWallWalkerCharacter::MoveForward(float Val)
{
	if(Val != 0)
	{
		FVector rightVector = UKismetMathLibrary::GetRightVector(GetControlRotation());
		FVector upVector = UKismetMathLibrary::GetUpVector(GetActorRotation());
		FVector crossProduct = FVector::CrossProduct(rightVector, upVector);
		crossProduct.Normalize(0.0001);
		AddMovementInput(crossProduct, Val);
	}
}

void AWallWalkerCharacter::MoveRight(float Val)
{
	if(Val != 0)
	{
		FVector rightVector = UKismetMathLibrary::GetRightVector(GetControlRotation());
		AddMovementInput(rightVector, Val);
	}
}

void AWallWalkerCharacter::CustomJump()
{
	ACharacter::Jump();
}

void AWallWalkerCharacter::CustomStopJumping()
{
	ACharacter::StopJumping();
}

void AWallWalkerCharacter::CustomAddControllerYawInput(float Val)
{
	AddControllerYawInput(Val);
}

void AWallWalkerCharacter::CustomAddControllerPitchInput(float Val)
{
	AddControllerPitchInput(Val);
}
