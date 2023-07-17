// Copyright 2023 Lautaro Javier Fernandez Pricco. All rights reserved.


#include "Actor/DotalikeEffectActor.h"
#include "AbilitySystem/DotalikeAttributeSet.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"

// Sets default values
ADotalikeEffectActor::ADotalikeEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
	Sphere->SetupAttachment(GetRootComponent());
}

void ADotalikeEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UDotalikeAttributeSet* DotalikeAttributeSet = Cast<UDotalikeAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UDotalikeAttributeSet::StaticClass()));
		check(DotalikeAttributeSet);
		
		//TODO: Remove const_cast. Use Gameplay Effect instead.
		UDotalikeAttributeSet* MutableDotalikeAttributeSet = const_cast<UDotalikeAttributeSet*>(DotalikeAttributeSet);
		MutableDotalikeAttributeSet->SetHealth(DotalikeAttributeSet->GetHealth() + 25.f);
		Destroy();
	}
}

void ADotalikeEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

// Called when the game starts or when spawned
void ADotalikeEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ADotalikeEffectActor::OnOverlap);
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ADotalikeEffectActor::EndOverlap);
}
