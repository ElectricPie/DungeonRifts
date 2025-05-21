// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/DRiftPartyCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/DRiftAbilitySystemLibrary.h"
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

void ADRiftPartyCharacter::BroadcastAttributes() const
{
	if (const UDRiftAttributeSet* DRiftAttributeSet = CastChecked<UDRiftAttributeSet>(AttributeSet))
	{
		OnHealthChanged.Broadcast(DRiftAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(DRiftAttributeSet->GetMaxHealth());
	}
}

void ADRiftPartyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityActorInfo();

	if (const UDRiftAttributeSet* DRiftAttributeSet = CastChecked<UDRiftAttributeSet>(AttributeSet))
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DRiftAttributeSet->GetHealthAttribute()).
			AddLambda([this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			});
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DRiftAttributeSet->GetMaxHealthAttribute()).
			AddLambda([this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			});

		OnHealthChanged.Broadcast(DRiftAttributeSet->GetHealth());
		OnMaxHealthChanged.Broadcast(DRiftAttributeSet->GetMaxHealth());
	}

	// TODO: Debug
	FGameplayEffectContextHandle DamageEffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	DamageEffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle TestDamageEffectSpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DamageTestEffect, 1.f, DamageEffectContextHandle);
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*TestDamageEffectSpecHandle.Data.Get());
}

void ADRiftPartyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitDefaultAttributes();
}

void ADRiftPartyCharacter::InitDefaultAttributes() const
{
	UDRiftAbilitySystemLibrary::InitializeDefaultAttributes(this, AbilitySystemComponent, 1.f, CharacterInfo);
}

