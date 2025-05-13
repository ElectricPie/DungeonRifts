// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/PartyFrameWidgetController.h"

#include "GameStates/DRiftGameState.h"

void UPartyFrameWidgetController::BindCallbacksToDependencies()
{	
	if (ADRiftGameState* DRiftGameState = GetWorld()->GetGameState<ADRiftGameState>())
	{
		DRiftGameState->OnPartyCreatedEvent.AddLambda([this](const int32 NewPartyId, UPlayerParty* NewParty)
		{
			PartyCreatedEvent.Broadcast(NewPartyId, NewParty);
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
