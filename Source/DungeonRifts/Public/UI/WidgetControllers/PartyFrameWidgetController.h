// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetController.h"
#include "PartyFrameWidgetController.generated.h"

class UPlayerParty;
class ADRiftPartyCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWidgetPartyCreatedSignature, const int32, PartyId, UPlayerParty*, NewParty);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharactersSelectedSignature, const TArray<ADRiftPartyCharacter*>&, SelectedCharacter);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DUNGEONRIFTS_API UPartyFrameWidgetController : public UWidgetController
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnWidgetPartyCreatedSignature PartyCreatedEvent;
	UPROPERTY(BlueprintAssignable)
	FOnCharactersSelectedSignature CharactersSelectedEvent;
	
public:
	virtual void BindCallbacksToDependencies() override;
	virtual void BroadcastInitialValues() override;

	UFUNCTION(BlueprintCallable)
	void SelectPartyCharacter(ADRiftPartyCharacter* InCharacter) const;
};
