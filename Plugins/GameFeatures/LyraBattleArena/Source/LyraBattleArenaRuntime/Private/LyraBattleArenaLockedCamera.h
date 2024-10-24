// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/LyraCameraMode.h"
#include "LyraBattleArenaLockedCamera.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class ULyraBattleArenaLockedCamera : public ULyraCameraMode
{
	GENERATED_BODY()

public:
	ULyraBattleArenaLockedCamera();

	//~ULyraCameraMode interface
	virtual void UpdateView(float DeltaTime) override;
	//~End of ULyraCameraMode interface

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
	FRotator CameraRotation;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
	float CameraOffsetDistance;

	UPROPERTY(EditDefaultsOnly, Category = "Camera Settings")
	float CameraSmoothSpeed;


};
