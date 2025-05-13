// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DRiftGameState.generated.h"

class ADRiftPartyCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPartyMemberAddedSignature, ADRiftPartyCharacter*, NewMember, const int32, MemberId);

UCLASS(BlueprintType)
class UPlayerParty : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<TObjectPtr<ADRiftPartyCharacter>> Members;
	UPROPERTY(BlueprintAssignable)
	FOnPartyMemberAddedSignature OnPartyMemberAddedEvent;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetPartySize() const { return Members.Num(); }
	UFUNCTION(BlueprintCallable)
	bool AddMember(ADRiftPartyCharacter* NewMember);
	// UFUNCTION(BlueprintCallable)
	// ADRiftPartyCharacter* GetMemberAtIndex(int32 Index) const;

};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnPartyCreatedSignature, const int32 /*PartyId*/, UPlayerParty* /*NewParty*/);

/**
 * 
 */
UCLASS()
class DUNGEONRIFTS_API ADRiftGameState : public AGameState
{
	GENERATED_BODY()

public:
	FOnPartyCreatedSignature OnPartyCreatedEvent;
	
public:
	/**
	 * Creates a new party and returns its ID.
	 * @return The ID of the newly created party, or -1 if the party could not be created.
	 */
	UFUNCTION(BlueprintCallable)
	int32 CreateParty();
	/**
	 * Adds a character to the specified party.
	 * @param PartyId The ID of the party to add the character to.
	 * @param NewMember The Actor to add to the party, this must implement IPartyInterface.
	 * @return True if the character was successfully added, false otherwise.
	 */
	UFUNCTION(BlueprintCallable)
	bool AddMemberToParty(const int32 PartyId, ADRiftPartyCharacter* NewMember);
	/**
	 * Gets the party by its ID.
	 * @param PartyId The ID of the party to retrieve.
	 * @return The party object, or nullptr if the party does not exist.
	 */
	UFUNCTION(BlueprintCallable)
	UPlayerParty* GetPlayerPartyById(int32 PartyId);
	TMap<int32, TObjectPtr<UPlayerParty>> GetPlayerParties() const { return PlayerParties; }
	
private:
	UPROPERTY()
	TMap<int32, TObjectPtr<UPlayerParty>> PlayerParties;

	int32 NextPartyId = 0;
};
