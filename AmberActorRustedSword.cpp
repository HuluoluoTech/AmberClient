// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberActorRustedSword.h"

AAmberActorRustedSword::AAmberActorRustedSword() : Super()
{
	ItemName = EAmberItemName::E_Name_RustedSword;

	UE_LOG(LogTemp, Warning, TEXT("AAmberActorRustedSword constructor Called."));

	ItemInfo = LoadDataTable(GetModuleName());
}