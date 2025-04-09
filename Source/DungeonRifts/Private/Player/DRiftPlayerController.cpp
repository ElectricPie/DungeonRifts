// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DRiftPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Characters/DRiftPartyCharacter.h"
#include "GameStates/DRiftGameState.h"
#include "Net/UnrealNetwork.h"

void ADRiftPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADRiftPlayerController, PartyId);
}

void ADRiftPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	check(MappingContext);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
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

void ADRiftPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// TODO:
	if (ADRiftPartyCharacter* PartyCharacter = Cast<ADRiftPartyCharacter>(InPawn))
	{
		ADRiftGameState* GameState = GetWorld()->GetGameState<ADRiftGameState>();
		PartyId = GameState->CreateParty();
		GameState->AddMemberToParty(PartyId, PartyCharacter);
	}
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

void ADRiftPlayerController::OnRep_PartyId()
{
	// TODO: Handle change of party ID
}
