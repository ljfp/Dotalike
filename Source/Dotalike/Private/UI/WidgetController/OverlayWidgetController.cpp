// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/DotalikeAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UDotalikeAttributeSet* DotalikeAttributeSet = CastChecked<UDotalikeAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(DotalikeAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(DotalikeAttributeSet->GetMaxHealth());
}
