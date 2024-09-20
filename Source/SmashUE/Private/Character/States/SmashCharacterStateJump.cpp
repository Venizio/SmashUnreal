// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/States/SmashCharacterStateJump.h"

#include "Character/SmashCharacter.h"
#include "Character/SmashCharacterStateMachine.h"
#include "GameFramework/CharacterMovementComponent.h"


ESmashCharacterStateID USmashCharacterStateJump::GetStateID()
{
	return ESmashCharacterStateID::Jump;
}

void USmashCharacterStateJump::StateEnter(ESmashCharacterStateID PreviousStateID)
{
	Super::StateEnter(PreviousStateID);
	Character->PlayAnimMontage(JumpMontage);
	Character->Jump();
	Character->GetCharacterMovement()->bNotifyApex = true;
	Character->OnReachedJumpApex.AddDynamic(this, &USmashCharacterStateJump::OnTopReached);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("EnterStateJump"))
	);
}

void USmashCharacterStateJump::StateExit(ESmashCharacterStateID NextStateID)
{
	Super::StateExit(NextStateID);
	Character->StopAnimMontage(JumpMontage);
	Character->OnReachedJumpApex.RemoveDynamic(this, &USmashCharacterStateJump::OnTopReached);
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("ExitStateJump"))
	);
}

void USmashCharacterStateJump::OnTopReached()
{
	StateMachine->ChangeState(ESmashCharacterStateID::Fall);
}

void USmashCharacterStateJump::StateTick(float DeltaTime)
{
	Super::StateTick(DeltaTime);
}
