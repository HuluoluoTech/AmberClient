// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM()
enum class EAmberItemName
{
	E_Name_HealthPotion,
	E_Name_ManaPotion,
	E_Name_RustedSword,
	E_Name_IronSword,
	E_Name_WoodShield,
	E_Name_IronShield,
	E_Name_MAX UMETA(Hidden),
};

const static FString GetItemNameFromEnum(const EAmberItemName ItemName)
{
	switch (ItemName)
	{
	case EAmberItemName::E_Name_HealthPotion:
		return "E_Name_HealthPotion";
	case EAmberItemName::E_Name_ManaPotion:
		return "E_Name_ManaPotion";
	case EAmberItemName::E_Name_RustedSword:
		return "E_Name_RustedSword";
	case EAmberItemName::E_Name_IronSword:
		return "E_Name_IronSword";
	case EAmberItemName::E_Name_WoodShield:
		return "E_Name_WoodShield";
	case EAmberItemName::E_Name_IronShield:
		return "E_Name_IronShield";
	default:
		return "E_Name_MAX";
	}
}
