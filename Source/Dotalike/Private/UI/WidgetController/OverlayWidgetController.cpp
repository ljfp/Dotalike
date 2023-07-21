// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/DotalikeAttributeSet.h"
#include "GameplayEffectTypes.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDotalikeAttributeSet* DotalikeAttributeSet = CastChecked<UDotalikeAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(DotalikeAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(DotalikeAttributeSet->GetMaxHealth());

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetHealthAttribute());
}

void UOverlayWidgetController::BindCallbackToDependencies()
{
	const UDotalikeAttributeSet* DotalikeAttributeSet = CastChecked<UDotalikeAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnHealthChangedCallback);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(DotalikeAttributeSet->GetMaxHealthAttribute())
		.AddUObject(this, &UOverlayWidgetController::OnMaxHealthChangedCallback);
}

void UOverlayWidgetController::OnHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnMaxHealthChangedCallback(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}
