// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmberActorBaseInteractable.h"
#include "AmberActorHealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API AAmberActorHealthPotion : public AAmberActorBaseInteractable
{
	GENERATED_BODY()
	
public:
	AAmberActorHealthPotion();
	virtual EAmberItemName GetModuleName() { return EAmberItemName::E_Name_HealthPotion; }

};
