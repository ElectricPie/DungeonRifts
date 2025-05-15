#include "Party/PlayerParty.h"

bool UPlayerParty::AddMember(ADRiftPartyCharacter* NewMember)
{
	if (NewMember == nullptr)
		return false;
	
	const int32 MemberId = Members.Add(NewMember);
	OnPartyMemberAddedEvent.Broadcast(NewMember, MemberId);
	return true;
}