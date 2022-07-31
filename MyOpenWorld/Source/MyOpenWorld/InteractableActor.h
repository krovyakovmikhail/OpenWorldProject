// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractableObject_Interface.h"
#include "InteractableActor.generated.h"

UCLASS()
class MYOPENWORLD_API AInteractableActor : public AActor, public IInteractableObject_Interface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void OnInteractionFinished(AActor* ActorInteractedWithObject);
	


};
