// Fill out your copyright notice in the Description page of Project Settings.


#include "GameStates/DRiftGameState.h"

#include "Party/PartyInterface.h"

int32 ADRiftGameState::CreateParty()
{
	UPlayerParty* NewParty = NewObject<UPlayerParty>();
	PlayerParties.Add(NextPartyId, NewParty);
	return NextPartyId++;
}

bool ADRiftGameState::AddMemberToParty(const int32 PartyId, AActor* NewMember)
{
	if (!PlayerParties.Contains(PartyId))
		return false;
	if (NewMember == nullptr)
		return false;
	if (NewMember->GetClass()->ImplementsInterface(UPartyInterface::StaticClass()) == false)
		return false;
	
	PlayerParties[PartyId]->Members.Add(NewMember);
	IPartyInterface::Execute_SetPartyId(NewMember, PartyId);
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
