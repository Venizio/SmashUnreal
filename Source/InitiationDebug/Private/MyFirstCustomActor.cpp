// Fill out your copyright notice in the Description page of Project Settings.


#include "InitiationDebug/Public/MyFirstCustomActor.h"
#include "InitiationDebug/Public/MyFirstCustomObject.h"
#include "Kismet/GameplayStatics.h"

void AMyFirstCustomActor::CreateCustomObjectAndPrintHello()
{
	CustomObject = NewObject<UMyFirstCustomObject>();
	CustomObject->PrintHelloOnScreen();
}

UMyFirstCustomObject* AMyFirstCustomActor::GetCustomObject() const
{
	UMyFirstCustomObject* ObjectToReturn = CustomObject;
	return ObjectToReturn;
}

void AMyFirstCustomActor::SetCustomObject(UMyFirstCustomObject* InCustomObject)
{
	CustomObject = InCustomObject;
}

void AMyFirstCustomActor::PrintMyBodyIsReadyOnScreen()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Magenta,
		TEXT("hey je passe par ici lol")
		TEXT("༼ つ ◕_◕ ༽つ")
	);
}

int AMyFirstCustomActor::GetTenValue()
{
	return 10;
}

void AMyFirstCustomActor::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
}

void AMyFirstCustomActor::ApplyNullPointerCrash()
{
	APlayerController* PlayerController = nullptr;
	PlayerController->Pause();
}

void AMyFirstCustomActor::CheckPointerBeforeManipulation()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController != nullptr)
	{
		PlayerController->Pause();
	}
}

AMyFirstCustomActor::AMyFirstCustomActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AMyFirstCustomActor::BeginPlay()
{
	Super::BeginPlay();
	CreateCustomObjectAndPrintHello();
	OnActorBeginOverlap.AddDynamic(this, &AMyFirstCustomActor::OnOverlapBegin);
}

void AMyFirstCustomActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
