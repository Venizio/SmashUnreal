// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExamplesValuesReferencesActor.generated.h"

UCLASS()
class INITIATIONDEBUG_API AExamplesValuesReferencesActor : public AActor
{
	GENERATED_BODY()
	
#pragma region Unreal Defaults
	
public:
	// Sets default values for this actor's properties
	AExamplesValuesReferencesActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma endregion

#pragma region Print

	UFUNCTION(BlueprintCallable)
	static void PrintIntsCopy();

	UFUNCTION(BlueprintCallable)
	static void PrintVectorsCopy();

	UFUNCTION(BlueprintCallable)
	static void PrintIntsRefs();

	UFUNCTION(BlueprintCallable)
	static void PrintVectorsRefs();

	UFUNCTION(BlueprintCallable)
	static void PrintVectorConstRefParameter(const FVector& Value);

	UFUNCTION(BlueprintCallable)
	static void PrintVectorsReassignedReference();
	
#pragma endregion 
};
