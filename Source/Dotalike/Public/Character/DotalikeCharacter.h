// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "DotalikeCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DOTALIKE_API ADotalikeCharacter : public ACharacterBase
{
	GENERATED_BODY()

public:
	ADotalikeCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilityActorInfo();
};
