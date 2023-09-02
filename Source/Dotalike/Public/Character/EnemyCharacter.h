// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Interaction/TargetInterface.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DOTALIKE_API AEnemyCharacter : public ACharacterBase, public ITargetInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	// Belongs to ITargetInterface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;
};
