// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberPlayerMenu.h"
#include "Components/ProgressBar.h"
#include "AmberInventoryIcon.h"

UAmberPlayerMenu::UAmberPlayerMenu(const FObjectInitializer& ObjectInitializer): UUserWidget(ObjectInitializer)
{
}

void UAmberPlayerMenu::OnItemUse()
{
	PlayerRef->UseItem(PlayerRef->ItemSelected);
}

void UAmberPlayerMenu::OnItemDrop()
{
	PlayerRef->UseItem(PlayerRef->ItemSelected);
}

void UAmberPlayerMenu::BuildInventory()
{
	//for (int Index = 0; Index < 25; Index++)
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("Index = %d"), Index);

	//	UAmberInventoryIcon* AmberInventoryIcon = CreateWidget<UAmberInventoryIcon>(this, UAmberInventoryIcon::StaticClass());
	//	if (PlayerRef)
	//	{
	//		int Num = PlayerRef->Inventory.Num();
	//		//UE_LOG(LogTemp, Warning, TEXT("Num = %d"), Num);

	//		if (Num > Index)
	//		{

	//			AmberInventoryIcon->ItemInfo = PlayerRef->Inventory[Index];

	//			UE_LOG(LogTemp, Warning, TEXT("Add One %s"), *AmberInventoryIcon->ItemInfo.ItemName);

	//		}
	//	}

	//	UE_LOG(LogTemp, Warning, TEXT("InventoryPanel = %d"), InventoryPanel == nullptr);

	//	InventoryPanel->AddChildToUniformGrid(AmberInventoryIcon, Index / 25, Index % 25);

	//}
}