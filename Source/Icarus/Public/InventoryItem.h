// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemCategory.h"
#include "Spawner.h"
#include "InventoryItem.generated.h"

USTRUCT(Blueprintable)
struct FInventoryItem : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Title;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (MultiLine = true))
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSoftObjectPtr<UTexture2D> Image;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    EItemCategory Category;

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FSpawner Spawner;
};