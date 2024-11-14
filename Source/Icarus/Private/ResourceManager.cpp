// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceManager.h"

void UResourceManager::DecreaseResource(int32 Amount)
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

void UResourceManager::SetResource(int32 Amount)
{
    if (Amount > 0)
    {
        AvailableResource = Amount;
        OnResourceUpdated.Broadcast(AvailableResource);
    }
};

void UResourceManager::AddResource(int32 Amount)
{
    if (Amount < 0)
    {
        return;
    }

    AvailableResource += Amount;
    OnResourceUpdated.Broadcast(AvailableResource);
}