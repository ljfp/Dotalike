// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/DotalikeWidgetController.h"
#include "GameplayEffectTypes.h"
#include "OverlayWidgetController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class DOTALIKE_API UOverlayWidgetController : public UDotalikeWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbackToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

protected:
	void OnHealthChangedCallback(const FOnAttributeChangeData& Data) const;
	void OnMaxHealthChangedCallback(const FOnAttributeChangeData& Data) const;
};
