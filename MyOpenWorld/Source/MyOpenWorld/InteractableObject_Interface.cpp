// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableObject_Interface.h"

// Add default functionality here for any IInteractableObject_Interface functions that are not pure virtual.

void IInteractableObject_Interface::NotifyInteractionFinished(AActor* InteractableObject, AActor* ActorInteractedWithObject)
{
	{
		if (OnInteractionFinished.IsBound())
		{
			OnInteractionFinished.Broadcast(InteractableObject, ActorInteractedWithObject);
		}
	}
}
