// Fill out your copyright notice in the Description page of Project Settings.


#include "AI426/ItemBase/APlaceable.h"

// Sets default values
AAPlaceable::AAPlaceable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	RootComponent = SceneComponent;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");
	StaticMesh->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AAPlaceable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPlaceable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

