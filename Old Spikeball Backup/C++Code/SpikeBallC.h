// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpikeBallC.generated.h"

UCLASS()
class CLASSPROJECT_API ASpikeBallC : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpikeBallC();
	UFUNCTION(BlueprintCallable, Category = "Hazard")
	void PlayerHitSpike(AActor* HitActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
