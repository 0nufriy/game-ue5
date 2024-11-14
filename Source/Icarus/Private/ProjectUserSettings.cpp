// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectUserSettings.h"

#include "Sound/SoundClass.h"

UProjectUserSettings::UProjectUserSettings(const FObjectInitializer& ObjectInitializer)
	: UDeveloperSettings(ObjectInitializer)
{
	CategoryName = "Game";
	SectionName = "User Settings";
}

void UProjectUserSettings::PostInitProperties()
{
	Super::PostInitProperties();

	LoadObjects();
}

#if WITH_EDITOR
void UProjectUserSettings::PostEditChangeChainProperty(FPropertyChangedChainEvent& PropertyChangedEvent)
{
    Super::PostEditChangeChainProperty(PropertyChangedEvent);

	LoadObjects();
}
#endif

void UProjectUserSettings::LoadObjects()
{
	LoadSoundClass(MasterSoundClassName,  MasterSoundClass);
	LoadSoundClass(SoundEffectsSoundClassName, SoundEffectsSoundClass);
	LoadSoundClass(MusicSoundClassName, MusicSoundClass);
}

void UProjectUserSettings::LoadSoundClass(FSoftObjectPath& SoundClassName, TObjectPtr<USoundClass>& SoundClass)
{
	if (SoundClass)
	{
		SoundClass->RemoveFromRoot();
		SoundClass = nullptr;
	}
	
	if (!SoundClass)
	{
		if (UObject* SoundClassObject = SoundClassName.TryLoad())
		{
			SoundClass = CastChecked<USoundClass>(SoundClassObject);
			SoundClass->AddToRoot();
		}
	}

	if (!SoundClass)
	{
		UE_LOG(LogAudio, Warning, TEXT("Failed to load SoundClassObject from path '%s'.  Attempting to fall back to engine default."), *SoundClassName.GetAssetPathString());
		SoundClassName.SetPath(EngineSoundsDir / "Master");
		if (UObject* SoundClassObject = SoundClassName.TryLoad())
		{
			SoundClass = CastChecked<USoundClass>(SoundClassObject);
			SoundClass->AddToRoot();
		}
	}

	if (!SoundClass)
	{
		UE_LOG(LogAudio, Error, TEXT("Failed to load SoundClassObject from path '%s'."), *SoundClassName.GetAssetPathString());
	}
}
