// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AmberPlayerStats.generated.h"

/**
 * 
 */
//UCLASS(BlueprintType)
//class AMBER_API UAmberPlayerStats : public UObject
//{
//	GENERATED_BODY()
//
//public:
//	UAmberPlayerStats();
//	~UAmberPlayerStats();
//
//public:
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//		FString Name;
//	UPROPERTY(EditAnywhere, BlueprintReadOnly)
//		int Level;
//};

USTRUCT(BlueprintType)
struct FAmberPlayerStats
{
	GENERATED_BODY()

		void Init();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int Level;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float CurrentHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float CurrentMana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MaxMana;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float CurrentXP;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float ToNextLevel;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Strengh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float Defense;
};

USTRUCT(BlueprintType)
struct FAmberPlayerGear
{
	GENERATED_BODY()

		void Init();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int SwordModifier;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int ShieldModifier;
};

USTRUCT(BlueprintType)
struct FAmberPlayerProp
{
	GENERATED_BODY()

	FAmberPlayerProp();
	~FAmberPlayerProp();

	const float GetCurrentHealthPercentage() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FAmberPlayerStats AmberPlayerStats;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FAmberPlayerGear AmberPlayerGear;
};
