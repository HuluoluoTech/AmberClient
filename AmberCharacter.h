// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AmberPlayerStats.h"
#include "AmberItemInfo.h"
//#include "AmberInventoryIcon.h"
//#include "AmberPlayerHUD.h"
#include "Interactable.h"
#include "AmberActorBaseInteractable.h"


#include "AmberCharacter.generated.h"

class UAmberInventoryIcon;
class UAmberPlayerHUD;
class UAmberPlayerMenu;
struct FAmberItemInfo;

UENUM()
enum class EMenuStatus : uint8
{
	E_Menu_Open = 0,
	E_Menu_Close,
};

UCLASS(config=Game)
class AAmberCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	AAmberCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	//////////////// Impl 2022-10-01
	// Author : zTgx
public:
	/**
	EditAnywhere -> 可以在 Detail 中显示编辑
	BlueprintReadOnly -> 可以在蓝图中获取到
	*/
	UPROPERTY(EditAnywhere, BlueprintReadOnly) //, Category = AmberPlayerProps
		FAmberPlayerProp AmberPlayerProp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FAmberItemInfo ItemSelected;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FAmberItemInfo> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int InventorySize{25};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UAmberPlayerHUD* AmberPlayerHUD;

	//
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UAmberPlayerMenu* AmberMenu;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		EMenuStatus MenuStatus{ EMenuStatus::E_Menu_Close };

	//UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AAmberActorBaseInteractable*> InteractInRange;

public:
	UFUNCTION(BlueprintCallable)
		void UseItem(FAmberItemInfo ItemInfo);
	UFUNCTION(BlueprintCallable)
		void ToggleMenu(UUserWidget* UserWidget);

	UFUNCTION(BlueprintCallable)
		void PickupItem();

	// 下面两个方法从Blueprint里面进行回调
	UFUNCTION(BlueprintCallable)
		void OnBeginOverlapL(class AActor* OtherActor);
	UFUNCTION(BlueprintCallable)
		void OnEndOverlapL(class AActor* OtherActor);

	void PickupIMPL();

};

