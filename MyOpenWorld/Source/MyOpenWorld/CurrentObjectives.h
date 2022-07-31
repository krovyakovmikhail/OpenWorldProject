// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/VerticalBox.h"

#include "CurrentObjectives.generated.h"

class AQuest;
class UObjectiveWidget;

/**
 * 
 */
UCLASS()
class MYOPENWORLD_API UCurrentObjectives : public UUserWidget
{
	GENERATED_BODY()

	public:
	
	UFUNCTION()
	void SetCurrentObjectives(AQuest * Quest);
	
	
	protected:
	
    UPROPERTY(EditDefaultsOnly)
    TSubclassOf<UObjectiveWidget> ObjectiveWidgetClass;
	
    UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
    UVerticalBox * ObjectivesList;

};
