// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "GameplayTagAssetInterface.h"
#include "MechanismBase.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ICARUS_API AMechanismBase : public AStaticMeshActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gameplay Tags")
    FGameplayTagContainer OwnedGameplayTags;

public:
    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = OwnedGameplayTags; }
};
