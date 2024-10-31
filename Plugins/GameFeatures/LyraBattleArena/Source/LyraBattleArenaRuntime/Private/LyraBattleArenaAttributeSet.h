#pragma once


#include "AbilitySystem/Attributes/LyraAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "LyraBattleArenaAttributeSet.generated.h"

/**
 * Attribute set for a battle arena type game
 */
UCLASS()
class ULyraBattleArenaAttributeSet : public ULyraAttributeSet
{
	GENERATED_BODY()

public:
	ULyraBattleArenaAttributeSet();

	//~UAttributeSet interface
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	//~End of UAttributeSet interface


	//Character ID
	ATTRIBUTE_ACCESSORS(ThisClass, CharacterID);
	//Character Level
	ATTRIBUTE_ACCESSORS(ThisClass, CharacterLevel);
	//Max XP
	ATTRIBUTE_ACCESSORS(ThisClass, MaxXP);
	//Curent XP
	ATTRIBUTE_ACCESSORS(ThisClass, XP);
	// Resource (Mana, Energy, etc.)
	ATTRIBUTE_ACCESSORS(ThisClass, Resource);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxResource);

	// Power (Attack Power / Ability Power)
	ATTRIBUTE_ACCESSORS(ThisClass, Power);

	//Casting Speed / Attack Speed
	ATTRIBUTE_ACCESSORS(ThisClass, ActionSpeed);

	// Defense (Armor / Magic Resistance)
	ATTRIBUTE_ACCESSORS(ThisClass, Defense);
	//Movement speed
	ATTRIBUTE_ACCESSORS(ThisClass, MovementSpeed);

	ATTRIBUTE_ACCESSORS(ThisClass, PassiveCooldown);

	ATTRIBUTE_ACCESSORS(ThisClass, BasicAttackCooldown);

	ATTRIBUTE_ACCESSORS(ThisClass, Ability1Cooldown);

	ATTRIBUTE_ACCESSORS(ThisClass, Ability2Cooldown);

	ATTRIBUTE_ACCESSORS(ThisClass, Ability3Cooldown);



protected:
	// Replication functions for each attribute (to notify clients of changes)

	UFUNCTION()
	void OnRep_CharacterID(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_CharacterLevel(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxXP(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_XP(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Resource(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxResource(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Power(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_ActionSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MovementSpeed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_PassiveCooldown(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_BasicAttackCooldown(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Ability1Cooldown(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Ability2Cooldown(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Ability3Cooldown(const FGameplayAttributeData& OldValue);

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

	void AddXP(float XPToAdd);

private:
	// Attribute Data for each category


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CharacterID, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData CharacterID;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CharacterLevel, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData CharacterLevel;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxXP, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxXP;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_XP, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData XP;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resource, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Resource;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxResource, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxResource;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Power, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Power;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_ActionSpeed, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData ActionSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Defense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MovementSpeed, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MovementSpeed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_PassiveCooldown, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData PassiveCooldown;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_BasicAttackCooldown, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData BasicAttackCooldown;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Ability1Cooldown, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Ability1Cooldown;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Ability2Cooldown, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Ability2Cooldown;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Ability3Cooldown, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Ability3Cooldown;

};
