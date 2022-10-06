// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberActorWoodShield.h"

AAmberActorWoodShield::AAmberActorWoodShield(): Super()
{
	ItemName = EAmberItemName::E_Name_WoodShield;

	UE_LOG(LogTemp, Warning, TEXT("AAmberActorWoodShield constructor Called."));

	ItemInfo = LoadDataTable(GetModuleName());
}