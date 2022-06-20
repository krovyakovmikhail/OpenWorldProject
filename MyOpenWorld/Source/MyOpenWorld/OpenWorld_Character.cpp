// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenWorld_Character.h"

// Sets default values
AOpenWorld_Character::AOpenWorld_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	SpringArmComponent->SetupAttachment(GetRootComponent());
	CameraComponent->SetupAttachment(SpringArmComponent);
	

}

// Called when the game starts or when spawned
void AOpenWorld_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOpenWorld_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AOpenWorld_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("MoveForward", this, &AOpenWorld_Character::MveForward);
	InputComponent->BindAxis("MoveRight", this, &AOpenWorld_Character::MoveRight);
	InputComponent->BindAxis("Turn", this, &AOpenWorld_Character::Turn);
	InputComponent->BindAxis("LookUp", this, &AOpenWorld_Character::LookUp);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AOpenWorld_Character::Interact);

}

void AOpenWorld_Character::MveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void AOpenWorld_Character::MoveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);
}

void AOpenWorld_Character::Interact()
{
}

void AOpenWorld_Character::Turn(float value)
{
	AddControllerYawInput(value);
}

void AOpenWorld_Character::LookUp(float value)
{
	AddControllerPitchInput(value);
	
	//SpringArmComponent->SetRelativeRotation()
}


