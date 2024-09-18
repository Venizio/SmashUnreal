// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MatchGameMode.generated.h"
class AArenaPlayerStart;
class ASmashCharacter;
/**
 *
 */
UCLASS()
class SMASHUE_API AMatchGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

private:
	TSubclassOf<ASmashCharacter> GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType) const;
	void FindPlayerStartActorsInArena(TArray<AArenaPlayerStart*>& ResultsActors);
	void SpawnCharacter(const TArray<AArenaPlayerStart*>& SpawnPoints);

protected:
	UPROPERTY(EditAnywhere)
	TArray<ASmashCharacter*> CharactersInsideArena;
};
