// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DRiftPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void ADRiftPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(MappingContext);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
}

void ADRiftPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADRiftPlayerController::Move);
}

void ADRiftPlayerController::Move(const FInputActionValue& InputActionValue)
{
	if (APawn* ControlledPawn = GetPawn())
	{
		const FVector2D InputValue = InputActionValue.Get<FVector2D>();
		const FRotator YawRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::Y);

		ControlledPawn->AddMovementInput(ForwardDirection, InputValue.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	}
}
