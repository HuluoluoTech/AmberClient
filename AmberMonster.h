// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"

#include "AmberMonster.generated.h"

UCLASS()
class AMBER_API AAmberMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAmberMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// How fast he is
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		float HitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		int XP;

	// Loot
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		UClass* BPLoot;

	// The amount of damage attacks do
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		float BaseAttackDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		float AttackTimeout;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		float TimesSinceLastStrike;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		USceneComponent* SightSource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		USphereComponent* SightSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MonsterProps)
		USphereComponent* AttackRangeSphere;


public:
	bool IsInSightRange(float Distance)  { return Distance < SightSphere->GetScaledSphereRadius(); }
	bool IsInAttackRange(float Distance) { return Distance < AttackRangeSphere->GetScaledSphereRadius(); }
};
