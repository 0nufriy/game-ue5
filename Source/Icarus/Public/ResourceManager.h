// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ResourceManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FResourceUpdated, int32, NewAmount);

UCLASS(BlueprintType, Blueprintable)
class ICARUS_API UResourceManager : public UObject
{
	GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category="ShipResources")
    FResourceUpdated OnResourceUpdated;

    UFUNCTION(BlueprintPure, Category = "ShipResources")
    virtual const int32 GetResource() { return AvailableResource; }

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void DecreaseResource(int32 Amount = 1);

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void SetResource(int32 Amount);

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void AddResource(int32 Amount);

private:
    int32 AvailableResource = 0;
};
