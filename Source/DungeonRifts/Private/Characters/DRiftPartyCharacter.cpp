// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DRiftPartyCharacter.h"

#include "Camera/CameraComponent.h"


// Sets default values
ADRiftPartyCharacter::ADRiftPartyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(RootComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

