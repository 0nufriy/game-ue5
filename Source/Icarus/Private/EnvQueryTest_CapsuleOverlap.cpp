// Fill out your copyright notice in the Description page of Project Settings.

#include "EnvQueryTest_CapsuleOverlap.h"
#include "Components/CapsuleComponent.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_VectorBase.h"
#include "EnvironmentQuery/Contexts/EnvQueryContext_Querier.h"

UEnvQueryTest_CapsuleOverlap::UEnvQueryTest_CapsuleOverlap(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
    Cost = EEnvTestCost::High;
    ValidItemType = UEnvQueryItemType_VectorBase::StaticClass();
    SetWorkOnFloatValues(false);
}

void UEnvQueryTest_CapsuleOverlap::RunTest(FEnvQueryInstance& QueryInstance) const
{
    if (AActor* Owner = Cast<AActor>(QueryInstance.Owner.Get()))
    {
        if (UCapsuleComponent* OwnerCapsule = Cast<UCapsuleComponent>(Owner->GetRootComponent()))
        {
            UObject* DataOwner = QueryInstance.Owner.Get();
            BoolValue.BindData(DataOwner, QueryInstance.QueryID);

            FCollisionQueryParams OverlapParams(SCENE_QUERY_STAT(EnvQueryOverlap), bOverlapComplex);

            bool bWantsHit = BoolValue.GetValue();

            FCollisionShape CollisionCapsule = FCollisionShape::MakeCapsule(OwnerCapsule->GetScaledCapsuleRadius(), OwnerCapsule->GetScaledCapsuleHalfHeight());

            typedef bool(UEnvQueryTest_CapsuleOverlap::* FRunOverlapSignature)(const FVector&, const FCollisionShape&, const TArray<AActor*>&, UWorld*, enum ECollisionChannel, const FCollisionQueryParams&) const;
            FRunOverlapSignature OverlapFunc = (FRunOverlapSignature)&UEnvQueryTest_CapsuleOverlap::RunOverlapBlocking;

            TArray<AActor*> IgnoredActors;
            QueryInstance.PrepareContext(UEnvQueryContext_Querier::StaticClass(), IgnoredActors);

            for (FEnvQueryInstance::ItemIterator It(this, QueryInstance); It; ++It)
            {
                const FVector ItemLocation = GetItemLocation(QueryInstance, It.GetIndex());
                AActor* ItemActor = GetItemActor(QueryInstance, It.GetIndex());
                IgnoredActors.Push(ItemActor);

                const bool bHit = RunOverlapBlocking(ItemLocation + FVector(0, 0, OwnerCapsule->GetScaledCapsuleHalfHeight()), CollisionCapsule, IgnoredActors, QueryInstance.World, OverlapChannel, OverlapParams);
                It.SetScore(TestPurpose, FilterType, bHit, bWantsHit);

                IgnoredActors.Pop(/*bAllowShrinking=*/false);
            }
        }
    }
}

bool UEnvQueryTest_CapsuleOverlap::RunOverlapBlocking(const FVector& ItemPos, const FCollisionShape& CollisionShape, const TArray<AActor*>& IgnoredActors, UWorld* World, enum ECollisionChannel Channel, const FCollisionQueryParams& Params) const
{
    FCollisionQueryParams OverlapParams(Params);
    OverlapParams.AddIgnoredActors(IgnoredActors);

    const bool bHit = World->OverlapBlockingTestByChannel(ItemPos, FQuat::Identity, Channel, CollisionShape, OverlapParams);
    return bHit;
}