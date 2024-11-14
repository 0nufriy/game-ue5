// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "WeaponAmmoType.h"
#include "ToolAmmoType.h"
#include "ResourceManager.h"
#include "FloatResourceManager.h"
#include "ShipResourcesSubsystem.generated.h"

UCLASS()
class ICARUS_API UShipResourcesSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:

    virtual void Initialize(FSubsystemCollectionBase& Collection) override;

    UFUNCTION(BlueprintPure, Category = "ShipResources|WeaponAmmo")
    UResourceManager* GetWeaponAmmoManager(EWeaponAmmoType AmmoType);

    UFUNCTION(BlueprintPure, Category = "ShipResources|ToolAmmo")
    UFloatResourceManager* GetToolAmmoManager(EToolAmmoType AmmoType);

    UFUNCTION(BlueprintPure, Category = "ShipResources|Money")
    UResourceManager* GetMoneyManager();

    UFUNCTION(BlueprintCallable, Category = "ShipResources|ToolAmmo")
    TArray<UFloatResourceManager*> GetAllToolAmmoManagers();

    UFUNCTION(BlueprintCallable, Category = "ShipResources|WeaponAmmo")
    TArray<UResourceManager*> GetAllWeaponAmmoManagers();


private:
    TMap<EWeaponAmmoType, UResourceManager*> WeaponAmmoManagers;

    TMap<EToolAmmoType, UFloatResourceManager*> ToolAmmoManagers;

    UPROPERTY()
    UResourceManager* MoneyManager;
};
