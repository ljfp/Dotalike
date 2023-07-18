// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "UI/WidgetController/DotalikeWidgetController.h"

void UDotalikeWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController = WCParams.PlayerController;
	PlayerState = WCParams.PlayerState;
	AbilitySystemComponent = WCParams.AbilitySystemComponent;
	AttributeSet = WCParams.AttributeSet;
}
