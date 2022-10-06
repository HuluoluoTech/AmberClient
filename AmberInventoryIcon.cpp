// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberInventoryIcon.h"
#include "Kismet/GameplayStatics.h"

UAmberInventoryIcon::UAmberInventoryIcon(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
	if (ButtonIcon)
	{
		ButtonIcon->OnClicked.AddDynamic(this, &UAmberInventoryIcon::OnButtonClick);
	}
}

void UAmberInventoryIcon::OnButtonClick()
{
	ACharacter* myPawn = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	AAmberCharacter* AmberCharacter = Cast<AAmberCharacter>(myPawn);

	// ˫����Icon��ֱ�ӵ���ʹ�÷���
	if (AmberCharacter->ItemSelected.ItemClass == ItemInfo.ItemClass) {
		AmberCharacter->UseItem(ItemInfo);
	}
	else {
		AmberCharacter->ItemSelected = ItemInfo;
	}
}