// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_Cooldown.h"
#include "BTDecorator_RefreshedCooldown.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API UBTDecorator_RefreshedCooldown : public UBTDecorator_Cooldown
{
	GENERATED_BODY()

    virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	
};
