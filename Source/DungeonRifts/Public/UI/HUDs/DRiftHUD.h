// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "DRiftHUD.generated.h"

class UDRiftUserWidget;

/**
 * 
 */
UCLASS(Abstract)
class DUNGEONRIFTS_API ADRiftHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UDRiftUserWidget> OverlayWidgetClass;
	TObjectPtr<UDRiftUserWidget> OverlayWidget;
};
