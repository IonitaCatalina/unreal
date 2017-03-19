// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingBalls.h"
#include "FloatingBall.h"
#include "MovingBallsCharacter.h"


// Sets default values
AFloatingBall::AFloatingBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	RootComponent = Root;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	BallMesh->AttachTo(RootComponent);

	rotationSpeed = 0.0f;
	radius = 0.0f;
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

	// Get character
	ACharacter* myCharacter = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	// Get ball
	FVector actorLocation = GetActorLocation();
	actorLocation.X = (actorLocation.X + FMath::Cos(runningTime + DeltaTime) * radius);
	actorLocation.Y = (actorLocation.Y + FMath::Sin(runningTime + DeltaTime) * radius);
	actorLocation.Z = (actorLocation.Y + FMath::Sin(runningTime + DeltaTime) * radius);

	runningTime += DeltaTime;

	SetActorLocation(actorLocation);

}

