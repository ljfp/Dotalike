// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/DotalikeAttributeSet.h"
#include "AbilitySystem/DotalikeAbilitySystemComponent.h"
#include "GameplayEffectTypes.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDotalikeAttributeSet* DotalikeAttributeSet = CastChecked<UDotalikeAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(DotalikeAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(DotalikeAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(DotalikeAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(DotalikeAttributeSet->GetMaxMana());

	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetHealthAttribute());
	//AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetManaAttribute());
}

void UOverlayWidgetController::BindCallbackToDependencies()
{
	const UDotalikeAttributeSet* DotalikeAttributeSet = CastChecked<UDotalikeAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnHealthChangedCallback);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnMaxHealthChangedCallback);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnManaChangedCallback);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetMaxManaAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnMaxManaChangedCallback);

	Cast<UDotalikeAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[](const FGameplayTagContainer& AssetTags)
		{
			for (const FGameplayTag& Tag : AssetTags)
			{
				const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, Msg);
			}
		}
	);
}

void UOverlayWidgetController::OnHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnManaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxManaChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}
