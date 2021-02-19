// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "ProjectGQCharacter.h"

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::MoveForward);
	InputComponent->BindAxis("TurnRate", this, &ACustomPlayerController::TurnAtRate);
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &ACustomPlayerController::AddControllerPitchInput);
	
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACustomPlayerController::OnFire);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACustomPlayerController::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &ACustomPlayerController::StopJumping);
}

void ACustomPlayerController::OnFire()
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->OnFire();
	}
}

void ACustomPlayerController::MoveRight(float Val)
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->MoveRight(Val);
	}
}

void ACustomPlayerController::TurnAtRate(float Rate)
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->TurnAtRate(Rate);
	}
}

void ACustomPlayerController::Jump()
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->Jump();
	}
}

void ACustomPlayerController::StopJumping()
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->StopJumping();
	}
}

void ACustomPlayerController::AddControllerYawInput(float Val)
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->CustomAddControllerYawInput(Val);
	}
}

void ACustomPlayerController::AddControllerPitchInput(float Val)
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->CustomAddControllerPitchInput(Val);
	}
}

void ACustomPlayerController::MoveForward(float Val)
{
	APawn* pawn = GetPawn();
	if(pawn)
	{
		AProjectGQCharacter* character = Cast<AProjectGQCharacter>(pawn);
		if(character) character->MoveForward(Val);
	}
}
