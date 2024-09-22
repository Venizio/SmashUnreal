// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SmashCharacter.h"
#include "EnhancedInputComponent.h"
#include "AssetTypeActions/AssetDefinition_SoundBase.h"
#include "Character/SmashCharacterStateMachine.h"
#include "Interfaces/ITargetDevice.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASmashCharacter::ASmashCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASmashCharacter::BeginPlay()
{
	Super::BeginPlay();
	CreateStateMachine();
	GetCharacterMovement()->JumpZVelocity = 800.f;
	InitializeStateMachine();
}

// Called every frame
void ASmashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TickStateMachine(DeltaTime);
	RotateMeshUsingOrientX();
}

// Called to bind functionality to input
void ASmashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	SetupMappingContextIntoController();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (EnhancedInputComponent == nullptr) return;
	BindInputMoveXAxisAndActions(EnhancedInputComponent);
	BindInputMoveYAxisAndActions(EnhancedInputComponent);
}

float ASmashCharacter::GetOrientX() const
{
	return OrientX;
}

void ASmashCharacter::SetOrientX(float NewOrientX)
{
	OrientX = NewOrientX;
}

void ASmashCharacter::RotateMeshUsingOrientX() const
{
	FRotator Rotation = GetMesh()->GetRelativeRotation();
	Rotation.Yaw = -90.f * OrientX;
	GetMesh()->SetRelativeRotation(Rotation);
}

void ASmashCharacter::CreateStateMachine()
{
	StateMachine = NewObject<USmashCharacterStateMachine>(this);
}

void ASmashCharacter::InitializeStateMachine()
{
	if (StateMachine == nullptr) return;
	StateMachine->Init(this);
}

void ASmashCharacter::TickStateMachine(float DeltaTime) const
{
	if (StateMachine == nullptr)return;
	StateMachine->Tick(DeltaTime);
}

void ASmashCharacter::SetupMappingContextIntoController() const
{
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController == nullptr) return;
	ULocalPlayer* Player = PlayerController->GetLocalPlayer();
	if (Player == nullptr) return;
	UEnhancedInputLocalPlayerSubsystem* InputSystem = Player->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (InputSystem == nullptr) return;
	InputSystem->AddMappingContext(InputMappingContext, 0);
}

float ASmashCharacter::GetInputMoveX() const
{
	return InputMoveX;
}

void ASmashCharacter::SetInputMoveXTreshold(float XTreshOldValue)
{
	InputMoveXTreshHold = XTreshOldValue;
}

void ASmashCharacter::OnInputMoveX(const FInputActionValue& InputActionValue)
{
	InputMoveX = InputActionValue.Get<float>();
}

void ASmashCharacter::OnInputMoveY(const FInputActionValue& InputActionValue)
{
	InputMoveY = InputActionValue.Get<float>();
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Orange,
		FString::Printf(TEXT("%f"), InputMoveY)
	);
}

void ASmashCharacter::OnInputMoveXFast(const FInputActionValue& InputActionValue)
{
	InputMoveX = InputActionValue.Get<float>();
	InputMoveXFastEvent.Broadcast(InputMoveX);
}

void ASmashCharacter::OnCanceledInput()
{
	InputMoveX = 0;
	InputMoveY = 0;
}

void ASmashCharacter::BindInputMoveXAxisAndActions(UEnhancedInputComponent* EnhancedInputComponent)
{
	if (InputData == nullptr)return;
	if (InputData->InputActionMoveX)
	{
		EnhancedInputComponent->BindAction(
			InputData->InputActionMoveX,
			ETriggerEvent::Started,
			this,
			&ASmashCharacter::OnInputMoveX
		);

		EnhancedInputComponent->BindAction(
			InputData->InputActionMoveX,
			ETriggerEvent::Completed,
			this,
			&ASmashCharacter::OnCanceledInput
		);
	}
	if (InputData->InputActionMoveXFast)
	{
		EnhancedInputComponent->BindAction(
			InputData->InputActionMoveXFast,
			ETriggerEvent::Triggered,
			this,
			&ASmashCharacter::OnInputMoveXFast);
	}
}

void ASmashCharacter::BindInputMoveYAxisAndActions(UEnhancedInputComponent* EnhancedInputComponent)
{
	if (InputData == nullptr)return;
	if (InputData->InputActionMoveY)
	{
		EnhancedInputComponent->BindAction(
			InputData->InputActionMoveY,
			ETriggerEvent::Started,
			this,
			&ASmashCharacter::OnInputMoveY);


		EnhancedInputComponent->BindAction(
			InputData->InputActionMoveY,
			ETriggerEvent::Completed,
			this,
			&ASmashCharacter::OnCanceledInput);
	}
}
