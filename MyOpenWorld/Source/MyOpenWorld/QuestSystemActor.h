// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableObject_Interface.h"
#include "QuestDialog.h"
#include "GameFramework/Actor.h"
#include "QuestSystemActor.generated.h"

UCLASS()
class MYOPENWORLD_API AQuestSystemActor : public AActor, public IInteractableObject_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AQuestSystemActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interact_Implementation(AActor* ActorInteractedWithObject) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UQuestDialog> QuestDialogClass;
	
};
