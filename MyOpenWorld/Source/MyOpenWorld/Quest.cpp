// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest.h"

#include "CurrentObjectives.h"
#include "Objective.h"

// Sets default values
AQuest::AQuest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false	;

}

// Called when the game starts or when spawned
void AQuest::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

const TArray<UObjective*>& AQuest::GetObjectives() const
{
	return Objectives;
}

void AQuest::UpdateLocation()
{
	AActor * ParentActor = GetAttachParentActor();
	if (ParentActor)
	{
		SetActorLocation(ParentActor->GetActorLocation());
	}
}

FText AQuest::GetName()
{
	return Name;
}

FText AQuest::GetDescription()
{
	return  Descrition; 
}

void AQuest::TakeQuest(AActor* Character)
{
	if (bIsTaken)
	{
		return;
	}
	for (int32 i = 0; i < Objectives.Num(); i++)
	{
		if (Objectives[i])
		{
			Objectives[i]->ActivateObjective(Character);
			Objectives[i]->bCanBeCompleted = !bKeepObjectivesOrder || i == 0;
			Objectives[i]->OnObjectiveCompleted.AddUObject(this, &AQuest::OnObjectiveCompleted);
			
		}
	}
	bIsTaken = true;
}

bool AQuest::IsAlreadyTaken()
{
	return bIsTaken;
}

bool AQuest::IsComleted() const
{

	
	if (bKeepObjectivesOrder && Objectives.IsValidIndex((Objectives.Num()-1)))
	{
		return Objectives[Objectives.Num()-1]->bIsCompleted;
	}
	for (auto* Objective : Objectives)
	{
		if (Objective && !Objective->bIsCompleted)
		{
			return  false;
		}
	}
	
	return true;
	
	
}

AQuest* const& AQuest::GetPrerquisedQuest()
{
	return PreviousQuest;
}

void AQuest::OnObjectiveCompleted(UObjective* Objective)
{
	if (bKeepObjectivesOrder)
    {
	    int32 ObjectiveIndex;
	    if (Objectives.Find(Objective, ObjectiveIndex) &&  Objectives.IsValidIndex(ObjectiveIndex + 1))
	    {
	    Objectives[ObjectiveIndex + 1]->bCanBeCompleted = true;
		}
    }
    if (OnQuestStatusUpdated.IsBound())
    {
		OnQuestStatusUpdated.Broadcast(this);
    }

}

#if WITH_EDITOR

void AQuest::AddLocationObjective()
{
	Objectives.Add(NewObject<ULocationObjective>(this));
}

void AQuest::AddInteractObjective()
{
	Objectives.Add(NewObject<UInteractionObjective>(this));

}

#endif


