#pragma once

#include "CoreMinimal.h"
#include "CoreTypes.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"             
#include "Components/SkeletalMeshComponent.h"   
#include "Components/SceneCaptureComponent2D.h" 
#include "Components/BillboardComponent.h"      
#include "Components/PointLightComponent.h"  
#include "LyraBattleArenaIconMaker.generated.h"

UCLASS()
class ALyraBattleArenaIconMaker : public AActor
{
	GENERATED_BODY()

public:
	
	ALyraBattleArenaIconMaker();


	UFUNCTION(BlueprintCallable, CallInEditor, Category = Actor)
	void CreateTextureFromScene();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Actor)
	UTextureRenderTarget2D* IconMakerRenderTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Actor)
	FString IconMakerTextureName = "IconMakerTexture";

protected:


	UPROPERTY(VisibleAnywhere, Category = "Components")
	USkeletalMeshComponent* IconMakerSkeletalMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* IconMakerCamera;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	USceneCaptureComponent2D* IconMakerSceneCapture;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBillboardComponent* IconMakerPointLightRig;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPointLightComponent* IconMakerPointLight1;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPointLightComponent* IconMakerPointLight2;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UPointLightComponent* IconMakerPointLight3;
	UTexture2D* RenderTargetToTexture2D(UTextureRenderTarget2D* InRenderTarget);

	void ModifyTextureAlpha(UTexture2D* Texture);

	//void InvertAlpha(UFactory* NewAssetFactory);

private:
	UTexture2D* PostEditTexture;

};
