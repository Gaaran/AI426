// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426PlayerCharacter.h"
#include "Base/AI426GameState.h"
#include "Camera/CameraComponent.h"
#include <Kismet/KismetSystemLibrary.h>

void AAI426PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GS = GetWorld()->GetGameState<AAI426GameState>();
}

void AAI426PlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult HitResult;
	TArray<AActor*> IgnoreList;
	UKismetSystemLibrary::LineTraceSingle(GetWorld(), GetMesh()->GetComponentLocation(),
		GetMesh()->GetComponentLocation() + GetMesh()->GetComponentLocation().ForwardVector * TraceDistance, TraceTypeQuery1,
		true, IgnoreList, EDrawDebugTrace::Persistent, HitResult, true);
	if (HitResult.GetActor())
	{
		GS->DebugMessage(HitResult.GetActor()->GetName());
	}

}

void AAI426PlayerCharacter::GetInteractable()
{

}
