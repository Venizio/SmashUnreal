// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorRenamed.generated.h"

UCLASS()
class INITIATIONDEBUG_API AMyActorRenamed : public AActor
{
	GENERATED_BODY()

#pragma region To Rename

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> ActorPropertyRenamed;

#pragma endregion

#pragma region Unreal Defaults

public:
	// Sets default values for this actor's properties
	AMyActorRenamed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma endregion
};
