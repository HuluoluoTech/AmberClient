// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmberActorBaseInteractable.h"
#include "AmberActorWoodShield.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API AAmberActorWoodShield : public AAmberActorBaseInteractable
{
	GENERATED_BODY()
	
public:
	AAmberActorWoodShield();
	virtual EAmberItemName GetModuleName() { return EAmberItemName::E_Name_WoodShield; }
};
