// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DRiftGameState.h"

#include "Characters/DRiftPartyCharacter.h"

int32 ADRiftGameState::CreateParty()
{
	UPlayerParty* NewParty = NewObject<UPlayerParty>();
	PlayerParties.Add(NextPartyId, NewParty);
	return NextPartyId++;
}

bool ADRiftGameState::AddMemberToParty(const int32 PartyId, ADRiftPartyCharacter* NewMember)
{
	if (!PlayerParties.Contains(PartyId))
		return false;
	if (NewMember == nullptr)
		return false;
	
	PlayerParties[PartyId]->Members.Add(NewMember);
	IPartyInterface::Execute_SetPartyId(NewMember, PartyId);
	return true;
}

UPlayerParty* ADRiftGameState::GetPlayerPartyById(const int32 PartyId)
{
	if (PlayerParties.Contains(PartyId))
	{
		return PlayerParties[PartyId];
	}

	return nullptr;
}
