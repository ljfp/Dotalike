// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "Character/EnemyCharacter.h"
#include "Dotalike/Dotalike.h"
#include "AbilitySystem/DotalikeAbilitySystemComponent.h"
#include "AbilitySystem/DotalikeAttributeSet.h"

AEnemyCharacter::AEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UDotalikeAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	AttributeSet = CreateDefaultSubobject<UDotalikeAttributeSet>("AttributeSet");
}

void AEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	// We shouldn't be calling this over and over again, but it's a cheap operation so it's fine.
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	// Same comment as the former one.
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
