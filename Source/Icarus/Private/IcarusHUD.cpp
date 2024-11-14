// Fill out your copyright notice in the Description page of Project Settings.


#include "IcarusHUD.h"
#include "Blueprint/GameViewportSubsystem.h"

void AIcarusHUD::BeginPlay()
{
    Super::BeginPlay();

    if (UGameViewportSubsystem* Subsystem = UGameViewportSubsystem::Get(GetWorld()))
    {
        Subsystem->OnWidgetAdded.AddUObject(this, &AIcarusHUD::WidgetAdded);
    }
}