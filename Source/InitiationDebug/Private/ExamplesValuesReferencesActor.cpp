// Fill out your copyright notice in the Description page of Project Settings.


#include "ExamplesValuesReferencesActor.h"


// Sets default values
AExamplesValuesReferencesActor::AExamplesValuesReferencesActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AExamplesValuesReferencesActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExamplesValuesReferencesActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AExamplesValuesReferencesActor::PrintIntsCopy()
{
	int FirstInt = 1;
	int FirstIntCopy = FirstInt;
	FirstInt = 2;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Yellow,
		FString::Printf(TEXT("FirstInt = %d"), FirstInt)
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("FirstIntCopy = %d"), FirstIntCopy)
	);
}

void AExamplesValuesReferencesActor::PrintVectorsCopy()
{
	FVector Position = FVector::Zero();
	FVector PositionCopy = Position;
	Position.X = 10.0;
	Position.Y = 25.0;
	Position.Z = -102.0;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Yellow,
		FString::Printf(TEXT("Position = %s"), *Position.ToString())
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("PositionCopy = %s"), *PositionCopy.ToString())
	);
}

void AExamplesValuesReferencesActor::PrintIntsRefs()
{
	int FirstInt = 1;
	int& FirstIntRef = FirstInt;
	FirstInt = 2;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Yellow,
		FString::Printf(TEXT("FirstInt = %d"), FirstInt)
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("FirstIntRef = %d"), FirstIntRef)
	);
}

void AExamplesValuesReferencesActor::PrintVectorsRefs()
{
	FVector Position = FVector::Zero();
	FVector& PositionRef = Position;
	Position.X = 10.0;
	Position.Y = 25.0;
	Position.Z = -102.0;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Yellow,
		FString::Printf(TEXT("Position = %s"), *Position.ToString())
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("Positionref = %s"), *PositionRef.ToString())
	);
}

void AExamplesValuesReferencesActor::PrintVectorConstRefParameter(const FVector& Value)
{
	//Value = FVector::Zero();
	//Value.X = 1;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("Value Ref = %s"), *Value.ToString())
	);
}

void AExamplesValuesReferencesActor::PrintVectorsReassignedReference()
{
	FVector A = FVector(1.f, 2.f, 3.f);
	FVector B = FVector(4.f, 5.f, 6.f);

	FVector& Ref = A;
	Ref = B;

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("A = %s"), *A.ToString())
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("B = %s"), *B.ToString())
	);

	GEngine->AddOnScreenDebugMessage(
		-1,
		3.f,
		FColor::Red,
		FString::Printf(TEXT("Ref = %s"), *Ref.ToString())
	);
}
