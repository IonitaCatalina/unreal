// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBalls.h"
#include "FloatingBall.h"


// Sets default values
AFloatingBall::AFloatingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->AttachTo(RootComponent);

	speedScale = 0.0f;
}

// Called when the game starts or when spawned
void AFloatingBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFloatingBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

