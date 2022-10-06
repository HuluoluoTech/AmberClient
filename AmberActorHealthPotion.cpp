// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberActorHealthPotion.h"

AAmberActorHealthPotion::AAmberActorHealthPotion() : Super()
{
	ItemName = EAmberItemName::E_Name_HealthPotion;

	UE_LOG(LogTemp, Warning, TEXT("AAmberActorHealthPotion constructor Called."));

	ItemInfo = LoadDataTable(GetModuleName());
}