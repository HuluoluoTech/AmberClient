// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmberCharacter.h"
#include "Components/Button.h"
#include "AmberItemInfo.h"


#include "AmberInventoryIcon.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API UAmberInventoryIcon : public UUserWidget
{
	GENERATED_BODY()
public:
	UAmberInventoryIcon(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
		void OnButtonClick();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FAmberItemInfo ItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UButton* ButtonIcon;
};
