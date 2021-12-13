// Fill out your copyright notice in the Description page of Project Settings.


#include "TPPCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ATPPCharacter::ATPPCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoomArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera boom"));
	BoomArm->SetupAttachment(RootComponent);
	BoomArm->TargetArmLength = 300.f;
	BoomArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(BoomArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	
	GetCharacterMovement()->bOrientRotationToMovement = true; 
	GetCharacterMovement()->RotationRate = FRotator(0, 540, 0);

	TurnRate = 45;
	LookRate = 45;

}

// Called when the game starts or when spawned
void ATPPCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATPPCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATPPCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATPPCharacter::MoveRight);
	PlayerInputComponent->BindAxis("TurnRate", this, &ATPPCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ATPPCharacter::LookUpAtRate);
	InputComponent->BindAction("Jump", IE_Pressed, this, &ATPPCharacter::StartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &ATPPCharacter::StopJump);
}

void ATPPCharacter::MoveForward(float Value)
{
	if (Controller != NULL && Value != 0.0)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, Rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, Value);
	}
}

void ATPPCharacter::MoveRight(float Value)
{
	if (Controller != NULL && Value != 0.0)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator Yaw(0, Rotation.Yaw, 0);
		const FVector direction = FRotationMatrix(Yaw).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, Value);
	}
}

void ATPPCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * GetWorld()->GetDeltaSeconds() * TurnRate);
}

void ATPPCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * GetWorld()->GetDeltaSeconds() * TurnRate);
}

// Called every frame
void ATPPCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATPPCharacter::StartJump()
{
	bPressedJump = true;
}

void ATPPCharacter::StopJump()
{
	bPressedJump = false;
}


