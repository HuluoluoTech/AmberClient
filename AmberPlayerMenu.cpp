// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberPlayerMenu.h"
#include "Components/ProgressBar.h"
#include "AmberInventoryIcon.h"

UAmberPlayerMenu::UAmberPlayerMenu(const FObjectInitializer& ObjectInitializer): UUserWidget(ObjectInitializer)
{
	BuildInventory();
}

void UAmberPlayerMenu::SetPlayerRef(AAmberCharacter* AmberPlayer)
{
	PlayerRef = AmberPlayer;

	if (ButtonUse)
	{
		ButtonUse->OnClicked.AddDynamic(this, &UAmberPlayerMenu::OnItemUse);
	}

	if (ItemImagePreview)
	{
	}
}

void UAmberPlayerMenu::OnItemUse()
{
	PlayerRef->UseItem(ItemInfo);
}

void UAmberPlayerMenu::OnItemDrop()
{
	PlayerRef->UseItem(PlayerRef->ItemSelected);
}

void UAmberPlayerMenu::BuildInventory()
{
	for (int Row = 0; Row < 5; Row++)
	{
		for (int Column = 0; Column < Row; Column++)
		{
			int Index = Row * 5 + Column;

			UAmberInventoryIcon* AmberInventoryIcon = CreateWidget<UAmberInventoryIcon>(this, UAmberInventoryIcon::StaticClass());
			/*if (PlayerRef->Inventory.Num() >= Index) {
				AmberInventoryIcon->SetItemInfo(PlayerRef->Inventory[Index]);
			}*/
			InventoryPanel->AddChildToUniformGrid(AmberInventoryIcon, Row, Column);
		}
	}
}