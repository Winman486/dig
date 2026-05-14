// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikeBallC.h"

// Sets default values
ASpikeBallC::ASpikeBallC()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpikeBallC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpikeBallC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator SpikeRototation = FRotator(0.f, 100.f * DeltaTime, 0.f);
	AddActorLocalRotation(SpikeRototation);

}
void ASpikeBallC::PlayerHitSpike(AActor* HitActor) {
	if (HitActor) {
		// Log to the screen so you know it worked
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spike Damage Dealt via C++!"));
	}
}