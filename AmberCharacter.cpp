// Copyright Epic Games, Inc. All Rights Reserved.

#include "AmberCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "AmberPlayerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "AmberPlayerMenu.h"

//////////////////////////////////////////////////////////////////////////
// AAmberCharacter

AAmberCharacter::AAmberCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AAmberCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AAmberCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AAmberCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AAmberCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AAmberCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AAmberCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AAmberCharacter::TouchStopped);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AAmberCharacter::PickupItem);

}

void AAmberCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AAmberCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AAmberCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AAmberCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AAmberCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AAmberCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AAmberCharacter::UseItem(FAmberItemInfo ItemInfo)
{

}

void AAmberCharacter::ToggleMenu(UUserWidget* UserWidget)
{
	UE_LOG(LogTemp, Warning, TEXT("Toggle Menu."));

	MenuStatus = (UserWidget == nullptr || MenuStatus == EMenuStatus::E_Menu_Open) ? EMenuStatus::E_Menu_Close : EMenuStatus::E_Menu_Open;
}

void AAmberCharacter::PickupItem()
{
	PickupIMPL();
}

void AAmberCharacter::PickupIMPL()
{
	// 从 InteractInRange 中pick
	const int Num = InteractInRange.Num();
	//if (Num < 1) return;
	UE_LOG(LogTemp, Warning, TEXT("\n\nInteractInRange Num: %d"), Num);
	UE_LOG(LogTemp, Warning, TEXT("Inventory Num: %d"), Inventory.Num());

	TArray<FAmberItemInfo> TempInventory;
	for (int Index = 0; Index < Num; Index++) {
		AAmberActorBaseInteractable* Actor = InteractInRange[Index];

		// 先检查是否已有该物品
		FAmberItemInfo* Info = Actor->ItemInfo;
		UE_LOG(LogTemp, Warning, TEXT("Info:"));

		Info->DumpItemInfo();

		bool bIsInInventory = false;
		for (int IndexInner = 0; IndexInner < Inventory.Num(); IndexInner++)
		{
			FAmberItemInfo Item = Inventory[IndexInner];
			UE_LOG(LogTemp, Warning, TEXT("Item:"));

			Item.DumpItemInfo();

			// 是否是同意一类型物品
			if (Item.ItemClass == Info->ItemClass)
			{
				bIsInInventory = true;

				// 是否还有多余空间
				if (Item.CurrentStack < Item.MaxStack)
				{
					// 更新Index
					//Info->ItemIndex = Index;
					Item.CurrentStack += 1;

					Inventory[IndexInner] = Item;
				}
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("bIsInInventory = %d"), bIsInInventory);

		// New Item
		if (bIsInInventory == false)
		{
			Inventory.Add(*Info);
		}

		Actor->Destroy();
	}

	UE_LOG(LogTemp, Warning, TEXT("After Add this Item, Inventory Num: %d"), Inventory.Num());
}

void AAmberCharacter::OnBeginOverlapL(class AActor* OtherActor)
{
	if (OtherActor->Implements<UInteractable>()) {
		UE_LOG(LogTemp, Warning, TEXT("OnOverlapBegin"));

		InteractInRange.AddUnique(Cast<AAmberActorBaseInteractable>(OtherActor));

		const AAmberActorBaseInteractable* t = Cast<AAmberActorBaseInteractable>(OtherActor);
		const FString Name = GetItemNameFromEnum(t->ItemName);
		UE_LOG(LogTemp, Warning, TEXT("Overlap With : %s"), *Name);
		t->ItemInfo->DumpItemInfo();
		UE_LOG(LogTemp, Warning, TEXT("Overlap End..."));
	}
}

void AAmberCharacter::OnEndOverlapL(class AActor* OtherActor)
{
	if (OtherActor->Implements<UInteractable>()) {
		InteractInRange.Remove(Cast<AAmberActorBaseInteractable>(OtherActor));
		UE_LOG(LogTemp, Warning, TEXT("OnOverlapEnd"));


	}

}
