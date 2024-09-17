// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ExampleFloat.generated.h"

/**
 * 
 */
UCLASS()
class INITIATIONDEBUG_API UExampleFloat : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ValueToEdit = 0.f;
};
