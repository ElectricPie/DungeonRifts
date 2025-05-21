// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DRiftCharacterBase.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class DUNGEONRIFTS_API AEnemyCharacter : public ADRiftCharacterBase
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	virtual void InitAbilityActorInfo() override;
	virtual void InitDefaultAttributes() const override;
};
