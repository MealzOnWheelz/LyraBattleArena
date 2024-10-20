// Fill out your copyright notice in the Description page of Project Settings.


#include "LyraDockableTagsWidget.h"
#include "SGameplayTagPicker.h"
#include "Widgets/SCompoundWidget.h"



void ULyraDockableTagsWidget::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);

	// Release Slate resources
	TagPicker.Reset();
}

TSharedRef<SWidget> ULyraDockableTagsWidget::RebuildWidget()
{
	// Create and configure the Slate widget
	TagPicker = SNew(SGameplayTagPicker)
		.ReadOnly(false)
		.MaxHeight(0.0f) // unbounded
		.MultiSelect(false)
		.SettingsName(TEXT("Manager"))
		.GameplayTagPickerMode(EGameplayTagPickerMode::ManagementMode);

	// Return the Slate widget wrapped in SCompoundWidget
	return TagPicker.ToSharedRef();
}



