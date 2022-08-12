// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "OpenWorld_Character.generated.h"

UCLASS()
class MYOPENWORLD_API AOpenWorld_Character : public ACharacter
{
	GENERATED_BODY()


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category ="SpringArm")
		USpringArmComponent * SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category ="Camera")
		UCameraComponent * CameraComponent;

		


public:
	// Sets default values for this character's properties
	AOpenWorld_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float value);
	UFUNCTION()
	void MoveRight(float value);
	UFUNCTION()
	void Interact();
	UFUNCTION()
	void Turn(float value);
	UFUNCTION()
	void LookUp(float value);
	//UFUNCTION()
    //void Jump();
	

};
