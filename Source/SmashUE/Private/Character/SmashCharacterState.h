﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/SmashCharacterStateID.h"
#include "Components/ActorComponent.h"
#include "SmashCharacterState.generated.h"

class ASmashCharacter;
class USmashCharacterStateMachine;
UCLASS(Abstract)
class SMASHUE_API USmashCharacterState : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	USmashCharacterState();

	virtual ESmashCharacterStateID GetStateID();
	virtual void StateInitialize(USmashCharacterStateMachine* InStateMachine);
	virtual void StateEnter(ESmashCharacterStateID PreviousStateID);
	virtual void StateExit(ESmashCharacterStateID NextStateID);
	virtual void StateTick(float DeltaTime);

	protected:
	UPROPERTY()
	TObjectPtr<ASmashCharacter> Character;
	UPROPERTY()
	TObjectPtr<USmashCharacterStateMachine> StateMachine;
};
