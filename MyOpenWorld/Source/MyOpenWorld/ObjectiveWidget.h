// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ObjectiveWidget.generated.h"

class UTextBlock;
class UCheckBox;
class UObjective;
/**
 * 
 */
UCLASS()
class MYOPENWORLD_API UObjectiveWidget : public UUserWidget
{
	GENERATED_BODY()

	public:
		void Init(UObjective* Objective);

		void RemoveWidget(); 


	
	protected:
		UPROPERTY(meta = (BindWidgetOptional))
		UCheckBox * ComplitionCheck;
		UPROPERTY(meta = (BindWidgetOptional))
		UTextBlock * DescriptionText;

	
};
