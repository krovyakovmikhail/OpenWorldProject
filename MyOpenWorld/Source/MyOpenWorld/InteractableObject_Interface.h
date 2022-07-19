// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractableObject_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractableObject_Interface : public UInterface
{
	GENERATED_BODY()
};

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnInteractionFinished, AActor* /*InteractableObject*/, AActor* /*ActorInteractedWithObject*/);


/**
 * 
 */
class MYOPENWORLD_API IInteractableObject_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void Interact(AActor* ActorInteractedWithObject);

	UFUNCTION()
		virtual void Interact_Implementation(AActor* ActorInteractedWithObject) {};

		virtual void NotifyInteractionFinished(AActor* InteractableObject, AActor* ActorInteractedWithObject);
	

	FOnInteractionFinished OnInteractionFinished;
};
