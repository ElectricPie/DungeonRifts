#pragma once

#include "CoreMinimal.h"

#include "PlayerParty.generated.h"

class ADRiftPartyCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyMemberAddedSignature, ADRiftPartyCharacter*, NewMember, const int32, MemberId);

UCLASS(BlueprintType)
class UPlayerParty : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPartyMemberAddedSignature OnPartyMemberAddedEvent;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetPartySize() const { return Members.Num(); }
	UFUNCTION(BlueprintCallable)
	bool AddMember(ADRiftPartyCharacter* NewMember);
	// UFUNCTION(BlueprintCallable)
	// ADRiftPartyCharacter* GetMemberAtIndex(int32 Index) const;

	UFUNCTION(BlueprintCallable)
	TArray<ADRiftPartyCharacter*> GetPartyMembers() const { return Members; }

private:
	UPROPERTY()
	TArray<TObjectPtr<ADRiftPartyCharacter>> Members;
	
};