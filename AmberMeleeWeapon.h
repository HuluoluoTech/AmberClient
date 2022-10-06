// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"


#include "AmberMeleeWeapon.generated.h"

class AAmberMonster;

UCLASS()
class AMBER_API AAmberMeleeWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAmberMeleeWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MeleeWeapon)
		float AttackDamage;

	TArray<AActor*> Hits;
	bool IsSwinging;
	AAmberMonster* Holder;

	UPROPERTY(VisibleDefaultsOnly, BlurprintReadOnly, Category = MeleeWeapon)
		UBoxComponent* ProxBox;

	UPROPERTY(VisibleDefaultsOnly, BlurprintReadOnly, Category = MeleeWeapon)
		UStaticMeshComponent* StaticMesh;

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void Prox(AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Swing();
	void Rest();
};
