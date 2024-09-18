// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SmashCharacterStateMachine.h"

#include "SmashCharacterState.h"
#include "Character/SmashCharacter.h"

void USmashCharacterStateMachine::Init(ASmashCharacter* InCharacter)
{
	Character = InCharacter;
	FindState();
	InitializeState();
	ChangeState(ESmashCharacterStateID::Idle);
}

ASmashCharacter* USmashCharacterStateMachine::GetCharacter() const
{
	return Character;	
}

void USmashCharacterStateMachine::ChangeState(ESmashCharacterStateID NextStateID)
{
	USmashCharacterState* NextState = GetState(NextStateID);
	if (NextState == nullptr)return;
	if(CurrentState != nullptr)
	{
		CurrentState->StateExit(NextStateID);
	}

	ESmashCharacterStateID PreviousStateID = CurrentStateID;
	CurrentStateID = NextStateID;
	CurrentState = NextState;

	if(CurrentState != nullptr)
	{
		CurrentState->StateEnter(PreviousStateID);
	}
}

USmashCharacterState* USmashCharacterStateMachine::GetState(ESmashCharacterStateID StateID)
{
	for(USmashCharacterState *State : AllStates)
	{
		if(StateID == State->GetStateID())
		{
			return State;
		}
	}
	return nullptr;
}

void USmashCharacterStateMachine::FindState()
{
	TArray<UActorComponent*> FoundComponents = Character->K2_GetComponentsByClass(USmashCharacterState::StaticClass());
	for(UActorComponent* StateComponent : FoundComponents)
	{
		USmashCharacterState* State = Cast<USmashCharacterState>(StateComponent);
		if(State == nullptr)continue;
		if(State->GetStateID() == ESmashCharacterStateID::None) continue;
		AllStates.Add(State);
	}
}

void USmashCharacterStateMachine::InitializeState()
{
	for(USmashCharacterState* State : AllStates)
	{
		State->StateInitialize(this);
	}
}

