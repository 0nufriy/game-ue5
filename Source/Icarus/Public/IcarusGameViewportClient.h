// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "IcarusGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API UIcarusGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
    virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;

protected:
    bool OverrideInputAxisHandler(FInputKeyEventArgs& EventArgs, float& Delta, float& DeltaTime, int32& NumSamples);
    bool OverrideInputKey(FInputKeyEventArgs& EventArgs);
};
