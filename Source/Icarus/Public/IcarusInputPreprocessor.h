// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputDeviceType.h"
#include "InputLocalPlayerSubsystem.h"
#include "Framework/Application/IInputProcessor.h"

class UInputLocalPlayerSubsystem;

/**
 * 
 */

class ICARUS_API FIcarusInputPreprocessor : public IInputProcessor
{
public:
	FIcarusInputPreprocessor(UInputLocalPlayerSubsystem& InInputLocalPlayerSubsystem);

	//~ Begin IInputProcessor Interface
	virtual void Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor) override;
	virtual bool HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent) override;
	virtual bool HandleAnalogInputEvent(FSlateApplication& SlateApp, const FAnalogInputEvent& InAnalogInputEvent) override;
	virtual bool HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override;
	virtual bool HandleMouseButtonDownEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override;
	virtual bool HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent) override;
	//~ End IInputProcessor Interface

protected:
	EInputDeviceType GetInputType(const FKey& Key);
	void RefreshCurrentInputMethod(EInputDeviceType InputMethod);
	bool IsRelevantInput(const FSlateApplication& SlateApp, const FInputEvent& InputEvent) const;

protected:
	UInputLocalPlayerSubsystem& InputSubsystem;
};
