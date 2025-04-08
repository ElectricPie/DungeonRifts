﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DRiftCharacterBase.h"
#include "Party/PartyInterface.h"
#include "DRiftPartyCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class DUNGEONRIFTS_API ADRiftPartyCharacter : public ADRiftCharacterBase, public IPartyInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADRiftPartyCharacter();

	/* Party Interface */
	virtual int32 GetPartyId_Implementation() const override { return PartyId; }
	virtual void SetPartyId_Implementation(const int32 NewPartyId) override { PartyId = NewPartyId; }
	/* End Party Interface */
	

private:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> CameraSpringArmComponent;
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComponent;

	int32 PartyId = -1;
};
