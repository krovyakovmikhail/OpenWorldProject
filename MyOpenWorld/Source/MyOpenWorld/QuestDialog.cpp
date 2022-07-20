// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestDialog.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UQuestDialog::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (RejectButton)
	{
		RejectButton->OnReleased.AddDynamic(this, &UQuestDialog::RejectQuest);
	}
	if (AcceptButton)
	{
		AcceptButton->OnReleased.AddDynamic(this, &UQuestDialog::AcceptQuest);
	}
	APlayerController * PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	UWidgetBlueprintLibrary::SetInputMode_UIOnly(PC);
	PC->bShowMouseCursor = true;
}
