// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "WidgetController.generated.h"

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* InPlayerController, APlayerState* InPlayerState)
		: PlayerController(InPlayerController), PlayerState(InPlayerState) {}

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;
};

/**
 * 
 */
UCLASS(Abstract)
class DUNGEONRIFTS_API UWidgetController : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& InParams);
	virtual void BindCallbacksToDependencies() {}
	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitialValues() {}

protected:
	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY()
	TObjectPtr<APlayerState> PlayerState;
};
