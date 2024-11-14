// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipResourcesSubsystem.h"

void UShipResourcesSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);


    const UEnum* WeaponAmmoTypeEnum = StaticEnum<EWeaponAmmoType>();

    for (int32 i = 0; i < WeaponAmmoTypeEnum->NumEnums() - 1; i++)
    {
        UResourceManager* NewManager = NewObject<UResourceManager>();
        WeaponAmmoManagers.Add(static_cast<EWeaponAmmoType>(i), NewManager);
    }

    const UEnum* ToolAmmoTypeEnum = StaticEnum<EToolAmmoType>();

    for (int32 i = 0; i < ToolAmmoTypeEnum->NumEnums() - 1; i++)
    {
        UFloatResourceManager* NewManager = NewObject<UFloatResourceManager>();
        ToolAmmoManagers.Add(static_cast<EToolAmmoType>(i), NewManager);
    }

    MoneyManager = NewObject<UResourceManager>();
}

UResourceManager* UShipResourcesSubsystem::GetWeaponAmmoManager(EWeaponAmmoType AmmoType)
{
    return WeaponAmmoManagers[AmmoType];
}

UFloatResourceManager* UShipResourcesSubsystem::GetToolAmmoManager(EToolAmmoType AmmoType)
{
    return ToolAmmoManagers[AmmoType];
}

UResourceManager* UShipResourcesSubsystem::GetMoneyManager()
{
    return MoneyManager;
}

TArray<UFloatResourceManager*> UShipResourcesSubsystem::GetAllToolAmmoManagers()
{
    TArray<UFloatResourceManager*> ResultArray;
    ToolAmmoManagers.GenerateValueArray(ResultArray);
    return ResultArray;
}

TArray<UResourceManager*> UShipResourcesSubsystem::GetAllWeaponAmmoManagers()
{
    TArray<UResourceManager*> ResultArray;
    WeaponAmmoManagers.GenerateValueArray(ResultArray);
    return ResultArray;
}