// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DRiftCharacterBase.h"
#include "DRiftPartyCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DUNGEONRIFTS_API ADRiftPartyCharacter : public ADRiftCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADRiftPartyCharacter();

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraSpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;
};
