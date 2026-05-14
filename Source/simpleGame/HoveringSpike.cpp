// Fill out your copyright notice in the Description page of Project Settings.

#include "HoveringSpike.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

// Sets default values
AHoveringSpike::AHoveringSpike()
{
	// Set this actor to call Tick() every frame.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AHoveringSpike::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AHoveringSpike::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator SpikeRotation = FRotator(0.f, 100.f * DeltaTime, 0.f);
	AddActorLocalRotation(SpikeRotation);
}

void AHoveringSpike::PlayerHitSpike(AActor* HitActor)
{
	if (HitActor)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.f,
			FColor::Red,
			TEXT("Spike Damage Dealt!")
		);

		ACharacter* PlayerCharacter = Cast<ACharacter>(HitActor);

		if (PlayerCharacter)
		{
			// Direction from spike to player
			FVector KnockbackDirection =
				PlayerCharacter->GetActorLocation() - GetActorLocation();

			KnockbackDirection.Normalize();

			// Add upward force
			KnockbackDirection.Z = 0.5f;

			float KnockbackForce = 500.0f;
			FVector LaunchVelocity =
				KnockbackDirection * KnockbackForce;

			PlayerCharacter->LaunchCharacter(
				LaunchVelocity,
				true,
				true
			);

			GEngine->AddOnScreenDebugMessage(
				-1,
				5.f,
				FColor::Red,
				TEXT("Knockback Applied!")
			);
		}
	}
}