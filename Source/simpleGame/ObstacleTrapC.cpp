#include "ObstacleTrapC.h"
#include "Kismet/GameplayStatics.h"

AObstacleTrapC::AObstacleTrapC()
{
	PrimaryActorTick.bCanEverTick = false;

	Messages = { TEXT("Ouch!"), TEXT("Too slow!"), TEXT("Watch out!"), TEXT("Nice try!") };
}

void AObstacleTrapC::BeginPlay()
{
	Super::BeginPlay();
}

void AObstacleTrapC::PlayerHit(AActor* HitActor)
{
	if (HitActor)
	{
		for (int32 i = 0; i < Messages.Num(); i++)
		{
			if (i == HitCount % Messages.Num())
			{
				GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Messages[i]);
				break;
			}
		}

		HitCount++;
		UGameplayStatics::ApplyDamage(HitActor, DamageAmount, nullptr, this, nullptr);
	}
}
