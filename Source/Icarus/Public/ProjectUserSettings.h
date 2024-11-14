// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectUserSettings.generated.h"

/**
 * 
 */
UCLASS(config=Game, defaultconfig, MinimalAPI)
class UProjectUserSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UProjectUserSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	virtual void PostInitProperties() override;

#if WITH_EDITOR
	virtual void PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent) override;
#endif

	// Audio
	UPROPERTY(config, EditAnywhere, Category="Audio", meta=(AllowedClasses="/Script/Engine.SoundClass", DisplayName="Master Sound Class"))
	FSoftObjectPath MasterSoundClassName;

	UPROPERTY(config, EditAnywhere, Category="Audio", meta=(AllowedClasses="/Script/Engine.SoundClass", DisplayName="Sound Effects Sound Class"))
	FSoftObjectPath SoundEffectsSoundClassName;

	UPROPERTY(config, EditAnywhere, Category="Audio", meta=(AllowedClasses="/Script/Engine.SoundClass", DisplayName="Master Sound Class"))
	FSoftObjectPath MusicSoundClassName;

	UPROPERTY(config, EditAnywhere, Category="Audio", DisplayName="Default Master Volume", meta=(ClampMin="0.0", ClampMax="1.0"))
	float DefaultMasterVolume = 0.8f;

	UPROPERTY(config, EditAnywhere, Category="Audio", DisplayName="Default Sound Effects Volume", meta=(ClampMin="0.0", ClampMax="1.0"))
	float DefaultSoundEffectsVolume = 0.8f;

	UPROPERTY(config, EditAnywhere, Category="Audio", DisplayName="Default Music Volume", meta=(ClampMin="0.0", ClampMax="1.0"))
	float DefaultMusicVolume = 0.8f;

public:
	ICARUS_API void LoadObjects();

	ICARUS_API USoundClass* GetMasterSoundClass() const { return MasterSoundClass; }
	ICARUS_API USoundClass* GetSoundEffectsSoundClass() const { return SoundEffectsSoundClass; }
	ICARUS_API USoundClass* GetMusicSoundClass() const { return MusicSoundClass; }

private:
	void LoadSoundClass(FSoftObjectPath& SoundClassName, TObjectPtr<USoundClass>& SoundClass);
	
private:
	UPROPERTY(Transient)
	TObjectPtr<USoundClass> MasterSoundClass;

	UPROPERTY(Transient)
	TObjectPtr<USoundClass> SoundEffectsSoundClass;

	UPROPERTY(Transient)
	TObjectPtr<USoundClass> MusicSoundClass;
	
	const FString EngineSoundsDir = TEXT("/Engine/EngineSounds");
};
