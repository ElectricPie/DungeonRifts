// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DRiftHUD.generated.h"

struct FWidgetControllerParams;
class UPartyFrameWidgetController;
class UDRiftUserWidget;

/**
 * 
 */
UCLASS(Abstract)
class DUNGEONRIFTS_API ADRiftHUD : public AHUD
{
	GENERATED_BODY()

public:
	UPartyFrameWidgetController* GetPartyFrameWidgetController(const FWidgetControllerParams& ControllerParams);

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDRiftUserWidget> OverlayWidgetClass;
	UPROPERTY()
	TObjectPtr<UDRiftUserWidget> OverlayWidget;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPartyFrameWidgetController> PartyFrameWidgetControllerClass;
	UPROPERTY()
	TObjectPtr<UPartyFrameWidgetController> PartyFrameWidgetController;
};
