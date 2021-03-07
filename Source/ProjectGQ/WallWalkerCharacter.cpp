// Fill out your copyright notice in the Description page of Project Settings.


#include "WallWalkerCharacter.h"

AWallWalkerCharacter::AWallWalkerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MaxHealth = 100.f;
	Health = 70.f;	
}

void AWallWalkerCharacter::AddHealth(float health)
{
	if (Health + health > MaxHealth)
	{
		Health = MaxHealth;
		return;
	}
	Health += health;
}
