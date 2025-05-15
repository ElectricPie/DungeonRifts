// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DRiftPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/DRiftPartyCharacter.h"
#include "Controller/PartyCharacterController.h"
#include "GameStates/DRiftGameState.h"
#include "Net/UnrealNetwork.h"
#include "Party/PlayerParty.h"
#include "Player/DRiftPlayerPartyPawn.h"

void ADRiftPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADRiftPlayerController, PartyId);
}

void ADRiftPlayerController::SetTargetPartyCharacter(ADRiftPartyCharacter* InCharacter)
{
	if (InCharacter == nullptr)
		return;

	PartyCharacter = InCharacter;
	PartyCharacterController = Cast<APartyCharacterController>(PartyCharacter->GetController());

	if (ADRiftPlayerPartyPawn* PlayerPartyPawn = Cast<ADRiftPlayerPartyPawn>(GetPawn()))
	{
		PlayerPartyPawn->SetPartyMember(InCharacter);
	}
}

void ADRiftPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(MappingContext);
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
		GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}

	bShowMouseCursor = true;
}

void ADRiftPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADRiftPlayerController::Move);
	EnhancedInputComponent->BindAction(SelectAction, ETriggerEvent::Started, this, &ADRiftPlayerController::Select);
}

void ADRiftPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	// if (ADRiftPartyCharacter* PartyCharacter = Cast<ADRiftPartyCharacter>(InPawn))
	// {
	// 	ADRiftGameState* GameState = GetWorld()->GetGameState<ADRiftGameState>();
	// 	PartyId = GameState->CreateParty();
	// 	GameState->AddMemberToParty(PartyId, PartyCharacter);
	// }
}

void ADRiftPlayerController::Move(const FInputActionValue& InputActionValue)
{
	// if (APawn* ControlledPawn = GetPawn())
	// {
	// 	const FVector2D InputValue = InputActionValue.Get<FVector2D>();
	// 	const FRotator YawRotation = FRotator(0.f, GetControlRotation().Yaw, 0.f);
	// 	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::X);
	// 	const FVector RightDirection = FRotationMatrix(YawRotation).GetScaledAxis(EAxis::Y);
	//
	// 	ControlledPawn->AddMovementInput(ForwardDirection, InputValue.Y);
	// 	ControlledPawn->AddMovementInput(RightDirection, InputValue.X);
	// }
}

void ADRiftPlayerController::Select()
{
	// if (PartyCharacterController == nullptr)
	// 	return;

	if (PlayerParty == nullptr)
	{
		ADRiftGameState* GameState = GetWorld()->GetGameState<ADRiftGameState>();
		PlayerParty = GameState->GetPlayerPartyById(0);
		if (PlayerParty == nullptr)
			return;
	}

	FVector2D MouseScreenPosition;
	if (GetMousePosition(MouseScreenPosition.X, MouseScreenPosition.Y))
	{
		FVector MouseWorldPosition;
		FVector MouseWorldDirection;
		DeprojectScreenPositionToWorld(MouseScreenPosition.X, MouseScreenPosition.Y, MouseWorldPosition,
		                               MouseWorldDirection);

		FHitResult HitResult;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);

		const FVector End = MouseWorldPosition + MouseWorldDirection * SelectRayLength;

		if (GetWorld()->LineTraceSingleByChannel(HitResult, MouseWorldPosition, End, ECC_Visibility, CollisionParams))
		{
			// PartyCharacterController->SetWorldDestination(HitResult.Location);
			for (const auto& PartyMember : PlayerParty->GetPartyMembers())
			{
				if (APartyCharacterController* MemberController = PartyMember->GetController<APartyCharacterController>())
				{
					MemberController->SetWorldDestination(HitResult.Location);
				}
			}
		}
	}
}

void ADRiftPlayerController::OnRep_PartyId()
{
	// TODO: Handle change of party ID
}
