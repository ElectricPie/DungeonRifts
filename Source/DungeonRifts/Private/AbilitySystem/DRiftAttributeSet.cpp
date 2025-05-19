// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/DRiftAttributeSet.h"

#include "Net/UnrealNetwork.h"

void UDRiftAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UDRiftAttributeSet, Health, COND_None, REPNOTIFY_Always);
}

void UDRiftAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDRiftAttributeSet, Health, OldHealth);
}
