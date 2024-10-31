#include "LyraBattleArenaAttributeSet.h"
#include "Net/UnrealNetwork.h"

// Constructor
ULyraBattleArenaAttributeSet::ULyraBattleArenaAttributeSet()
	:CharacterID(0.0f)
	,CharacterLevel(0.0f)
	,MaxXP(100.0f)
	,XP(0.0f)
	,Resource(0.0f)
	,MaxResource(0.0f)
	,Power(0.0f)
	,ActionSpeed(0.0f)
	,Defense(0.0f)
	,MovementSpeed(0.0f)
	,PassiveCooldown(0.0f)
	,BasicAttackCooldown(0.0f)
	,Ability1Cooldown(0.0f)
	,Ability2Cooldown(0.0f)
	,Ability3Cooldown(0.0f)

{
}

// Override for PreAttributeBaseChange
void ULyraBattleArenaAttributeSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	// If XP attribute is changing, process it through AddXP
	if (Attribute == GetXPAttribute())
	{
		// Call AddXP for level-up checks, etc.
		const_cast<ULyraBattleArenaAttributeSet*>(this)->AddXP(NewValue);
	}
	else
	{
		// Clamp non-XP attributes as usual
		ClampAttribute(Attribute, NewValue);
	}
}

// Override for PreAttributeChange
void ULyraBattleArenaAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	// If XP attribute is changing, process it through AddXP
	if (Attribute == GetXPAttribute())
	{
		AddXP(NewValue);
	}
	else
	{
		// Clamp non-XP attributes as usual
		ClampAttribute(Attribute, NewValue);
	}
}


// Replication functions
void ULyraBattleArenaAttributeSet::OnRep_CharacterID(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, CharacterID, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_CharacterLevel(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, CharacterLevel, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_MaxXP(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MaxXP, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_XP(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, XP, OldValue);
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
void ULyraBattleArenaAttributeSet::OnRep_ActionSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, ActionSpeed, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_Defense(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Defense, OldValue);
}
void ULyraBattleArenaAttributeSet::OnRep_MovementSpeed(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, MovementSpeed, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_PassiveCooldown(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, PassiveCooldown, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_BasicAttackCooldown(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, BasicAttackCooldown, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Ability1Cooldown(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Ability1Cooldown, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Ability2Cooldown(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Ability2Cooldown, OldValue);
}

void ULyraBattleArenaAttributeSet::OnRep_Ability3Cooldown(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(ULyraBattleArenaAttributeSet, Ability3Cooldown, OldValue);
}

void ULyraBattleArenaAttributeSet::ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const
{
	
	if (Attribute == GetResourceAttribute())
	{
		// Clamp Resource value between 0 and MaxResource
		NewValue = FMath::Clamp(NewValue, 0.0f, MaxResource.GetCurrentValue());
	}


}

// Ensure proper replication of attributes over the network
void ULyraBattleArenaAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, CharacterID, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, CharacterLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxXP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, XP, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Resource, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MaxResource, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Power, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, ActionSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Defense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, MovementSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, PassiveCooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, BasicAttackCooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Ability1Cooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Ability2Cooldown, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(ULyraBattleArenaAttributeSet, Ability3Cooldown, COND_None, REPNOTIFY_Always);

}

void ULyraBattleArenaAttributeSet::AddXP(float NewXPValue)
{
	if (NewXPValue < 0.0f) return;

	float CurrentXP = XP.GetCurrentValue();
	float XPToAdd = NewXPValue - CurrentXP;  // Calculate the change in XP

	// If no actual XP increase, skip
	if (XPToAdd <= 0.0f) return;

	// Set new XP value to apply through level-up logic
	float UpdatedXP = CurrentXP + XPToAdd;

	// Level-up loop to handle excess XP
	while (UpdatedXP >= MaxXP.GetCurrentValue())
	{
		UpdatedXP -= MaxXP.GetCurrentValue();

		// Level up the character
		CharacterLevel.SetCurrentValue(CharacterLevel.GetCurrentValue() + 1.0f);

		// Increase MaxXP by 10% for the new level
		float NewMaxXP = MaxXP.GetCurrentValue() * 1.1f;
		MaxXP.SetCurrentValue(NewMaxXP);

		// Ensure MaxXP and CharacterLevel replication
		if (UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent())
		{
			ASC->SetNumericAttributeBase(GetCharacterLevelAttribute(), CharacterLevel.GetCurrentValue());
			ASC->SetNumericAttributeBase(GetMaxXPAttribute(), NewMaxXP);
		}
	}

	// Apply remaining XP after level-ups
	XP.SetCurrentValue(UpdatedXP);

	// Ensure XP replication
	if (UAbilitySystemComponent* ASC = GetOwningAbilitySystemComponent())
	{
		ASC->SetNumericAttributeBase(GetXPAttribute(), UpdatedXP);
	}
}
