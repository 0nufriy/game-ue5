// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Engine/EngineTypes.h"
#include "UObject/ObjectMacros.h"
#include "EnvQueryTest_CapsuleOverlap.generated.h"

class AActor;
struct FCollisionQueryParams;
struct FCollisionShape;

UCLASS(MinimalAPI)
class UEnvQueryTest_CapsuleOverlap : public UEnvQueryTest
{
    GENERATED_UCLASS_BODY()

    UPROPERTY(EditDefaultsOnly, Category = Overlap)
    TEnumAsByte<enum ECollisionChannel> OverlapChannel;

    UPROPERTY(EditDefaultsOnly, Category = Overlap, AdvancedDisplay)
    uint32 bOverlapComplex : 1;

    virtual void RunTest(FEnvQueryInstance& QueryInstance) const override;

protected:
    bool RunOverlapBlocking(const FVector& ItemPos, const FCollisionShape& CollisionShape, const TArray<AActor*>& IgnoredActors, UWorld* World, enum ECollisionChannel Channel, const FCollisionQueryParams& Params) const;

};
