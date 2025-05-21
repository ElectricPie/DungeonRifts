// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DRiftAbilitySystemLibrary.generated.h"

class UCharacterInfo;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class DUNGEONRIFTS_API UDRiftAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="DungeonRiftsAbilitySystemLibrary|Character")
	static void InitializeDefaultAttributes(const UObject* WorldContextObject, UAbilitySystemComponent* AbilitySystemComponent,
	                                        const float Level, const UCharacterInfo* CharacterInfo);
};
