// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "UI/Widget/DotalikeUserWidget.h"

void UDotalikeUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}

/* This will be implemented in Blueprints
void UDotalikeUserWidget::WidgetControllerSet()
{
}
*/