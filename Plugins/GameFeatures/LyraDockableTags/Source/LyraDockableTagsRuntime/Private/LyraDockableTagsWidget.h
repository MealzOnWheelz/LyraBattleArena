// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LyraDockableTagsWidget.generated.h"

/**
 * 
 */
UCLASS()
class ULyraDockableTagsWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void ReleaseSlateResources(bool bReleaseChildren);
	virtual TSharedRef<SWidget> RebuildWidget() override;

	TSharedPtr<class SGameplayTagPicker> TagPicker;
	
	
};
