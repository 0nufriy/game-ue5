// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "IcarusUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API UIcarusUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UIcarusUserSettings();
	
	virtual void ApplySettings(bool bCheckForCommandLineOverrides) override;

	UFUNCTION(BlueprintCallable, Category=Settings)
	static UIcarusUserSettings* GetIcarusUserSettings()
	{
		return Cast<UIcarusUserSettings>(UGameUserSettings::GetGameUserSettings());
	}

	UFUNCTION(BlueprintSetter, Category = "Settings|Audio")
	void SetMasterVolume(float Volume);
	
	UFUNCTION(BlueprintGetter, Category = "Settings|Audio")
	float GetMasterVolume() const { return MasterVolume; }

	UFUNCTION(BlueprintSetter, Category = "Settings|Audio")
	void SetMusicVolume(float Volume);

	UFUNCTION(BlueprintGetter, Category = "Settings|Audio")
	float GetMusicVolume() const { return MusicVolume; }

	UFUNCTION(BlueprintSetter, Category = "Settings|Audio")
	void SetSoundEffectsVolume(float Volume);

	UFUNCTION(BlueprintGetter, Category = "Settings|Audio")
	float GetSoundEffectsVolume() const { return SoundEffectsVolume; }

private:
	UPROPERTY(Config, BlueprintGetter = GetMasterVolume, BlueprintSetter = SetMasterVolume, Category = "Settings|Audio")
	float MasterVolume;
	
	UPROPERTY(Config, BlueprintGetter = GetMusicVolume, BlueprintSetter = SetMusicVolume, Category = "Settings|Audio")
	float MusicVolume;
	
	UPROPERTY(Config, BlueprintGetter = GetSoundEffectsVolume, BlueprintSetter = SetSoundEffectsVolume, Category = "Settings|Audio")
	float SoundEffectsVolume;

	const TCHAR* AudioSection = TEXT("AudioGroups");
	const TCHAR* MasterVolumeKey = TEXT("MasterVolume");
	const TCHAR* MusicVolumeKey = TEXT("MusicVolume");
	const TCHAR* SoundEffectsVolumeKey = TEXT("SoundEffectsVolume");
};
