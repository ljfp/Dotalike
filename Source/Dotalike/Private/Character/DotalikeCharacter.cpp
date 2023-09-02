// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "Character/DotalikeCharacter.h"
#include "Player/DotalikePlayerState.h"
#include "Player/DotalikePlayerController.h"
#include "UI/HUD/DotalikeHUD.h"
#include "AbilitySystem/DotalikeAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ADotalikeCharacter::ADotalikeCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void ADotalikeCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the server
	InitAbilityActorInfo();
}

void ADotalikeCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the client
	InitAbilityActorInfo();
}

void ADotalikeCharacter::InitAbilityActorInfo()
{
	ADotalikePlayerState* DotalikePlayerState = GetPlayerState<ADotalikePlayerState>();
	check(DotalikePlayerState);
	DotalikePlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(DotalikePlayerState, this);
	Cast<UDotalikeAbilitySystemComponent>(DotalikePlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = DotalikePlayerState->GetAbilitySystemComponent();
	AttributeSet = DotalikePlayerState->GetAttributeSet();

	// PlayerController can and will be null in the case of a server-only player.
	if (ADotalikePlayerController* DotalikePlayerController = Cast<ADotalikePlayerController>(GetController()))
	{
		if (ADotalikeHUD* DotalikeHUD = Cast<ADotalikeHUD>(DotalikePlayerController->GetHUD()))
		{
			DotalikeHUD->InitOverlay(DotalikePlayerController, DotalikePlayerState, AbilitySystemComponent, AttributeSet);
		}

	}
}
