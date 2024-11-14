// Fill out your copyright notice in the Description page of Project Settings.


#include "AIController_SmoothFocus.h"
#include "Kismet/KismetMathLibrary.h"
#include <Navigation/CrowdFollowingComponent.h>
#include UE_INLINE_GENERATED_CPP_BY_NAME(AIController_SmoothFocus)

AAIController_SmoothFocus::AAIController_SmoothFocus(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer.SetDefaultSubobjectClass<UCrowdFollowingComponent>(TEXT("PathFollowingComponent")))
{
    SetGenericTeamId(FGenericTeamId(2));
}

void AAIController_SmoothFocus::UpdateControlRotation(float DeltaTime, bool bUpdatePawn)
{
    //Call the original method without updating the pawn
    Super::UpdateControlRotation(DeltaTime, false);

    //Smooth and change the pawn rotation
    if (bUpdatePawn)
    {
        //Get pawn
        APawn* const MyPawn = GetPawn();
        //Get Pawn current rotation
        const FRotator CurrentPawnRotation = MyPawn->GetActorRotation();

        //Calculate smoothed rotation
        SmoothTargetRotation = UKismetMathLibrary::RInterpTo_Constant(MyPawn->GetActorRotation(), ControlRotation, DeltaTime, SmoothFocusInterpSpeed);
        //Check if we need to change
        if (CurrentPawnRotation.Equals(SmoothTargetRotation, 1e-3f) == false)
        {
            //Change rotation using the Smooth Target Rotation
            MyPawn->FaceRotation(SmoothTargetRotation, DeltaTime);
        }
    }
}