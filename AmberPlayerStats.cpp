// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberPlayerStats.h"

void FAmberPlayerStats::Init()
{
	Name = "Amber";
	Level = 1;
	CurrentHealth = 50.0f;
	MaxHealth = 100.0f;

	CurrentMana = 50.0f;
	MaxMana = 100.0f;

	CurrentXP = 1;
	ToNextLevel = 100;
}

void FAmberPlayerGear::Init()
{
	SwordModifier = 100;
	ShieldModifier = 100;
}

FAmberPlayerProp::FAmberPlayerProp()
{
	AmberPlayerStats.Init();
	AmberPlayerGear.Init();
}

FAmberPlayerProp::~FAmberPlayerProp()
{
}

const float FAmberPlayerProp::GetCurrentHealthPercentage() const
{
	//if (MaxHealth != 0.0) {
	//	float Percentage = CurrentHealth / MaxHealth;
	//	return Percentage;
	//}

	return 1.0;
}
