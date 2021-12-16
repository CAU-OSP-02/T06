// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingItem.h"

// Sets default values
AFloatingItem::AFloatingItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFloatingItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewRotation.Yaw += DeltaTime * 20.0f
	NewLocation.Z += DeltaHeight * 30.0f;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
	SetActorRotation(NewRotation);


}

