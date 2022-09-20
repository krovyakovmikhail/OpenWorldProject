// Fill out your copyright notice in the Description page of Project Settings.


#include "Boat.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


// Sets default values
ABoat::ABoat()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Boat body"));
	RootComponent = BodyMesh;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArm->SetupAttachment(BodyMesh);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	

}

// Called when the game starts or when spawned
void ABoat::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABoat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector currentLocation = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	FVector movePosition = currentLocation + forwardVector * MoveSpeed *
		TargetForwardAxisValue * DeltaTime;
	SetActorLocation(movePosition, true);

}

// Called to bind functionality to input
void ABoat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABoat::MoveForward(float AxisValue)
{
	TargetForwardAxisValue = AxisValue;
}


