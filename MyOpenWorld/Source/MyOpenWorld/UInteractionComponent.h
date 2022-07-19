// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/SphereComponent.h"

#include "UInteractionComponent.generated.h"


UCLASS( ClassGroup="Collision", meta=(DisplayName = "Interaction Collision", BlueprintSpawnableComponent) )
class MYOPENWORLD_API UUInteractionComponent : public USphereComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUInteractionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	
	UFUNCTION(BlueprintCallable)
	void Interact();

	
	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> InteractMessageClass;
	
	UPROPERTY()
	UUserWidget* InteractMessage;
	
	UPROPERTY()
	AActor * ActorToInteract;
	
	UFUNCTION()
	void OnInteractionCompBeginOverlap(UPrimitiveComponent* OverlappedComponent,	AActor* OtherActor, UPrimitiveComponent* OtherComp,	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
	void OnInteractionCompEndOverlap(UPrimitiveComponent* OverlappedComponent,	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	


		
};
