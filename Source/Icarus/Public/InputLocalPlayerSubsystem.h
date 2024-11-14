// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IcarusInputPreprocessor.h"
#include "InputDeviceType.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "Containers/Ticker.h"
#include "Framework/Application/SlateApplication.h"
#include "InputLocalPlayerSubsystem.generated.h"

class FIcarusInputPreprocessor;

/**
 * 
 */
UCLASS()
class ICARUS_API UInputLocalPlayerSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable)
	FKey GetLastPressedKey() const { return LastPressedKey; }
	
	void SetCurrentInputDeviceType(EInputDeviceType InputType);

	UFUNCTION(BlueprintCallable)
	EInputDeviceType GetCurrentInputDeviceType() const { return CurrentInputDeviceType; }

private:
	bool Tick(float DeltaTime);
	
private:
	FKey LastPressedKey = FKey();

	EInputDeviceType CurrentInputDeviceType = EInputDeviceType::Mouse;

	TSharedPtr<FIcarusInputPreprocessor> MakeInputProcessor();

	TSharedPtr<FIcarusInputPreprocessor> InputPreprocessor;

	FTSTicker::FDelegateHandle TickHandle;
};
