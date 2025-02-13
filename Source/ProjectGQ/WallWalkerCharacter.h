// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NinjaCharacter.h"
#include "WallWalkerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTGQ_API AWallWalkerCharacter : public ANinjaCharacter
{
	GENERATED_BODY()
	
public:
	AWallWalkerCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Gameplay")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Gameplay")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Gameplay")
	bool bReadyToBeTeleported;

	UFUNCTION(BlueprintCallable)
	void AddHealth(float healthToAdd);

	UFUNCTION(BlueprintImplementableEvent)
	void Die();

	// Movement functions
	void MoveForward(float Val);
	void MoveRight(float Val);
	void CustomJump();
	void CustomStopJumping();
	void CustomAddControllerYawInput(float Val);
	void CustomAddControllerPitchInput(float Val);

	UFUNCTION(BlueprintImplementableEvent)
	void YawEvent();
};
