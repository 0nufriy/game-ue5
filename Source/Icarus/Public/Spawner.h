// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Spawntype.h"
#include "Math/Vector.h"
#include "ToolAmmoType.h"
#include "ItemBase.h"
#include "WeaponAmmoType.h"
#include "PlayerClass.h"
#include "Spawner.generated.h"

USTRUCT(Blueprintable)
struct FSpawner
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TEnumAsByte<ESpawnType> SpawnType = ESpawnType::World;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "SpawnType == ESpawnType::World", EditConditionHides))
    TSoftClassPtr<AItemBase> SpawnItemClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "SpawnType == ESpawnType::ToolAmmo", EditConditionHides))
    TEnumAsByte<EToolAmmoType> ToolAmmoType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "SpawnType == ESpawnType::WeaponAmmo", EditConditionHides))
    TEnumAsByte<EWeaponAmmoType> WeaponAmmoType;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (EditCondition = "SpawnType == ESpawnType::Revive", EditConditionHides))
    TEnumAsByte<EPlayerClass> PlayerClass;
};
