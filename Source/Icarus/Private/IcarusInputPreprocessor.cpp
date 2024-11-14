// Fill out your copyright notice in the Description page of Project Settings.


#include "IcarusInputPreprocessor.h"

#include "InputDeviceType.h"
#include "Kismet/KismetInputLibrary.h"

FIcarusInputPreprocessor::FIcarusInputPreprocessor(UInputLocalPlayerSubsystem& InInputLocalPlayerSubsystem)
	: InputSubsystem(InInputLocalPlayerSubsystem)
{
}

void FIcarusInputPreprocessor::Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor)
{
}

bool FIcarusInputPreprocessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
	EInputDeviceType InputType = GetInputType(InKeyEvent.GetKey());
	if (IsRelevantInput(SlateApp, InKeyEvent))
	{
		RefreshCurrentInputMethod(InputType);
	}
	
	return false;
}

bool FIcarusInputPreprocessor::HandleAnalogInputEvent(FSlateApplication& SlateApp,
	const FAnalogInputEvent& InAnalogInputEvent)
{
	return false;
}

bool FIcarusInputPreprocessor::HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& InPointerEvent)
{
	if (IsRelevantInput(SlateApp, InPointerEvent))
	{
		RefreshCurrentInputMethod(EInputDeviceType::Mouse);
	}
	
	return false;
}

bool FIcarusInputPreprocessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp,
	const FPointerEvent& InPointerEvent)
{
	if (IsRelevantInput(SlateApp, InPointerEvent))
	{
		RefreshCurrentInputMethod(EInputDeviceType::Mouse);
	}
	
	return false;
}

bool FIcarusInputPreprocessor::HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp,
	const FPointerEvent& InPointerEvent)
{
	if (IsRelevantInput(SlateApp, InPointerEvent))
	{
		RefreshCurrentInputMethod(EInputDeviceType::Mouse);
	}
	
	return false;
}

bool FIcarusInputPreprocessor::IsRelevantInput(const FSlateApplication& SlateApp, const FInputEvent& InputEvent) const
{
#if WITH_EDITOR
	// If we're stopped at a breakpoint we need for this input preprocessor to just ignore all incoming input
	// because we're now doing stuff outside the game loop in the editor and it needs to not block all that.
	// This can happen if you suspend input while spawning a dialog and then hit another breakpoint and then
	// try and use the editor, you can suddenly be unable to do anything.
	if (GIntraFrameDebuggingGameThread)
	{
		return false;
	}
#endif
	
	if (SlateApp.IsActive() 
		|| SlateApp.GetHandleDeviceInputWhenApplicationNotActive())
	{
		const ULocalPlayer& LocalPlayer = *InputSubsystem.GetLocalPlayerChecked();
		int32 ControllerId = LocalPlayer.GetControllerId();

#if WITH_EDITOR
		// PIE is a very special flower, especially when running two clients - we have two LocalPlayers with ControllerId 0
		// The editor has existing shenanigans for handling this scenario, so we're using those for now
		// Ultimately this would ideally be something the editor resolves at the SlateApplication level with a custom ISlateInputMapping or something
		GEngine->RemapGamepadControllerIdForPIE(LocalPlayer.ViewportClient, ControllerId);
#endif
		return ControllerId == InputEvent.GetUserIndex();
	}
	
	return false;
}


EInputDeviceType FIcarusInputPreprocessor::GetInputType(const FKey& Key)
{
	if (Key.IsGamepadKey())
	{
		return EInputDeviceType::Gamepad;
	}

	if (UKismetInputLibrary::Key_IsKeyboardKey(Key))
	{
		return EInputDeviceType::Keyboard;
	}

	return EInputDeviceType::Mouse;
}

void FIcarusInputPreprocessor::RefreshCurrentInputMethod(EInputDeviceType InputMethod)
{
	InputSubsystem.SetCurrentInputDeviceType(InputMethod);
}
