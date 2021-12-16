// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LvTransferVolume.generated.h"

UCLASS()
class OPENLVPRAC_API ALvTransferVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALvTransferVolume();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		FString TransferLevelName;

	UPROPERTY()
		class UBoxComponent* TransferVolume;

};
