// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DRiftGameState.h"

int32 ADRiftGameState::CreateParty()
{
	UPlayerParty* NewParty = NewObject<UPlayerParty>();
	PlayerParties.Add(NextPartyId, NewParty);
	return NextPartyId++;
}

bool ADRiftGameState::AddCharacterToParty(const int32 PartyId, ACharacter* NewCharacter)
{
	if (!PlayerParties.Contains(PartyId))
		return false;
	if (NewCharacter == nullptr)
		return false;
	
	PlayerParties[PartyId]->Members.Add(NewCharacter);
	return true;
}

UPlayerParty* ADRiftGameState::GetPlayerPartyById(const int32 PartyId)
{
	if (!PlayerParties.Contains(PartyId))
	{
		return nullptr;
	}

	return PlayerParties[PartyId];
}
