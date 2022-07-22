// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Quest.generated.h"

class UObjective;




UCLASS()
class MYOPENWORLD_API AQuest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure)
	const TArray<UObjective*>& GetObjectives() const;
	
	UFUNCTION(BlueprintCallable, CallInEditor)
    void UpdateLocation();

	UFUNCTION(BlueprintCallable)
	FText GetName();
	
	UFUNCTION(BlueprintCallable)
	FText GetDescription();
	
	void TakeQuest(AActor * Character);
	
	UFUNCTION()
	bool IsAlreadyTaken();

	UFUNCTION()
	bool IsComleted() const;
	
	UFUNCTION()
	AQuest* const &GetPrerquisedQuest();
	
	DECLARE_MULTICAST_DELEGATE_OneParam(FOnQuestStatusUpdated, AQuest*)
	FOnQuestStatusUpdated OnQuestStatusUpdated;
	
	protected:
	
	UPROPERTY(EditAnywhere)
	FText Name;
	
	UPROPERTY(EditAnywhere)
	FText Descrition;
	
	UPROPERTY(EditAnywhere)
	TArray<UObjective*> Objectives;
	
	UPROPERTY(EditAnywhere)	
	bool bIsStoryQuest = true;
	
	UPROPERTY(EditAnywhere)
	bool bKeepObjectivesOrder = true;
	
	UPROPERTY(EditAnywhere)
	AQuest* PreviousQuest;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsTaken = false;

	void OnObjectiveCompleted(UObjective* Objective);


#if WITH_EDITOR	
	UFUNCTION(BlueprintCallable, CallInEditor)
    void AddLocationObjective();
    
    UFUNCTION(BlueprintCallable, CallInEditor)
    void AddInteractObjective();
#endif
	
};
