// MealzOnWheelz2024

#pragma once

#include "CoreMinimal.h"
#include "Components/ControllerComponent.h"
#include "InstancedStruct.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Engine/DataTable.h"
#include "LyraBattleArenaAttributeSet.h"
#include "LyraBattleArenaAbilityData.generated.h"

UENUM(BlueprintType)
enum class ETraceType : uint8
{
	None			UMETA(DisplayName = "None"),
	SingleSphere    UMETA(DisplayName = "SingleSphere"),
	SingleBox       UMETA(DisplayName = "SingleBox"),
	SingleSelf      UMETA(DisplayName = "SingleSelf"),
	MultiSphere		UMETA(DisplayName = "MultiSphere"),
	MultiBox		UMETA(DisplayName = "MultiBox"),
	MultiSelf       UMETA(DisplayName = "MultiSelf"),

};

UENUM(BlueprintType)
enum class ERootMotionDirection : uint8
{
	None			UMETA(DisplayName = "None"),
	Forward			UMETA(DisplayName = "Forward"),
	Backward		UMETA(DisplayName = "Backward"),

};

UENUM(BlueprintType)
enum class EInputTriggerType : uint8
{
	Channel			UMETA(DisplayName = "Channel"),
	Combo			UMETA(DisplayName = "Combo"),
	Instant			UMETA(DisplayName = "Instant"),
	Hold			UMETA(DisplayName = "Hold"),
	HoldAndRelease	UMETA(DisplayName = "HoldAndRelease"),
	Passive			UMETA(DisplayName = "Passive"),
	Toggle			UMETA(DisplayName = "Toggle"),

};

USTRUCT(BlueprintType)
struct FGameplayAbilityData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Widgets")
	FText AbilityDescription;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Widgets")
	TSoftObjectPtr<UTexture2D> AbilityIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data")
	TSoftClassPtr<UGameplayEffect> GameplayAbilityGameplayEffect;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data")
	TSoftClassPtr<AActor> GameplayAbilityActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data")
	EInputTriggerType InputTriggerType = EInputTriggerType::Instant;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "InputTriggerType == EInputTriggerType::Channel || InputTriggerType == EInputTriggerType::Combo || InputTriggerType == EInputTriggerType::Instant || InputTriggerType == EInputTriggerType::Hold || InputTriggerType == EInputTriggerType::HoldAndRelease", EditConditionHides))
	TSoftObjectPtr<UAnimMontage> AnimMontage1;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "InputTriggerType == EInputTriggerType::Channel || InputTriggerType == EInputTriggerType::Combo || InputTriggerType == EInputTriggerType::HoldAndRelease", EditConditionHides))
	TSoftObjectPtr<UAnimMontage> AnimMontage2;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "InputTriggerType == EInputTriggerType::Combo", EditConditionHides))
	TSoftObjectPtr<UAnimMontage> AnimMontage3;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "InputTriggerType == EInputTriggerType::Channel || InputTriggerType == EInputTriggerType::Combo || InputTriggerType == EInputTriggerType::Hold || InputTriggerType == EInputTriggerType::HoldAndRelease", EditConditionHides))
	float InputThresholdTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data")
	ETraceType TraceType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "TraceType != ETraceType::None", EditConditionHides))
	float TraceDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "TraceType == ETraceType::SingleSphere || TraceType == ETraceType::MultiSphere", EditConditionHides))
	float SphereRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "TraceType == ETraceType::SingleBox || TraceType == ETraceType::MultiBox", EditConditionHides))
	FVector BoxExtent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data")
	ERootMotionDirection RootMotionDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "RootMotionDirection != ERootMotionDirection::None", EditConditionHides))
	float Distance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "RootMotionDirection != ERootMotionDirection::None", EditConditionHides))
	float Height;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "RootMotionDirection != ERootMotionDirection::None", EditConditionHides))
	float Duration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability Data|Gameplay Ability Data", meta = (EditCondition = "TraceType == ETraceType::MultiSphere || TraceType == ETraceType::MultiBox", EditConditionHides))
	int32 MaxTargets;

};

USTRUCT(BlueprintType)
struct FDefaultCharacterData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Attribute Data")
	TMap<FGameplayTag, float> OverrideMagnitudeMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Attribute Data")
	TMap<FGameplayTag, TSoftClassPtr<UGameplayEffect>> OverrideGameplayEffectMap;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Animation Data")
	TSoftClassPtr<UAnimInstance> DefaultAnimClassLayer;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Cosmetic Data")
	TSoftClassPtr<AActor> DefaultCharacterPart;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Widget Data")
	FText CharacterName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Widget Data")
	TSoftObjectPtr<UTexture2D> CharacterIcon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data|Widget Data")
	TSoftObjectPtr<UTexture2D> ChooseCharacterIcon;

};


USTRUCT(BlueprintType)
struct FCharacterInstanceData
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FDefaultCharacterData"))
	FInstancedStruct CharacterInstanceDataInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FGameplayAbilityData"))
	FInstancedStruct PassiveDataInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FGameplayAbilityData"))
	FInstancedStruct BasicAttackDataInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FGameplayAbilityData"))
	FInstancedStruct Ability1DataInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FGameplayAbilityData"))
	FInstancedStruct Ability2DataInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Base Ability Data", meta = (BaseStruct = "FGameplayAbilityData"))
	FInstancedStruct Ability3DataInstance;

};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterIDSet, float, CharacterID);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ULyraBattleArenaAbilityData : public UControllerComponent
{
	GENERATED_BODY()

public:


	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category = "Character")
	FOnCharacterIDSet OnCharacterIDSet;

	// Instanced structs to hold Ability Data defaults
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data", meta = (BaseStruct = "FCharacterInstanceData"))
	FInstancedStruct DefaultCharacterInstanceData;

	// Instanced struct for current Ability data
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Data", meta = (BaseStruct = "FCharacterInstanceData"))
	FInstancedStruct CurrentCharacterInstanceData;

	// DataTable that holds the Ability Data
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Ability Data")
	UDataTable* CharacterDataTable;

};
