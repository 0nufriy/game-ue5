// Fill out your copyright notice in the Description page of Project Settings.


#include "IcarusUserSettings.h"

#include "ProjectUserSettings.h"
#include "Sound/SoundClass.h"

UIcarusUserSettings::UIcarusUserSettings()
{
	if (const UProjectUserSettings* ProjectSettings = GetMutableDefault<UProjectUserSettings>())
	{
		MasterVolume = ProjectSettings->DefaultMasterVolume;
		MusicVolume = ProjectSettings->DefaultMusicVolume;
		SoundEffectsVolume = ProjectSettings->DefaultSoundEffectsVolume;
	}
}

void UIcarusUserSettings::ApplySettings(bool bCheckForCommandLineOverrides)
{
	Super::ApplySettings(bCheckForCommandLineOverrides);

	if (const UProjectUserSettings* ProjectSettings = GetMutableDefault<UProjectUserSettings>())
	{
		ProjectSettings->GetMasterSoundClass()->Properties.Volume = GetMasterVolume();
		ProjectSettings->GetSoundEffectsSoundClass()->Properties.Volume = GetSoundEffectsVolume();
		ProjectSettings->GetMusicSoundClass()->Properties.Volume = GetMusicVolume();
	}
}

void UIcarusUserSettings::SetMasterVolume(const float Volume)
{
	MasterVolume = Volume;
}

void UIcarusUserSettings::SetMusicVolume(const float Volume)
{
	MusicVolume = Volume;
}

void UIcarusUserSettings::SetSoundEffectsVolume(const float Volume)
{
	SoundEffectsVolume = Volume;
}