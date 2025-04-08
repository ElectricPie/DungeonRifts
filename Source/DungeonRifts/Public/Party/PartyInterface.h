﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PartyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UPartyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DUNGEONRIFTS_API IPartyInterface
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	int32 GetPartyId() const;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetPartyId(const int32 NewPartyId);
};
