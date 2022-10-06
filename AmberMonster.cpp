// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberMonster.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"


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

	SightSource = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	RootComponent = SightSource;

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

	ACharacter* AmberPawn = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	if (AmberPawn == nullptr) return;

	// Player Location
	FVector PlayerLocation = AmberPawn->GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("PlayerLocation = %s"), *PlayerLocation.ToString());


	FVector MonsterLocation = GetActorLocation();
	UE_LOG(LogTemp, Warning, TEXT("MonsterLocation = %s"), *MonsterLocation.ToString());

	//// Player - Monster
	//// Direction
	//FVector ToPlayer = AmberPawn->GetActorLocation() - GetActorLocation();
	////ToPlayer.Normalize();

	//// Move Monster to Player
	//// AddMovementInput(ToPlayer, Speed * DeltaTime);

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(MonsterLocation, PlayerLocation);
	SetActorRotation(LookAtRotation);

	//GEngine->AddOnScreenDebugMessage(1, 20.f, FColor::Red, "Im Monster");


	DrawDebugLine(GetWorld(), MonsterLocation, PlayerLocation, FColor::Red);
}

// Called to bind functionality to input
void AAmberMonster::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

