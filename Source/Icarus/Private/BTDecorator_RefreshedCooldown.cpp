// Fill out your copyright notice in the Description page of Project Settings.


#include "BTDecorator_RefreshedCooldown.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(BTDecorator_RefreshedCooldown)

void UBTDecorator_RefreshedCooldown::InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const
{
    FBTCooldownDecoratorMemory* DecoratorMemory = CastInstanceNodeMemory<FBTCooldownDecoratorMemory>(NodeMemory);
    if (InitType == EBTMemoryInit::Initialize)
    {
        DecoratorMemory->LastUseTimestamp = OwnerComp.GetWorld()->GetTimeSeconds() - CoolDownTime;
    }

    DecoratorMemory->bRequestedRestart = false;
}