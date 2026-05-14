#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObstacleTrapC.generated.h"

UCLASS()
class SIMPLEGAME_API AObstacleTrapC : public AActor
{
	GENERATED_BODY()

public:
	AObstacleTrapC();

	UPROPERTY(EditAnywhere)
	float DamageAmount = 20.f;

	UFUNCTION(BlueprintCallable, Category = "Trap")
	void PlayerHit(AActor* HitActor);

protected:
	virtual void BeginPlay() override;

private:
	TArray<FString> Messages;
	int32 HitCount = 0;
};
