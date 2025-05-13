// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DRiftUiSystemLibrary.generated.h"

class UPartyFrameWidgetController;
/**
 * 
 */
UCLASS()
class DUNGEONRIFTS_API UDRiftUiSystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="DungeonRiftSystemLibrary|WidgetController", meta=(DefaultToSelf="WorldContextObject"))
	static UPartyFrameWidgetController* GetPartyFrameWidgetController(const UObject* WorldContextObject);
};
