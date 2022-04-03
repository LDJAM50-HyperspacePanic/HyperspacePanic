// Fill out your copyright notice in the Description page of Project Settings.


#include "HPCharacter.h"

// Sets default values
AHPCharacter::AHPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AHPCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AHPCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AHPCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AHPCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AHPCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Wrench"), IE_Pressed, this, &AHPCharacter::WackWrench);
}

void AHPCharacter::MoveForward(float AxisVal)
{
	AddMovementInput(GetActorForwardVector() * AxisVal);
}

void AHPCharacter::MoveRight(float AxisVal)
{
	AddMovementInput(GetActorRightVector() * AxisVal);
}

void AHPCharacter::WackWrench()
{
}

