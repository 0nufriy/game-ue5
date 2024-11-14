// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShopItem.h"
#include "RoundShopItem.generated.h"
/**
 * 
 */
USTRUCT(BlueprintType)
struct FRoundShopItem
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FShopItem Item;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<int32, int32> AmountOverride;
};
