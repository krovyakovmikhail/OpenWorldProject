﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LocationMarker.generated.h"

// This class does not need to be modified.
UINTERFACE()
class ULocationMarker : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE_TwoParams(FOnLocationReached, AActor* /*LocationMarker*/,AActor* /*OverlappedActor*/);

class MYOPENWORLD_API ILocationMarker
{
	GENERATED_BODY()

	public:
	virtual void NotifyOverlapWithActor(AActor* LocationMarker, AActor* OverlappedActor);

	FOnLocationReached OnLocationReached;


	


	
};
