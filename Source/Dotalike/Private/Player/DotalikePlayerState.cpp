// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "Player/DotalikePlayerState.h"
#include "AbilitySystem/DotalikeAbilitySystemComponent.h"
#include "AbilitySystem/DotalikeAttributeSet.h"

ADotalikePlayerState::ADotalikePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UDotalikeAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UDotalikeAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ADotalikePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
