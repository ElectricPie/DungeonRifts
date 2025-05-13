// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DRiftGameState.h"

#include "Characters/DRiftPartyCharacter.h"

bool UPlayerParty::AddMember(ADRiftPartyCharacter* NewMember)
{
	if (NewMember == nullptr)
		return false;
	
	const int32 MemberId = Members.Add(NewMember);
	OnPartyMemberAddedEvent.Broadcast(NewMember, MemberId);
	return true;
}

int32 ADRiftGameState::CreateParty()
{
	UPlayerParty* NewParty = NewObject<UPlayerParty>();
	PlayerParties.Add(NextPartyId, NewParty);
	OnPartyCreatedEvent.Broadcast(NextPartyId, NewParty);
	return NextPartyId++;
}

bool ADRiftGameState::AddMemberToParty(const int32 PartyId, ADRiftPartyCharacter* NewMember)
{
	if (!PlayerParties.Contains(PartyId))
		return false;
	
	if (PlayerParties[PartyId]->AddMember(NewMember))
	{
		IPartyInterface::Execute_SetPartyId(NewMember, PartyId);
		return true;
	}

	return false;
}

UPlayerParty* ADRiftGameState::GetPlayerPartyById(const int32 PartyId)
{
	if (PlayerParties.Contains(PartyId))
	{
		return PlayerParties[PartyId];
	}

	return nullptr;
}
