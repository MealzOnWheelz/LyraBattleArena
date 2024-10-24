
#include "LyraBattleArenaLockedCamera.h"
#include "GameFramework/Actor.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(LyraBattleArenaLockedCamera)

ULyraBattleArenaLockedCamera::ULyraBattleArenaLockedCamera()
{
	CameraRotation = FRotator(-55.0f, 180.0f, 0.0f);
	CameraOffsetDistance = -1600.0f;
	CameraSmoothSpeed = 5.0f;
}

void ULyraBattleArenaLockedCamera::UpdateView(float DeltaTime)
{
	AActor* TargetActor = GetTargetActor();
	if (!TargetActor)
	{
		return;
	}

	FVector CharacterLocation = TargetActor->GetActorLocation();

	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	if (!PC || !PC->IsLocalPlayerController())
	{
		return;
	}

	// Calculate the camera's desired pivot location using the rotation and offset distance
	FVector Offset = CameraRotation.Vector() * CameraOffsetDistance;
	FVector DesiredPivotLocation = CharacterLocation + Offset;

	// Smoothly interpolate the camera's current position towards the desired position
	View.Location = FMath::VInterpTo(View.Location, DesiredPivotLocation, DeltaTime, CameraSmoothSpeed);

	// Apply the final view settings
	View.Rotation = CameraRotation;
	View.ControlRotation = View.Rotation;
	View.FieldOfView = FieldOfView;
}