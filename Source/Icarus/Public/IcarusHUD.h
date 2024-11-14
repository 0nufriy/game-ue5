// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/Widget.h"
#include "IcarusHUD.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API AIcarusHUD : public AHUD
{
	GENERATED_BODY()

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintImplementableEvent)
    void WidgetAdded(UWidget* Widget, ULocalPlayer* LocalPlayer);
	
};
