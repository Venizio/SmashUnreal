// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyFirstCustomActor.generated.h"

class UMyFirstCustomObject;

UCLASS()
class INITIATIONDEBUG_API AMyFirstCustomActor : public AActor
{
	GENERATED_BODY()

#pragma region CustomObject

public:
	void CreateCustomObjectAndPrintHello();

	UMyFirstCustomObject* GetCustomObject() const;

	void SetCustomObject(UMyFirstCustomObject* InCustomObject);

protected:
	UPROPERTY()
	TObjectPtr<UMyFirstCustomObject> CustomObject;

#pragma endregion

#pragma region UPROPERTY Examples

protected:
	UPROPERTY(EditAnywhere)
	float MyEditableFloat = 0.f;

	UPROPERTY(VisibleAnywhere)
	float MyVisibleFloat = 0.f;

	UPROPERTY(EditDefaultsOnly)
	float MyEditableFloatArchetypeOnly = 0.f;

	UPROPERTY(BlueprintReadWrite)
	float MyBlueprintReadWriteFloat = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MyEditableBlueprintReadWriteFloat = 0.f;

private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess="true"))
	float MyPrivateFloat = 0.f;

#pragma endregion

#pragma region UFUNCTION Examples

protected:
	UFUNCTION(BlueprintCallable)
	void PrintMyBodyIsReadyOnScreen();

	UFUNCTION(BlueprintPure)
	int GetTenValue();

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);

#pragma endregion

#pragma region Raw Pointers

public:
	void ApplyNullPointerCrash();
	void CheckPointerBeforeManipulation();

#pragma endregion

#pragma region Unreal Defaults

public:
	// Sets default values for this actor's properties
	AMyFirstCustomActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

#pragma endregion
};
