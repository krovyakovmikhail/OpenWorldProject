// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Quest.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestListComponent.generated.h"


class AQuest;
class UCurrentObjectives;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYOPENWORLD_API UQuestListComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UQuestListComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	UPROPERTY()
    TArray<AQuest*> AcceptedQuests;
	
	UPROPERTY(EditAnywhere)
	AQuest* ActiveQuest = nullptr;    
	
    UPROPERTY(EditAnywhere)
    TSubclassOf<UCurrentObjectives> CurrentObjectivesWidgetClass;


public:
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AddQuest(AQuest* Quest);
    const TArray<AQuest*>& GetQuests();
    
    AQuest* GetActiveQuest() const;
    void SetActiveQuest(AQuest* Quest);
    
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnQuestAction, AQuest *);	
    FOnQuestAction OnActiveQuestChanged;
	
};
