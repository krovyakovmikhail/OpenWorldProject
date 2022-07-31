// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestSystemActor.h"

#include "Quest.h"
#include "QuestDialog.h"
#include "QuestListComponent.h"


// Sets default values
AQuestSystemActor::AQuestSystemActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AQuestSystemActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AQuestSystemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AQuestSystemActor::Interact_Implementation(AActor* ActorInteractedWithObject)
{
	if (ActorInteractedWithObject)
    {
	    // check if actor has QuestList and can accept quests
	    UActorComponent * ActorQuestListComp =	    ActorInteractedWithObject->GetComponentByClass( UQuestListComponent::StaticClass());
		
	    if (ActorQuestListComp)
	    {
		    UQuestListComponent * ActorQuestList = Cast<UQuestListComponent>(ActorQuestListComp);
		    // past any limitations and quest choosing logic
	    	
		    TArray<AActor*> AttachedActors;
		    GetAttachedActors(AttachedActors);
		    bool HadQuestsAvailable = false;
	    	
		    for (AActor * Actor : AttachedActors)
		    {
			    if (AQuest * Quest = Cast<AQuest>(Actor))
			    {
				    if (Quest->IsAlreadyTaken() || (Quest->GetPrerquisedQuest() && !Quest->GetPrerquisedQuest()->IsComleted()))
				    {
						continue;
				    }
				    if (QuestDialogClass)
				    {
					    UQuestDialog * QuestDialog = CreateWidget<UQuestDialog>(GetWorld(),	QuestDialogClass);
					    QuestDialog->Init(Quest);
					    QuestDialog->OnQuestAccepted.BindUObject(ActorQuestList, &UQuestListComponent::AddQuest, Quest);
					    QuestDialog->OnQuestQuited.BindLambda([this, ActorInteractedWithObject]()
					    {
							NotifyInteractionFinished(this, ActorInteractedWithObject);
					    });
					    QuestDialog->AddToViewport();
				    }
				    HadQuestsAvailable = true;
				}
		    }
		    if (!HadQuestsAvailable)
		    {
				NotifyInteractionFinished(this, ActorInteractedWithObject);
		    }
	    }
    }
	
}

