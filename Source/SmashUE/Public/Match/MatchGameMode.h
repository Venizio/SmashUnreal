// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arena/ArenaSettings.h"
#include "Character/SmashCharacterInputData.h"
#include "GameFramework/GameModeBase.h"
#include "Character/SmashCharacterSettings.h"
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

	USmashCharacterInputData* LoadInputDataFromConfig();
	UInputMappingContext* LoadInputMappingContextFromConfig();
	TSubclassOf<ASmashCharacter> GetSmashCharacterClassFromInputType(EAutoReceiveInput::Type InputType);
	void FindPlayerStartActorsInArena(TArray<AArenaPlayerStart*>& ResultsActors) const;
	void SpawnCharacter(const TArray<AArenaPlayerStart*>& SpawnPoints);

protected:
	UPROPERTY(EditAnywhere)
	TArray<ASmashCharacter*> CharactersInsideArena;
};
