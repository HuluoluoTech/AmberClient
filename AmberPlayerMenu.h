// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmberCharacter.h"
#include "Components/Button.h"
#include "AmberItemInfo.h"
#include "Components/UniformGridPanel.h"
#include "Components/Image.h"

#include "AmberPlayerMenu.generated.h"

/**
 * 
 */
UCLASS()
class AMBER_API UAmberPlayerMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UAmberPlayerMenu(const FObjectInitializer& ObjectInitializer);

public:
	UFUNCTION(BlueprintCallable)
		void OnItemDrop();

	UFUNCTION(BlueprintCallable)
		void OnItemUse();

	UFUNCTION(BlueprintCallable)
		void BuildInventory();
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAmberCharacter* PlayerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UUniformGridPanel* InventoryPanel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonUse;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UButton* ButtonDrop;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UImage* ItemImagePreview;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAmberItemInfo ItemInfo;
};
