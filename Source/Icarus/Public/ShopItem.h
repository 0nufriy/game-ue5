// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShopItem.generated.h"

USTRUCT(Blueprintable, BlueprintType)
struct FShopItem
{
    GENERATED_BODY()

    FShopItem()
    {
        InfoName = "";
        Price = 0;
        AvailableAmount = 1;
        AmountPerItem = 1;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeStructureDefaultValue = ""))
    FName InfoName = "";

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeStructureDefaultValue = "0"))
    int32 Price = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeStructureDefaultValue = "1"))
    int32 AvailableAmount = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeStructureDefaultValue = "1"))
    int32 AmountPerItem = 1;
};
