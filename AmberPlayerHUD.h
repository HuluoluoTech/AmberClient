// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmberCharacter.h"

#include "AmberPlayerHUD.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API UAmberPlayerHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UAmberPlayerHUD(const FObjectInitializer& ObjectInitializer);

public:
	void SetPlayerRef(AAmberCharacter* AmberPlayer);

	float GetHealthPercentage();
	void UpdateLevelText();
	void UpdateXPPercentage();

public:
	AAmberCharacter* PlayerRef;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* ManaBar;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* XPBar;
};
