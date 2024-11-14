// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/UObjectGlobals.h"
#include "AIController.h"
#include "AIController_SmoothFocus.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API AAIController_SmoothFocus : public AAIController
{
	GENERATED_BODY()

protected:
    FRotator SmoothTargetRotation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SmoothFocus")
    float SmoothFocusInterpSpeed = 30.0f;

public:
    AAIController_SmoothFocus(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

    virtual void UpdateControlRotation(float DeltaTime, bool bUpdatePawn) override;
	
};
