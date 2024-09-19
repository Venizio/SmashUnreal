// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/States/SmashCharacterStateWalk.h"

#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateMachine.h"

ESmashCharacterStateID USmashCharacterStateWalk::GetStateID()
{
	return ESmashCharacterStateID::Walk;
}

void USmashCharacterStateWalk::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(WalkMontage);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("EnterStateWalk"))
	);
}

void USmashCharacterStateWalk::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	Character->StopAnimMontage(WalkMontage);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("ExitStateWalk"))
	);
}

void USmashCharacterStateWalk::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Green,
		FString::Printf(TEXT("TickStateWalk"))
	);

	if (FMath::Abs(Character->GetInputMoveX()) < 0.1f)
	{
		StateMachine->ChangeState(ESmashCharacterStateID::Idle);
	}
	else
	{
		Character->SetOrientX(Character->GetInputMoveX());
		Character->AddMovementInput(FVector::ForwardVector, Character->GetOrientX());
	}
}
