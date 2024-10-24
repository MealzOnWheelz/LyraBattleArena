// Fill out your copyright notice in the Description page of Project Settings.


#include "LyraBattleArenaIconMaker.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/Texture2D.h"
#include "Engine/Texture2DDynamic.h"
#include "Rendering/Texture2DResource.h"
#include "Kismet/KismetRenderingLibrary.h"

// Sets default values
ALyraBattleArenaIconMaker::ALyraBattleArenaIconMaker()
{
	// Create components and attach them to the actor
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	IconMakerSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	IconMakerSkeletalMesh->SetupAttachment(RootComponent);  // Attach to the root

	IconMakerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	IconMakerCamera->SetupAttachment(RootComponent);  // Attach to the root

	IconMakerSceneCapture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("SceneCapture"));
	IconMakerSceneCapture->SetupAttachment(IconMakerCamera);  // Attach to the camera

	IconMakerPointLightRig = CreateDefaultSubobject<UBillboardComponent>(TEXT("PointLightRig"));
	IconMakerPointLightRig->SetupAttachment(RootComponent);  // Attach to the root

	IconMakerPointLight1 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
	IconMakerPointLight1->SetupAttachment(IconMakerPointLightRig);  // Attach to PointLightRig

	IconMakerPointLight2 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight2"));
	IconMakerPointLight2->SetupAttachment(IconMakerPointLightRig);  // Attach to PointLightRig

	IconMakerPointLight3 = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight3"));
	IconMakerPointLight3->SetupAttachment(IconMakerPointLightRig);  // Attach to PointLightRig
}

void ALyraBattleArenaIconMaker::CreateTextureFromScene()
{
	if (!IconMakerSceneCapture || !IconMakerRenderTarget)
	{
		UE_LOG(LogTemp, Warning, TEXT("SceneCaptureComponent2D or RenderTarget is not assigned!"));
		return;
	}

	// Ensure scene is captured to the RenderTarget
	IconMakerSceneCapture->CaptureScene();

	// Create Texture2D from the RenderTarget
	UTexture2D* CreatedTexture = RenderTargetToTexture2D(IconMakerRenderTarget);

	if (CreatedTexture)
	{
		// Ensure we notify Unreal Engine that we're about to edit the texture
		CreatedTexture->PreEditChange(nullptr);

		// Modify the texture's alpha channel as required
		ModifyTextureAlpha(CreatedTexture);

		// Notify Unreal Engine that the editing is done
		CreatedTexture->PostEditChange();

		UE_LOG(LogTemp, Log, TEXT("Texture created and alpha channel modified!"));
	}
}

UTexture2D* ALyraBattleArenaIconMaker::RenderTargetToTexture2D(UTextureRenderTarget2D* InRenderTarget)
{
	if (!InRenderTarget)
	{
		return nullptr;
	}

	// Get the render target dimensions and pixel data size
	int32 ImageWidth = InRenderTarget->SizeX;
	int32 ImageHeight = InRenderTarget->SizeY;

	// Read pixel data from the render target
	FTextureRenderTargetResource* RenderTargetResource = InRenderTarget->GameThread_GetRenderTargetResource();
	TArray<FColor> PixelData;
	RenderTargetResource->ReadPixels(PixelData);

	// Use UKismetRenderingLibrary to create a texture from the render target
	UTexture2D* NewTexture = UKismetRenderingLibrary::RenderTargetCreateStaticTexture2DEditorOnly(
		InRenderTarget,
		IconMakerTextureName,
		TextureCompressionSettings::TC_Default,
		TextureMipGenSettings::TMGS_NoMipmaps
	);

	if (NewTexture)
	{
		NewTexture->SRGB = InRenderTarget->SRGB;
		// Any other texture property you want to modify
	}

	return NewTexture;
}

void ALyraBattleArenaIconMaker::ModifyTextureAlpha(UTexture2D* Texture)
{
	if (!Texture)
	{
		return;
	}

	// Lock the texture's pixel data for editing
	FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];  // Get the first Mip level
	FColor* MipData = static_cast<FColor*>(Mip.BulkData.Lock(LOCK_READ_WRITE));

	for (int32 PixelIndex = 0; PixelIndex < Mip.SizeX * Mip.SizeY; PixelIndex++)
	{
		FColor& Pixel = MipData[PixelIndex];

		// Set alpha based on the existing alpha value
		if (Pixel.A > 0)
		{
			Pixel.A = 0; // Set to 0 (fully transparent)
		}
		else
		{
			Pixel.A = 255; // Set to 255 (fully opaque)
		}
	}

	Mip.BulkData.Unlock();
	Texture->UpdateResource();  // Refresh the texture resource
}
