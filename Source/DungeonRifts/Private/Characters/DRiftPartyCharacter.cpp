// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DRiftPartyCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ADRiftPartyCharacter::ADRiftPartyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArmComponent"));
	CameraSpringArmComponent->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	CameraSpringArmComponent->TargetArmLength = 700.f;
	CameraSpringArmComponent->bInheritPitch = false;
	CameraSpringArmComponent->bInheritRoll = false;
	CameraSpringArmComponent->bInheritYaw = false;
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

