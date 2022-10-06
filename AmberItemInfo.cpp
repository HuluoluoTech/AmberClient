// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberItemInfo.h"

FAmberItemInfo::FAmberItemInfo()
{
}

FAmberItemInfo::~FAmberItemInfo()
{
}

void FAmberItemInfo::DumpItemInfo()
{
	UE_LOG(LogTemp, Warning, TEXT("\n#AmberItemInfo"));
	UE_LOG(LogTemp, Warning, TEXT("ItemName		: %s"), *ItemName);
	UE_LOG(LogTemp, Warning, TEXT("CurrentStack	: %d"), CurrentStack);
	UE_LOG(LogTemp, Warning, TEXT("MaxStack		: %d"), MaxStack);
	UE_LOG(LogTemp, Warning, TEXT("ItemIndex	: %d"), ItemIndex);
	UE_LOG(LogTemp, Warning, TEXT("ItemType		: %s"), *GetItemTypeFromEnum(ItemType));
	UE_LOG(LogTemp, Warning, TEXT("Potency		: %f"), Potency);
	UE_LOG(LogTemp, Warning, TEXT("Bid			: %d"), Bid);
	UE_LOG(LogTemp, Warning, TEXT("Sell			: %d"), Sell);
}

