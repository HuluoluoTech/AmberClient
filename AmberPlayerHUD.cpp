// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberPlayerHUD.h"
#include "Components/ProgressBar.h"

UAmberPlayerHUD::UAmberPlayerHUD(const FObjectInitializer& ObjectInitializer): UUserWidget(ObjectInitializer)
{}

void UAmberPlayerHUD::SetPlayerRef(AAmberCharacter* AmberPlayer)
{
	PlayerRef = AmberPlayer;

	// Progress Bindings
	//if (HealthBar) {
	//	HealthBar->PercentDelegate.BindUFunction(this, "GetHealthPercentage");
	//	HealthBar->SynchronizeProperties();
	//}
}

void UAmberPlayerHUD::UpdateLevelText()
{

}

float UAmberPlayerHUD::GetHealthPercentage()
{
	//const float HealthPercentage = PlayerRef->AmberPlayerProps.GetCurrentHealthPercentage();
	//return HealthPercentage;

	return 0.3f;
}

void UAmberPlayerHUD::UpdateXPPercentage()
{

}