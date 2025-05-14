// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DRiftPlayerPartyPawn.h"

#include "Camera/CameraComponent.h"
#include "Characters/DRiftPartyCharacter.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ADRiftPlayerPartyPawn::ADRiftPlayerPartyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	CameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArmComponent"));
	CameraSpringArmComponent->SetRelativeRotation(FRotator(-70.f, 0.f, 0.f));
	CameraSpringArmComponent->TargetArmLength = 700.f;
	CameraSpringArmComponent->bInheritPitch = false;
	CameraSpringArmComponent->bInheritRoll = false;
	CameraSpringArmComponent->bInheritYaw = false;
	CameraSpringArmComponent->bDoCollisionTest = false;
	CameraSpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(CameraSpringArmComponent);
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ADRiftPlayerPartyPawn::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (ControlledPartyMember)
	{
		SetActorLocation(ControlledPartyMember->GetActorLocation());
	}
}

void ADRiftPlayerPartyPawn::SetPartyMember(ADRiftPartyCharacter* InMember)
{
	ControlledPartyMember = InMember;
}


