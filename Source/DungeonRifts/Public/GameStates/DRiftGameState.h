// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DRiftGameState.generated.h"

class UPlayerParty;
class ADRiftPartyCharacter;

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
