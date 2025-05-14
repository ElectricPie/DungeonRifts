// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "DRiftPlayerPartyPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ADRiftPartyCharacter;

UCLASS()
class DUNGEONRIFTS_API ADRiftPlayerPartyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADRiftPlayerPartyPawn();

	virtual void Tick(float DeltaSeconds) override;

public:
	void SetPartyMember(ADRiftPartyCharacter* InMember);

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraSpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;
	
	UPROPERTY()
	TObjectPtr<ADRiftPartyCharacter> ControlledPartyMember;
};
