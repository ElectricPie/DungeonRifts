// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/PartyCharacterController.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"


// Sets default values
APartyCharacterController::APartyCharacterController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
}

void APartyCharacterController::SetWorldDestination(const FVector& Destination)
{
	DrawDebugSphere(GetWorld(), Destination, 20.f, 12, FColor::Red, false, 5.f);

	if (UBlackboardComponent* CharacterBlackboard = GetBlackboardComponent())
	{
		CharacterBlackboard->SetValueAsVector(TEXT("WorldDestination"), Destination);
	}
}

void APartyCharacterController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (BehaviorTreeAsset)
	{
		UBlackboardComponent* BlackboardComp = GetBlackboardComponent();
		UseBlackboard(BehaviorTreeAsset->BlackboardAsset, BlackboardComp);
		RunBehaviorTree(BehaviorTreeAsset);
	}
}


