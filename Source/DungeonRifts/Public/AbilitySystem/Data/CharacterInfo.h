// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterInfo.generated.h"

class UGameplayEffect;

/**
 * 
 */
UCLASS()
class DUNGEONRIFTS_API UCharacterInfo : public UDataAsset
{
	GENERATED_BODY()

public:
	TSubclassOf<UGameplayEffect> GetDefaultVitalAttributes() const { return DefaultVitalAttributes; }
	TSubclassOf<UGameplayEffect> GetDefaultSecondaryAttributes() const { return DefaultSecondaryAttributes; }

private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
};
