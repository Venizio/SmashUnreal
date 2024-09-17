// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "MyFirstCustomObject.generated.h"

/**
 * 
 */
UCLASS()
class INITIATIONDEBUG_API UMyFirstCustomObject : public UObject
{
	GENERATED_BODY()

public:
	void PrintHelloOnScreen();
};
