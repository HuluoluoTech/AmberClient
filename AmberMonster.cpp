// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberMonster.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AAmberMonster::AAmberMonster()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 20;
	HitPoints = 20;
	XP = 0;
	BPLoot = nullptr;
	BaseAttackDamage = 1;
	AttackTimeout = 1.5f;
	TimesSinceLastStrike = 0;

	SightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SightSphere"));
	SightSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	AttackRangeSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AttackRangeSphere"));
	AttackRangeSphere->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AAmberMonster::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmberMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAmberMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

