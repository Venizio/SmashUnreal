// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/States/SmashCharacterStateIdle.h"

ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("EnterStateIdle"))
	);
}

void USmashCharacterStateIdle::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("ExitStateIdle"))
	);
}

void USmashCharacterStateIdle::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	/*GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Green,
		FString::Printf(TEXT("TickStateIdle"))
	);*/
}
