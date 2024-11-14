// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "GameplayTagAssetInterface.h"
#include "ScifyCharacterBase.generated.h"

UCLASS()
class ICARUS_API AScifyCharacterBase : public ACharacter, public IGameplayTagAssetInterface, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AScifyCharacterBase();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Tags")
    FGameplayTagContainer OwnedGameplayTags;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
    FGenericTeamId TeamId = FGenericTeamId(1);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = OwnedGameplayTags; }

private:
    virtual FGenericTeamId GetGenericTeamId() const override { return TeamId; }
};
