// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "PartyCharacterController.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class DUNGEONRIFTS_API APartyCharacterController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APartyCharacterController();

protected:
	virtual void OnPossess(APawn* InPawn) override;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBehaviorTree> BehaviorTreeAsset;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBehaviorTreeComponent> BehaviorTreeComponent;
};
