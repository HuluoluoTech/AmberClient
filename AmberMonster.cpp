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
	SightSource->SetupAttachment(RootComponent);

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

	ACharacter* AmberCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (AmberCharacter == nullptr) return;

	// Player Location
	FVector PlayerLocation = AmberCharacter->GetActorLocation();
	 UE_LOG(LogTemp, Warning, TEXT("PlayerLocation = %s"), *PlayerLocation.ToString());

	FVector MonsterLocation = GetActorLocation();
	 UE_LOG(LogTemp, Warning, TEXT("MonsterLocation = %s"), *MonsterLocation.ToString());

	//// Player - Monster
	//// Direction
	 FVector ToPlayer = AmberCharacter->GetActorLocation() - GetActorLocation();
	 float DistanceToPlayer = ToPlayer.Size();
	 if (DistanceToPlayer > SightSphere->GetScaledSphereRadius())
	 {
		 // The Player is OutOfSight
		 return;
	 }

	 ToPlayer /= DistanceToPlayer; // nomalizes
	 

	// Move Monster to Player
	AddMovementInput(ToPlayer, Speed * DeltaTime);

	//FRotator ToPlayerRotation = ToPlayer.Rotation();
	//ToPlayerRotation.Pitch = 0;
	//SightSource->SetWorldRotation(ToPlayerRotation);

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

