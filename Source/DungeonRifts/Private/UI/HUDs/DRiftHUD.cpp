// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/HUDs/DRiftHUD.h"

#include "UI/Widgets/DRiftUserWidget.h"

class UDRiftUserWidget;

void ADRiftHUD::BeginPlay()
{
	Super::BeginPlay();

	check(OverlayWidgetClass);
	OverlayWidget = CreateWidget<UDRiftUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->AddToViewport();
}
