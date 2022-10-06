// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberInventoryIcon.h"


UAmberInventoryIcon::UAmberInventoryIcon(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	if (ButtonIcon)
	{
		ButtonIcon->OnClicked.AddDynamic(this, &UAmberInventoryIcon::OnButtonClick);
	}
}

void UAmberInventoryIcon::SetPlayerRef(TWeakPtr<AAmberCharacter> AmberPlayer)
{
	PlayerRef = AmberPlayer;
}

void UAmberInventoryIcon::SetItemInfo(FAmberItemInfo AmberItemInfo)
{
	this->ItemInfo.ItemClass = AmberItemInfo.ItemClass;
}

void UAmberInventoryIcon::OnButtonClick()
{
	TSharedPtr<AAmberCharacter> SPlayerRef(PlayerRef.Pin());
	if (SPlayerRef->ItemSelected.ItemClass == ItemInfo.ItemClass) {
		SPlayerRef->UseItem(ItemInfo);
	}
	else {
		ItemInfo = SPlayerRef->ItemSelected;
	}
}