// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/DRiftUserWidget.h"

void UDRiftUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
