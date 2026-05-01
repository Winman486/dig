// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinDispatcher.h"

// Sets default values
ACoinDispatcher::ACoinDispatcher()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoinDispatcher::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinDispatcher::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


FVector ACoinDispatcher::GetComplexCoinLocation() {

	FVector Result;

	FRandomStream rand;
	rand.GenerateNewSeed();

	FVector RandomUnitVector = rand.GetUnitVector();

	if (ShowDebugPoints) {
		UE_LOG(
			LogTemp,
			Warning,
			TEXT("The location of the point is: %s"),
			*RandomUnitVector.ToString()
		);
	}

	FVector RandomLocationAtDistance = RandomUnitVector * DistanceFromCenter;

	Result = GetActorLocation() + RandomLocationAtDistance;
	Result.Z = GetActorLocation().Z;

	if(ShowDebugPoints) {
		DrawDebugPoint(
			GetWorld(),
			Result,
			10,
			FColor::Red,
			true);
	}

	return Result;
}
