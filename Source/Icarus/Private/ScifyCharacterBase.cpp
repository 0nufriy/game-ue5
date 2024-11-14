// Fill out your copyright notice in the Description page of Project Settings.


#include "ScifyCharacterBase.h"

// Sets default values
AScifyCharacterBase::AScifyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScifyCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AScifyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AScifyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}