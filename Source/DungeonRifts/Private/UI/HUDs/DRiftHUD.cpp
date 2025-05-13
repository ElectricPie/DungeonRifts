// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUDs/DRiftHUD.h"

#include "UI/WidgetControllers/PartyFrameWidgetController.h"
#include "UI/Widgets/DRiftUserWidget.h"

class UDRiftUserWidget;

UPartyFrameWidgetController* ADRiftHUD::GetPartyFrameWidgetController(const FWidgetControllerParams& ControllerParams)
{
	if (PartyFrameWidgetController == nullptr)
	{
		check(PartyFrameWidgetControllerClass);
		PartyFrameWidgetController = NewObject<UPartyFrameWidgetController>(this, PartyFrameWidgetControllerClass);
		PartyFrameWidgetController->SetWidgetControllerParams(ControllerParams);
		PartyFrameWidgetController->BindCallbacksToDependencies();
	}

	return PartyFrameWidgetController;
}

void ADRiftHUD::BeginPlay()
{
	Super::BeginPlay();

	check(OverlayWidgetClass);
	OverlayWidget = CreateWidget<UDRiftUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
