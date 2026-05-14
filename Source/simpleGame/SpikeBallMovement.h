// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpikeBallMovement.generated.h"

UCLASS(Blueprintable, BlueprintType)
class SIMPLEGAME_API ASpikeBallMovement : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpikeBallMovement();
	UFUNCTION(BlueprintCallable, Category = "Hazard")
	void PlayerHitSpike(AActor* HitActor);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
