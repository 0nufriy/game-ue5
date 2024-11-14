// Fill out your copyright notice in the Description page of Project Settings.


#include "GetLocalPlayer.h"

// Sets default values for this component's properties
UGetLocalPlayer::UGetLocalPlayer()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGetLocalPlayer::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
ULocalPlayer* UGetLocalPlayer::GetLocalPlayerFromController(APlayerController* PlayerController) const{
	return PlayerController->GetLocalPlayer();
}
// Called every frame
void UGetLocalPlayer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

