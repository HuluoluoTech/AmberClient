// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "AmberItemType.h"
#include "Engine/DataTable.h"
#include "AmberActorBaseInteractable.h"

#include "AmberItemInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FAmberItemInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	FAmberItemInfo();
	~FAmberItemInfo();

public:
	void DumpItemInfo();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		TSubclassOf<class AAmberActorBaseInteractable> ItemClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		FString ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UTexture2D* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		int CurrentStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		int MaxStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		int ItemIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		EAmberItemType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		float Potency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		int Bid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		int Sell;
};
