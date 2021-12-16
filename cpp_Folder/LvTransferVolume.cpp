// Fill out your copyright notice in the Description page of Project Settings.


#include "LvTransferVolume.h"
#include "OpenLvPracCharacter.h"
#include <Engine/Classes/Components/BoxComponent.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ALvTransferVolume::ALvTransferVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TransferVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("TransferVolume")); 
	RootComponent = TransferVolume;
	TransferVolume->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
}

// Called when the game starts or when spawned
void ALvTransferVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALvTransferVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ALvTransferVolume::NotifyActorBeginOverlap(AActor* OtherActor) {
	AOpenLvPracCharacter* Character = Cast<AOpenLvPracCharacter>(OtherActor);
	if (Character)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(TransferLevelName));
	}
}
