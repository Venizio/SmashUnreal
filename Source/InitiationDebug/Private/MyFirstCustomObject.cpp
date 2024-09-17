// Fill out your copyright notice in the Description page of Project Settings.


#include "InitiationDebug/Public/MyFirstCustomObject.h"

void UMyFirstCustomObject::PrintHelloOnScreen()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		1.f,
		FColor::Red,
		TEXT("Hello")
	);
}
