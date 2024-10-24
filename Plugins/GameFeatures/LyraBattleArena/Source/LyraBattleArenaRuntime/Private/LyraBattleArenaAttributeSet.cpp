#include "LyraBattleArenaAttributeSet.h"
#include "Net/UnrealNetwork.h"

// Constructor
ULyraBattleArenaAttributeSet::ULyraBattleArenaAttributeSet()
	:CharacterID(0.0f)
	,Resource(10.0f)
	,MaxResource(10.0f)
	,Power(1.0f)
	,MaxPower(10.0f)
	,Defense(1.0f)
	,MaxDefense(10.0f)
	,Speed(0.85f)
	,MaxSpeed(2.0f)
{
}

// Override for PreAttributeBaseChange
void ULyraBattleArenaAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);
	// Clamp the attribute to its allowed range [0, Max]
	ClampAttribute(Attribute, NewValue);
}

// Override for PreAttributeChange
void ULyraBattleArenaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// Clamp the attribute to its allowed range [0, Max]
	ClampAttribute(Attribute, NewValue);
}

// Replication functions
void ULyraBattleArenaAttributeSet::OnRep_CharacterID(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, CharacterID, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_Resource(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Resource, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_MaxResource(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MaxResource, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Power(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Power, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_MaxPower(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MaxPower, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Defense, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_MaxDefense(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MaxDefense, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Speed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Speed, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_MaxSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MaxSpeed, OldValue);
}

void ULyraBattleArenaAttributeSet::ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetResourceAttribute())
	{
		// Clamp Resource value between 0 and MaxResource
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxResource.GetCurrentValue());
	}
	else if (Attribute == GetPowerAttribute())
	{
		// Clamp Power value between 0 and MaxPower
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxPower.GetCurrentValue());
	}
	else if (Attribute == GetDefenseAttribute())
	{
		// Clamp Defense value between 0 and MaxDefense
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxDefense.GetCurrentValue());
	}
	else if (Attribute == GetSpeedAttribute())
	{
		// Clamp Speed value between 0 and MaxSpeed
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxSpeed.GetCurrentValue());
	}
}

// Ensure proper replication of attributes over the network
void ULyraBattleArenaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, CharacterID, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Resource, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxResource, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Power, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxPower, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Defense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxDefense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Speed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxSpeed, COND_None, REPNOTIFY_Always);
}
