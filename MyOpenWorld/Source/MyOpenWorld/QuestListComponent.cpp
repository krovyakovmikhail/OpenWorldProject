// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestListComponent.h"

#include "CurrentObjectives.h"
#include "Quest.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
UQuestListComponent::UQuestListComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UQuestListComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

	if (CurrentObjectivesWidgetClass)
	{
		UCurrentObjectives* CurrentObjectivesWidget = CreateWidget<UCurrentObjectives>(GetWorld(), CurrentObjectivesWidgetClass);
		
		OnActiveQuestChanged.AddUObject(CurrentObjectivesWidget,&UCurrentObjectives::SetCurrentObjectives);
		
		CurrentObjectivesWidget->AddToViewport();
	}
	
}


// Called every frame
void UQuestListComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UQuestListComponent::AddQuest(AQuest* Quest)
{

	if (ActiveQuest == nullptr || ActiveQuest->IsComleted())
	{
		SetActiveQuest(Quest);		
	}
	
	
	if (Quest)
	{
		AcceptedQuests.AddUnique(Quest);
		Quest->TakeQuest(GetOwner());
		Quest->OnQuestStatusUpdated.AddLambda([this](AQuest * Quest)
		{
			if (ActiveQuest == Quest)
			{
				if (OnActiveQuestChanged.IsBound())
				{
					
					OnActiveQuestChanged.Broadcast(Quest);
				}
			}
		});
	}

}

const TArray<AQuest*>& UQuestListComponent::GetQuests()
{
	return AcceptedQuests;
}

AQuest* UQuestListComponent::GetActiveQuest() const
{
	return ActiveQuest;
}

void UQuestListComponent::SetActiveQuest(AQuest* Quest)
{
	//if (AcceptedQuests.Contains(Quest))
    //{
	    ActiveQuest = Quest;
		
	    if (OnActiveQuestChanged.IsBound())
	    {
		 OnActiveQuestChanged.Broadcast(Quest);
	    }
   // }

}

