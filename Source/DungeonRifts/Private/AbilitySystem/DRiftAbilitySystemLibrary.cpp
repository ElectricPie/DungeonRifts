// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/DRiftAbilitySystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystem/Data/CharacterInfo.h"

class UGameplayEffect;

void UDRiftAbilitySystemLibrary::InitializeDefaultAttributes(const UObject* WorldContextObject, UAbilitySystemComponent* AbilitySystemComponent,
                                                             const float Level, const UCharacterInfo* CharacterInfo)
{
	const AActor* AvatarActor = AbilitySystemComponent->GetAvatarActor();
	
	// Secondary Attributes
	FGameplayEffectContextHandle SecondaryEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	SecondaryEffectContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle SecondaryAttributeSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		CharacterInfo->GetDefaultSecondaryAttributes(), Level, SecondaryEffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SecondaryAttributeSpecHandle.Data.Get());
	
	// Vital Attributes
	FGameplayEffectContextHandle VitalEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	VitalEffectContextHandle.AddSourceObject(AvatarActor);
	const FGameplayEffectSpecHandle VitalAttributeSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(
		CharacterInfo->GetDefaultVitalAttributes(), Level, VitalEffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*VitalAttributeSpecHandle.Data.Get());
}
