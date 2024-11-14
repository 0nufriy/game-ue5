// Fill out your copyright notice in the Description page of Project Settings.


#include "InputLocalPlayerSubsystem.h"

#include "IcarusInputPreprocessor.h"

void UInputLocalPlayerSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InputPreprocessor = MakeInputProcessor();
	FSlateApplication::Get().RegisterInputPreProcessor(InputPreprocessor, 0);
	
	TickHandle = FTSTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UInputLocalPlayerSubsystem::Tick), 0.1f);
}

void UInputLocalPlayerSubsystem::Deinitialize()
{
	Super::Deinitialize();
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().UnregisterInputPreProcessor(InputPreprocessor);
	}
	InputPreprocessor.Reset();

	FTSTicker::GetCoreTicker().RemoveTicker(TickHandle);
}

bool UInputLocalPlayerSubsystem::Tick(float DeltaTime)
{
	QUICK_SCOPE_CYCLE_COUNTER(STAT_UCommonInputSubsystem_Tick);

	// Keep the CommonInputPreprocessor on top. Input swap and input filtering (e.g. "Ignore Gamepad Input")
	// both start to break down if narrow game preprocessors temporarily get in front of it.
	// This is a workaround to avoid a bigger intervention in the SlateApplication API for managing preprocessors.
	if (InputPreprocessor.IsValid() && FSlateApplication::IsInitialized())
	{
		FSlateApplication& SlateApplication = FSlateApplication::Get();
		if (SlateApplication.FindInputPreProcessor(InputPreprocessor) != 0)
		{
			SlateApplication.UnregisterInputPreProcessor(InputPreprocessor);
			SlateApplication.RegisterInputPreProcessor(InputPreprocessor, 0);
		}
	}
	
	return true; //repeat ticking
}

void UInputLocalPlayerSubsystem::SetCurrentInputDeviceType(EInputDeviceType InputType)
{
	CurrentInputDeviceType = InputType;
}

TSharedPtr<FIcarusInputPreprocessor> UInputLocalPlayerSubsystem::MakeInputProcessor()
{
	return MakeShared<FIcarusInputPreprocessor>(*this);
}