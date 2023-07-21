// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "AbilitySystem/DotalikeAttributeSet.h"
#include "Net/UnrealNetwork.h"

UDotalikeAttributeSet::UDotalikeAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(50.f);
	InitMaxMana(50.f);
}

void UDotalikeAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Register attributes for replication on the clients
	DOREPLIFETIME_CONDITION_NOTIFY(UDotalikeAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDotalikeAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDotalikeAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDotalikeAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UDotalikeAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDotalikeAttributeSet, Health, OldHealth);
}

void UDotalikeAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDotalikeAttributeSet, MaxHealth, OldMaxHealth);
}

void UDotalikeAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDotalikeAttributeSet, Mana, OldMana);
}

void UDotalikeAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDotalikeAttributeSet, MaxMana, OldMaxMana);
}
