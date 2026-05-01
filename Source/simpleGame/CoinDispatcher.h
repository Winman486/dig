// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinDispatcher.generated.h"

UCLASS()
class SIMPLEGAME_API ACoinDispatcher : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoinDispatcher();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BluePrintCallable)
	FVector GetComplexCoinLocation();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)

	float DistanceFromCenter = 1000;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, category = "Debug")
	bool ShowDebugPoints = false;


};
