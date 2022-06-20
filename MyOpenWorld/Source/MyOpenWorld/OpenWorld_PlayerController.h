// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OpenWorld_PlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYOPENWORLD_API AOpenWorld_PlayerController : public APlayerController
{
	GENERATED_BODY()
	virtual void SetupInputComponent() override;

};


	

