// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Party/PartyInterface.h"
#include "DRiftPlayerController.generated.h"



class UPlayerParty;
class ADRiftPartyCharacter;
class ADRiftPlayerPartyPawn;
class APartyCharacterController;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_MULTICAST_DELEGATE_OneParam(FOnPlayerCharactersSelectedSignature, const TArray<ADRiftPartyCharacter*>&/*SelectedCharacter*/);

/**
 * 
 */
UCLASS(Abstract)
class DUNGEONRIFTS_API ADRiftPlayerController : public APlayerController, public IPartyInterface
{
	GENERATED_BODY()

public:
	FOnPlayerCharactersSelectedSignature OnPlayerCharactersSelectedEvent;

public:
	/* Party Interface */
	virtual int32 GetPartyId_Implementation() const override { return PartyId; }
	virtual void SetPartyId_Implementation(const int32 NewPartyId) override { PartyId = NewPartyId; }

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	/**
	 * Set the selected party character as the only selected character.
	 * @param InCharacter The party character to set as selected.
	 */
	void SetSelectedPartyCharacter(ADRiftPartyCharacter* InCharacter);
	/**
	 * Add a party character to the selection.
	 * @param InCharacter The party character to add to the selection.
	 */
	void AddPartyCharacter(ADRiftPartyCharacter* InCharacter);

	UFUNCTION(BlueprintPure)
	bool IsSelectModifierPressed() const { return bSelectModifierPressed; }
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void OnPossess(APawn* InPawn) override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> MappingContext;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> MoveAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> SelectAction;
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> SelectModifierAction;
	
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_PartyId)
	int32 PartyId = -1;

	// UPROPERTY()
	// TObjectPtr<ADRiftPartyCharacter> PartyCharacter;
	// UPROPERTY()
	// TObjectPtr<APartyCharacterController> PartyCharacterController;

	UPROPERTY(EditAnywhere)
	float SelectRayLength = 10000.f;

	bool bSelectModifierPressed = false;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UPlayerParty> PlayerParty = nullptr;

	UPROPERTY()
	TArray<TObjectPtr<ADRiftPartyCharacter>> SelectedPartyCharacters;
	
private:
	void Move(const FInputActionValue& InputActionValue);
	void Select();
	
	UFUNCTION()
	void OnRep_PartyId();

	void SelectModifierPressed() { bSelectModifierPressed = true; }
	void SelectModifierReleased() { bSelectModifierPressed = false; }
};
