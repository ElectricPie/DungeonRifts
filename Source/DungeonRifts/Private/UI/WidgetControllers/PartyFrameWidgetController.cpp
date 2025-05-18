// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/PartyFrameWidgetController.h"

#include "GameStates/DRiftGameState.h"
#include "Player/DRiftPlayerController.h"

void UPartyFrameWidgetController::BindCallbacksToDependencies()
{	
	if (ADRiftGameState* DRiftGameState = GetWorld()->GetGameState<ADRiftGameState>())
	{
		DRiftGameState->OnPartyCreatedEvent.AddLambda([this](const int32 NewPartyId, UPlayerParty* NewParty)
		{
			PartyCreatedEvent.Broadcast(NewPartyId, NewParty);
		});
	}

	if (ADRiftPlayerController* DRiftPlayerController = Cast<ADRiftPlayerController>(PlayerController))
	{
		DRiftPlayerController->OnPlayerCharactersSelectedEvent.AddLambda([this](const TArray<ADRiftPartyCharacter*>& SelectedCharacters)
		{
			CharactersSelectedEvent.Broadcast(SelectedCharacters);
		});
	}
}

void UPartyFrameWidgetController::BroadcastInitialValues()
{
	if (const ADRiftGameState* DRiftGameState = GetWorld()->GetGameState<ADRiftGameState>())
	{
		for (const auto& Parties : DRiftGameState->GetPlayerParties())
		{
			PartyCreatedEvent.Broadcast(Parties.Key, Parties.Value);
		}
	}
}

void UPartyFrameWidgetController::SelectPartyCharacter(ADRiftPartyCharacter* InCharacter) const
{
	TArray<ADRiftPartyCharacter*> SelectedCharacters;
	SelectedCharacters.Add(InCharacter);
	// CharactersSelectedEvent.Broadcast(SelectedCharacters);
	
	if (ADRiftPlayerController* DRiftPlayerController = Cast<ADRiftPlayerController>(PlayerController))
	{
		if (DRiftPlayerController->IsSelectModifierPressed())
		{
			DRiftPlayerController->AddPartyCharacter(InCharacter);
		}
		else
		{
			DRiftPlayerController->SetSelectedPartyCharacter(InCharacter);
		}
	}
}
