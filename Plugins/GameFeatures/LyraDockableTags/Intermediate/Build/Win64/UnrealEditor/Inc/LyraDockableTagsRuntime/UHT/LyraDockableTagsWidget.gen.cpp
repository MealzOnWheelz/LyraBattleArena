// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LyraDockableTagsRuntime/Private/LyraDockableTagsWidget.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLyraDockableTagsWidget() {}

// Begin Cross Module References
LYRADOCKABLETAGSRUNTIME_API UClass* Z_Construct_UClass_ULyraDockableTagsWidget();
LYRADOCKABLETAGSRUNTIME_API UClass* Z_Construct_UClass_ULyraDockableTagsWidget_NoRegister();
UMG_API UClass* Z_Construct_UClass_UUserWidget();
UPackage* Z_Construct_UPackage__Script_LyraDockableTagsRuntime();
// End Cross Module References

// Begin Class ULyraDockableTagsWidget
void ULyraDockableTagsWidget::StaticRegisterNativesULyraDockableTagsWidget()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULyraDockableTagsWidget);
UClass* Z_Construct_UClass_ULyraDockableTagsWidget_NoRegister()
{
	return ULyraDockableTagsWidget::StaticClass();
}
struct Z_Construct_UClass_ULyraDockableTagsWidget_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "IncludePath", "LyraDockableTagsWidget.h" },
		{ "ModuleRelativePath", "Private/LyraDockableTagsWidget.h" },
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULyraDockableTagsWidget>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_ULyraDockableTagsWidget_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UUserWidget,
	(UObject* (*)())Z_Construct_UPackage__Script_LyraDockableTagsRuntime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ULyraDockableTagsWidget_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_ULyraDockableTagsWidget_Statics::ClassParams = {
	&ULyraDockableTagsWidget::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x00A010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ULyraDockableTagsWidget_Statics::Class_MetaDataParams), Z_Construct_UClass_ULyraDockableTagsWidget_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_ULyraDockableTagsWidget()
{
	if (!Z_Registration_Info_UClass_ULyraDockableTagsWidget.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULyraDockableTagsWidget.OuterSingleton, Z_Construct_UClass_ULyraDockableTagsWidget_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_ULyraDockableTagsWidget.OuterSingleton;
}
template<> LYRADOCKABLETAGSRUNTIME_API UClass* StaticClass<ULyraDockableTagsWidget>()
{
	return ULyraDockableTagsWidget::StaticClass();
}
ULyraDockableTagsWidget::ULyraDockableTagsWidget(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR(ULyraDockableTagsWidget);
ULyraDockableTagsWidget::~ULyraDockableTagsWidget() {}
// End Class ULyraDockableTagsWidget

// Begin Registration
struct Z_CompiledInDeferFile_FID_LyraStarterGame_Plugins_GameFeatures_LyraDockableTags_Source_LyraDockableTagsRuntime_Private_LyraDockableTagsWidget_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_ULyraDockableTagsWidget, ULyraDockableTagsWidget::StaticClass, TEXT("ULyraDockableTagsWidget"), &Z_Registration_Info_UClass_ULyraDockableTagsWidget, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULyraDockableTagsWidget), 823001392U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_LyraStarterGame_Plugins_GameFeatures_LyraDockableTags_Source_LyraDockableTagsRuntime_Private_LyraDockableTagsWidget_h_992452031(TEXT("/Script/LyraDockableTagsRuntime"),
	Z_CompiledInDeferFile_FID_LyraStarterGame_Plugins_GameFeatures_LyraDockableTags_Source_LyraDockableTagsRuntime_Private_LyraDockableTagsWidget_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_LyraStarterGame_Plugins_GameFeatures_LyraDockableTags_Source_LyraDockableTagsRuntime_Private_LyraDockableTagsWidget_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
