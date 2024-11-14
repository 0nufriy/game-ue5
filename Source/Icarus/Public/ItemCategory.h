// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType, Category="Item")
enum class EItemCategory : uint8
{
    WeaponAmmo   UMETA(DisplayName = "Weapon Ammunition"),
    ToolAmmo     UMETA(DisplayName = "Tool Ammunition"),
    Weapon       UMETA(DisplayName = "Weapon"),
    Consumable   UMETA(DisplayName = "Consumable"),
    Special      UMETA(DisplayName = "Special"),
    Gear         UMETA(DisplayName = "Gear"),
};