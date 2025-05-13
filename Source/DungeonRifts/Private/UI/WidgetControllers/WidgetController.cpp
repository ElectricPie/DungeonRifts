// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetControllers/WidgetController.h"

void UWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& InParams)
{
	PlayerController = InParams.PlayerController;
	PlayerState = InParams.PlayerState;
}
