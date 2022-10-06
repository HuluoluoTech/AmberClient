// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberActorBaseInteractable.h"
#include "AmberItemInfo.h"

// Sets default values
AAmberActorBaseInteractable::AAmberActorBaseInteractable()
{
	UE_LOG(LogTemp, Warning, TEXT("AAmberActorBaseInteractable constructor Called."));

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//LoadDataTable(ItemName);
}

//void AAmberActorBaseInteractable::OnConstruction(const FTransform& Transform)
//{
//	UE_LOG(LogTemp, Warning, TEXT("AAmberActorBaseInteractable::OnConstruction"));
//
//	LoadDataTable(EAmberItemName::E_Name_HealthPotion);
//}

FAmberItemInfo* AAmberActorBaseInteractable::LoadDataTable(EAmberItemName ModulName)
{
	// Load DataTable
	static ConstructorHelpers::FObjectFinder<UDataTable> ItemInfoDataTable(TEXT("DataTable'/Game/ThirdPerson/Blueprints/InteractionSystem/DT_AmberItemInfo.DT_AmberItemInfo'"));
	if (ItemInfoDataTable.Succeeded())
	{
		ItemInfoData = ItemInfoDataTable.Object;
	}
	static const FString ContextString(TEXT("Get ItemInfo By ItemName"));
	const FName RowName = FName(*GetItemNameFromEnum(ItemName));
	FAmberItemInfo* RowOfItemInfo = ItemInfoData->FindRow<FAmberItemInfo>(RowName, ContextString, true);

	RowOfItemInfo->DumpItemInfo();

	return RowOfItemInfo;
}

// Called when the game starts or when spawned
void AAmberActorBaseInteractable::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AAmberActorBaseInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmberActorBaseInteractable::InteractWith()
{
}


