// Fill out your copyright notice in the Description page of Project Settings.


#include "SpikeBallMovement.h"
#include "GameFramework/Character.h"
#include "Engine/Engine.h"

// Sets default values
ASpikeBallMovement::ASpikeBallMovement()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpikeBallMovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpikeBallMovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator SpikeRototation = FRotator(0.f, 100.f * DeltaTime, 0.f);
	AddActorLocalRotation(SpikeRototation);
}

void ASpikeBallMovement::PlayerHitSpike(AActor* HitActor) {
	if (HitActor) {
		// Log to the screen so you know it worked
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Spike Damage Dealt via C++!"));
	}
    if (HitActor) {
        ACharacter* PlayerCharacter = Cast<ACharacter>(HitActor);
        if (PlayerCharacter) {
            // 1. Calculate direction: From Spike toward Player
            FVector KnockbackDirection = PlayerCharacter->GetActorLocation() - GetActorLocation();
            KnockbackDirection.Normalize();

            // 2. Add an upward 'jump' element (Z-axis)
            KnockbackDirection.Z = 0.5f;

            // 3. Scale by force (e.g., 500.0f)
            float KnockbackForce = 500.0f;
            FVector LaunchVelocity = KnockbackDirection * KnockbackForce;

            // 4. Launch the character
            // bXYOverride and bZOverride set to true will replace current velocity
            PlayerCharacter->LaunchCharacter(LaunchVelocity, true, true);

            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Knockback Applied!"));
        }
    }
}