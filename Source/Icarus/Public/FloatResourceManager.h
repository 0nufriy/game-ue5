// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FloatResourceManager.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFloatResourceUpdated, float, NewAmount);

UCLASS(BlueprintType, Blueprintable)
class ICARUS_API UFloatResourceManager : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "ShipResources")
    FFloatResourceUpdated OnResourceUpdated;

    UFUNCTION(BlueprintPure, Category = "ShipResources")
    virtual const float GetResource() { return AvailableResource; }

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void DecreaseResource(float Amount = 1);

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void SetResource(float Amount);

    UFUNCTION(BlueprintCallable, Category = "ShipResources")
    virtual void AddResource(float Amount);

private:
    float AvailableResource = 0;

};
