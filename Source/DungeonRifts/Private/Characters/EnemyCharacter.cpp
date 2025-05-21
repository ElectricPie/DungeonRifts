// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/DRiftAbilitySystemLibrary.h"
#include "AbilitySystem/DRiftAttributeSet.h"


// Sets default values
AEnemyCharacter::AEnemyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UDRiftAttributeSet>(TEXT("AttributeSet"));
	
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

void AEnemyCharacter::InitAbilityActorInfo()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);

	InitDefaultAttributes();
}

void AEnemyCharacter::InitDefaultAttributes() const
{
	UDRiftAbilitySystemLibrary::InitializeDefaultAttributes(this, AbilitySystemComponent, 1.f, CharacterInfo);
}

