// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/States/SmashCharacterStateIdle.h"

#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateMachine.h"

ESmashCharacterStateID USmashCharacterStateIdle::GetStateID()
{
	return ESmashCharacterStateID::Idle;
}

void USmashCharacterStateIdle::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(IdleMontage);

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
	Character->StopAnimMontage(IdleMontage);
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
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Green,
		FString::Printf(TEXT("TickStateIdle"))
	);
	if (FMath::Abs(Character->GetInputMoveX()) > 0.1f)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Walk);
	}
}
