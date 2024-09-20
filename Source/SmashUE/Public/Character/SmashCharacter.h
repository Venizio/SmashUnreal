// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SmashCharacterInputData.h"
#include "SmashCharacterSettings.h"
#include "GameFramework/Character.h"
#include "SmashCharacter.generated.h"


class USmashCharacterStateMachine;


UCLASS()
class SMASHUE_API ASmashCharacter : public ACharacter
{
	GENERATED_BODY()
#pragma region unreal Default

public:
	// Sets default values for this character's properties
	ASmashCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
#pragma endregion
#pragma region orient

public:
	float GetOrientX() const;
	void SetOrientX(float NewOrientX);

protected:
	UPROPERTY(BlueprintReadOnly)
	float OrientX = 1.f;
	void RotateMeshUsingOrientX() const;
#pragma endregion
#pragma region StateMachine

public:
	void CreateStateMachine();
	void InitializeStateMachine();
	void TickStateMachine(float DeltaTime) const;

protected:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<USmashCharacterStateMachine> StateMachine;

#pragma endregion


#pragma region Input data / MappingContext

public:
	UPROPERTY()
	TObjectPtr<USmashCharacterInputData> InputData;
	UPROPERTY()
	TObjectPtr<UInputMappingContext> InputMappingContext;

protected:
	void SetupMappingContextIntoController() const;

#pragma endregion

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputMoveXEvent, float, inputMoveX);
#pragma region inputMoveX

public:
	float GetInputMoveX() const;
	void SetInputMoveXTreshold(float XTreshOldValue);
	UPROPERTY()
	FInputMoveXEvent InputMoveXFastEvent;

protected:
	UPROPERTY()
	float InputMoveX = 0.f;
	float InputMoveY = 0.f;

public:
	float GetInputMoveY() const
	{
		return InputMoveY;
	}

	void SetInputMove(float inInputMoveY)
	{
		this->InputMoveY = inInputMoveY;
	}

protected:
	float InputMoveXTreshHold;

public:
	float GetInputMoveXTreshHold() const
	{
		return InputMoveXTreshHold;
	}

private:
	void OnInputMoveX(const FInputActionValue& InputActionValue);
	void OnInputMoveY(const FInputActionValue& InputActionValue);
	void OnInputMoveXFast(const FInputActionValue& InputActionValue);
	void OnCanceledInput();
	void BindInputMoveXAxisAndActions(UEnhancedInputComponent* EnhancedInputComponent);
	void BindInputMoveYAxisAndActions(UEnhancedInputComponent* EnhancedInputComponent);
#pragma endregion
};
