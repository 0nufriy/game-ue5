// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ICARUS_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
		virtual void BeginPlay();
		void CustomOnViewportResize(FViewport* ViewPort, uint32 val);
		
		
		UFUNCTION(BlueprintImplementableEvent)
		void DoResize();

};