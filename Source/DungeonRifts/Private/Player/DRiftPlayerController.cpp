// Fill out your copyright notice in the Description page of Project Settings.

#include "Player/DRiftPlayerController.h"

#include "AIController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Characters/DRiftPartyCharacter.h"
#include "Net/UnrealNetwork.h"
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
	PartyCharacterController = Cast<AAIController>(PartyCharacter->GetController());
	// TODO: Debug
	if (PartyCharacterController)
	{
		if (UBlackboardComponent* CharacterBlackboard = PartyCharacterController->GetBlackboardComponent())
		{
			const FVector TargetLocation(
				FMath::RandRange(-1000.f, 1000.f),
				FMath::RandRange(-1000.f, 1000.f),
				PartyCharacter->GetActorLocation().Z
			);
			CharacterBlackboard->SetValueAsVector(TEXT("WorldDestination"), TargetLocation);
		}
	}
	
	if (ADRiftPlayerPartyPawn* PlayerPartyPawn = Cast<ADRiftPlayerPartyPawn>(GetPawn()))
	{
		PlayerPartyPawn->SetPartyMember(InCharacter);
	}
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

void ADRiftPlayerController::OnRep_PartyId()
{
	// TODO: Handle change of party ID
}
