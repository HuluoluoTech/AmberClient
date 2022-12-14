// Fill out your copyright notice in the Description page of Project Settings.


#include "AmberMeleeWeapon.h"
#include "Kismet/GameplayStatics.h"
#include "AmberMonster.h"

// Sets default values
AAmberMeleeWeapon::AAmberMeleeWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AttackDamage = 1;
	IsSwinging = false;
	Holder = nullptr;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMesh;

	ProxBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ProxBox"));
	ProxBox->OnComponentBeginOverlap.AddDynamic(this, &AAmberMeleeWeapon::Prox);
	ProxBox->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AAmberMeleeWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAmberMeleeWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAmberMeleeWeapon::Prox_Implementation(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp != OtherActor->GetRootComponent())
	{
		return;
	}

	AActor* HolderActor = Cast<AActor>(Holder);
	if (IsSwinging && OtherActor != HolderActor && !Hits.Contains(OtherActor))
	{
		OtherActor->TakeDamage(AttackDamage + Holder->BaseAttackDamage, FDamageEvent(), nullptr, this);
		Hits.Add(OtherActor);
	}
}

void AAmberMeleeWeapon::Swing()
{
	Hits.Empty();
	IsSwinging = true;
}

void AAmberMeleeWeapon::Rest()
{
	Hits.Empty();
	IsSwinging = false;
}



