// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatResourceManager.h"

void UFloatResourceManager::DecreaseResource(float Amount)
{
    if (AvailableResource > 0)
    {
        if (Amount > AvailableResource)
        {
            Amount = AvailableResource;
        }

        AvailableResource -= Amount;

        OnResourceUpdated.Broadcast(AvailableResource);
    }
};

void UFloatResourceManager::SetResource(float Amount)
{
    if (Amount > 0)
    {
        AvailableResource = Amount;
        OnResourceUpdated.Broadcast(AvailableResource);
    }
};

void UFloatResourceManager::AddResource(float Amount)
{
    if (Amount < 0)
    {
        return;
    }

    AvailableResource += Amount;
    OnResourceUpdated.Broadcast(AvailableResource);
}