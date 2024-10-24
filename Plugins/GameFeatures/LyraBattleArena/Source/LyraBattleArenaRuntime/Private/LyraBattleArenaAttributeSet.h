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
	// Resource (Mana, Energy, etc.)
	ATTRIBUTE_ACCESSORS(ThisClass, Resource);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxResource);

	// Power (Attack Power / Ability Power)
	ATTRIBUTE_ACCESSORS(ThisClass, Power);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxPower);

	// Defense (Armor / Magic Resistance)
	ATTRIBUTE_ACCESSORS(ThisClass, Defense);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxDefense);

	// Speed (Movement and Attack Speed)
	ATTRIBUTE_ACCESSORS(ThisClass, Speed);
	ATTRIBUTE_ACCESSORS(ThisClass, MaxSpeed);

protected:
	// Replication functions for each attribute (to notify clients of changes)

	UFUNCTION()
	void OnRep_CharacterID(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_Resource(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxResource(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Power(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxPower(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Defense(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxDefense(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
	void OnRep_MaxSpeed(const FGameplayAttributeData& OldValue);

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

private:
	// Attribute Data for each category


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CharacterID, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData CharacterID;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resource, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Resource;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxResource, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxResource;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Power, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Power;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxPower, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxPower;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Defense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxDefense, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxDefense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Speed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxSpeed, Category = "Attributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxSpeed;
};
