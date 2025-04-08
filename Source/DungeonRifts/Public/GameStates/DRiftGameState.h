﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "DRiftGameState.generated.h"

UCLASS(BlueprintType)
class UPlayerParty : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<APlayerController>> Players;
	UPROPERTY(BlueprintReadWrite)
	TArray<TObjectPtr<ACharacter>> Members;

public:
	UFUNCTION(BlueprintCallable)
	int32 GetPartySize() const { return Members.Num(); }
	
};

/**
 * 
 */
UCLASS()
class DUNGEONRIFTS_API ADRiftGameState : public AGameState
{
	GENERATED_BODY()
	
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
	 * @param NewCharacter The character to add to the party.
	 * @return True if the character was successfully added, false otherwise.
	 */
	UFUNCTION(BlueprintCallable)
	bool AddCharacterToParty(int32 PartyId, ACharacter* NewCharacter);
	/**
	 * Gets the party by its ID.
	 * @param PartyId The ID of the party to retrieve.
	 * @return The party object, or nullptr if the party does not exist.
	 */
	UFUNCTION(BlueprintCallable)
	UPlayerParty* GetPlayerPartyById(int32 PartyId);
	
private:
	TMap<int32, TObjectPtr<UPlayerParty>> PlayerParties;

	int32 NextPartyId = 0;
};
