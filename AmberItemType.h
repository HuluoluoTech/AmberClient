// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAmberItemType: uint8
{
	E_TYPE_HealthItem,
	E_TYPE_ManaItem,
	E_TYPE_SwordItem,
	E_TYPE_ShieldItem,
	E_TYPE_KeyItem,
	E_TYPE_ResourceItem,
	E_TYPE_MAX UMETA(Hidden),
};

const static FString GetItemTypeFromEnum(const EAmberItemType ItemName)
{
	switch (ItemName)
	{
	case EAmberItemType::E_TYPE_HealthItem:
		return "E_TYPE_HealthItem";
	case EAmberItemType::E_TYPE_ManaItem:
		return "E_TYPE_ManaItem";
	case EAmberItemType::E_TYPE_SwordItem:
		return "E_TYPE_SwordItem";
	case EAmberItemType::E_TYPE_ShieldItem:
		return "E_TYPE_ShieldItem";
	case EAmberItemType::E_TYPE_KeyItem:
		return "E_TYPE_KeyItem";
	case EAmberItemType::E_TYPE_ResourceItem:
		return "E_TYPE_ResourceItem";
	default:
		return "E_TYPE_MAX";
	}
}