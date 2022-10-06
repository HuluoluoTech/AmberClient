// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AmberItemName.h"
#include "Engine/DataTable.h"
#include "Interactable.h"


#include "AmberActorBaseInteractable.generated.h"

struct FAmberItemInfo;
UCLASS()
class AMBER_API AAmberActorBaseInteractable : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmberActorBaseInteractable();
	FAmberItemInfo* LoadDataTable(EAmberItemName ItemName);
	virtual EAmberItemName GetModuleName() { return EAmberItemName::E_Name_MAX; }
	//virtual void OnConstruction(const FTransform& Transform) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	FAmberItemInfo* ItemInfo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EAmberItemName ItemName;

protected:
	class UDataTable* ItemInfoData;

public:

public:
	void InteractWith();
};
