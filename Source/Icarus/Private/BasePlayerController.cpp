// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerController.h"
#include "Kismet/GameplayStatics.h"

void ABasePlayerController::BeginPlay()
{
    Super::BeginPlay();

    FViewport::ViewportResizedEvent.AddUObject(this, &ABasePlayerController::CustomOnViewportResize);
}

void ABasePlayerController::CustomOnViewportResize(FViewport* ViewPort, uint32 val) 
{
    DoResize();
}
