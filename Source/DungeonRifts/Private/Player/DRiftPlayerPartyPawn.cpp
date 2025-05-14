// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/DRiftPlayerPartyPawn.h"

#include "Characters/DRiftPartyCharacter.h"


// Sets default values
ADRiftPlayerPartyPawn::ADRiftPlayerPartyPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void ADRiftPlayerPartyPawn::Tick(const float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (ControlledPartyMember)
	{
		SetActorLocation(ControlledPartyMember->GetActorLocation());
	}
}

void ADRiftPlayerPartyPawn::SetPartyMember(ADRiftPartyCharacter* InMember)
{
	ControlledPartyMember = InMember;
}


