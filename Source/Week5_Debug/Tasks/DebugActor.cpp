// Fill out your copyright notice in the Description page of Project Settings.


#include "DebugActor.h"
#include "DrawDebugHelpers.h" 
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ADebugActor::ADebugActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADebugActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADebugActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
		
	FColor TraceColor = FColor::Blue;
	FHitResult Hit; 
	const FVector Start = GetActorLocation();
	const FVector End = ((GetActorForwardVector() * TraceDistance) + Start);  
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility);

	const TArray<AActor*> ActorsToIgnore;
	const bool bHit = UKismetSystemLibrary::LineTraceSingle(this, Start, End,
		UEngineTypes::ConvertToTraceType(ECC_Visibility),
		false, ActorsToIgnore, EDrawDebugTrace::ForDuration,
		Hit, true, FLinearColor::Yellow, FLinearColor::White, 0.1f); 
	
	if (bHit)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Trace Hit: %s"), *Hit.GetActor()->GetName()));
		
	}		
	
	DrawDebugLine(GetWorld(), Hit.TraceStart, End, TraceColor, false, 0, 0, 0);	
}


