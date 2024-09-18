// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
UENUM()
enum class ESmashCharacterStateID : uint8
{
	None = 0,
	Idle,
	Walk,
};
/**
 * 
 */
class SMASHUE_API SmashCharacterStateID
{
public:
	SmashCharacterStateID();
	~SmashCharacterStateID();
};
