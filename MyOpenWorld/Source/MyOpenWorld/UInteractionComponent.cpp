// Fill out your copyright notice in the Description page of Project Settings.


#include "UInteractionComponent.h"
#include "InteractableObject_Interface.h"
#include "Blueprint/UserWidget.h"


// Sets default values for this component's properties
UUInteractionComponent::UUInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	OnComponentBeginOverlap.AddDynamic(this, &UUInteractionComponent::OnInteractionCompBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this,	&UUInteractionComponent::OnInteractionCompEndOverlap);

	
}

void UUInteractionComponent::Interact()
{
	if (ActorToInteract)
	{
		IInteractableObject_Interface::Execute_Interact(ActorToInteract, GetOwner());
		
	}
}

void UUInteractionComponent::OnInteractionCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		if (!OtherActor->Implements<UInteractableObject_Interface>())
		{
			return;
		}
			ActorToInteract = OtherActor;
			if (!InteractMessage)
			{
				if (InteractMessageClass)
				{
					InteractMessage = CreateWidget<UUserWidget>(GetWorld(),	InteractMessageClass);
				}
			}
			if (InteractMessage && !InteractMessage->IsInViewport())
			{
				InteractMessage->AddToViewport();
			}
	}

	


}

void UUInteractionComponent::OnInteractionCompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (ActorToInteract == OtherActor)
	{
		ActorToInteract = nullptr;
		if (InteractMessage)
		{
			InteractMessage->RemoveFromViewport();
		}
	}
	

}




