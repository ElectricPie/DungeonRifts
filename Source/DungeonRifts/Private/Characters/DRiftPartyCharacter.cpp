// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DRiftPartyCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/DRiftAttributeSet.h"

// Sets default values
ADRiftPartyCharacter::ADRiftPartyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UDRiftAttributeSet>(TEXT("AttributeSet"));
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void ADRiftPartyCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void ADRiftPartyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitDefaultAttributes();
}

void ADRiftPartyCharacter::InitDefaultAttributes() const
{
	// TODO: Move out of here possibly into system library
	// Vital Attributes
	FGameplayEffectContextHandle VitalEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	VitalEffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle VitalAttributeSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultVitalAttributes, 1.f, VitalEffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*VitalAttributeSpecHandle.Data.Get());
	UE_LOG(LogTemp, Warning, TEXT("Applying Default Vital Attributes to %s"), *GetName());
}

