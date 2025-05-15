// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Party/PartyInterface.h"
#include "DRiftPlayerController.generated.h"

class AAIController;
class ADRiftPartyCharacterController;
class ADRiftPartyCharacter;
class ADRiftPlayerPartyPawn;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * 
 */
UCLASS(Abstract)
class DUNGEONRIFTS_API ADRiftPlayerController : public APlayerController, public IPartyInterface
{
	GENERATED_BODY()

public:
	/* Party Interface */
	virtual int32 GetPartyId_Implementation() const override { return PartyId; }
	virtual void SetPartyId_Implementation(const int32 NewPartyId) override { PartyId = NewPartyId; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void SetTargetPartyCharacter(ADRiftPartyCharacter* InCharacter);
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> MappingContext;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_PartyId)
	int32 PartyId = -1;

	UPROPERTY()
	TObjectPtr<ADRiftPartyCharacter> PartyCharacter;
	UPROPERTY()
	TObjectPtr<AAIController> PartyCharacterController;
	
private:
	void Move(const FInputActionValue& InputActionValue);

	UFUNCTION()
	void OnRep_PartyId();
};
