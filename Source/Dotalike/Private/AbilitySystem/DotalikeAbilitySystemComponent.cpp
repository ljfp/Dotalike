// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "AbilitySystem/DotalikeAbilitySystemComponent.h"

void UDotalikeAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UDotalikeAbilitySystemComponent::EffectApplied);
}

void UDotalikeAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Effect Applied"));
}
