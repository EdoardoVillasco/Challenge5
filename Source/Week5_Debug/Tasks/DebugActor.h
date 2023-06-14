#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DebugActor.generated.h"

class URotatingMovementComponent;

UCLASS()
class WEEK5_DEBUG_API ADebugActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADebugActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USceneComponent* DefaultRootComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		URotatingMovementComponent* RotatingComponent;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Debug")
		float TraceDistance = 1000.0f;

};
