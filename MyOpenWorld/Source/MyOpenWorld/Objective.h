// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Objective.generated.h"

UENUM()
enum class EObjectiveType : uint8
{
	Location,
	Interact,
	Collect,
	Kill
	};
/**
 * 
 */
DECLARE_MULTICAST_DELEGATE_OneParam(FOnObjectiveCompleted, UObjective* /*Objective*/);

UCLASS(Abstract)
class MYOPENWORLD_API UObjective : public UObject
{
	GENERATED_BODY()


	public:
	virtual void ActivateObjective(AActor * Character) {}
	
	UPROPERTY(EditAnywhere)
	FText Descrition;
	
	UPROPERTY(VisibleAnywhere)
	EObjectiveType Type;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsCompleted;
	
	UPROPERTY(VisibleAnywhere)
	bool bCanBeCompleted;
	
	FOnObjectiveCompleted OnObjectiveCompleted;
};

UCLASS()
class MYOPENWORLD_API UInteractionObjective : public UObjective
{
	GENERATED_BODY()

	public:
		UInteractionObjective();

		void ActivateObjective(AActor * Character) override;
		
		UPROPERTY(EditAnywhere, meta = (AllowedClasses = "InteractableObject"))
		AActor* Target;
	
};


UCLASS()
class MYOPENWORLD_API ULocationObjective : public UObjective
{
GENERATED_BODY()
	
public:
	ULocationObjective();
		
	void ActivateObjective(AActor * Character) override;

	UPROPERTY(EditAnywhere, meta = (AllowedClasses = "LocationMarker"))
	AActor* Marker;
};
