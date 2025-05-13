// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DRiftUiSystemLibrary.h"

#include "GameFramework/PlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUDs/DRiftHUD.h"
#include "UI/WidgetControllers/WidgetController.h"

UPartyFrameWidgetController* UDRiftUiSystemLibrary::GetPartyFrameWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (ADRiftHUD* DRiftHUD = PlayerController->GetHUD<ADRiftHUD>())
		{
			APlayerState* PlayerState = PlayerController->GetPlayerState<APlayerState>();
			const FWidgetControllerParams ControllerParams(PlayerController, PlayerState);
			return DRiftHUD->GetPartyFrameWidgetController(ControllerParams);
		}
	}

	return nullptr;
}
