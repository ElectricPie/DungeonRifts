// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "DRiftCharacterBase.generated.h"

class UCharacterInfo;
class UGameplayEffect;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class DUNGEONRIFTS_API ADRiftCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADRiftCharacterBase();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAttributeSet> AttributeSet;

	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Defaults")
	// TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	// UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Defaults")
	// TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Defaults")
	TObjectPtr<UCharacterInfo> CharacterInfo;
	
protected:
	virtual void InitAbilityActorInfo();
	virtual void InitDefaultAttributes() const;
};
