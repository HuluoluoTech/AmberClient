// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AmberActorBaseInteractable.h"
#include "AmberActorRustedSword.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API AAmberActorRustedSword : public AAmberActorBaseInteractable
{
	GENERATED_BODY()
	
public:
	AAmberActorRustedSword();
	virtual EAmberItemName GetModuleName() { return EAmberItemName::E_Name_RustedSword; }
};
