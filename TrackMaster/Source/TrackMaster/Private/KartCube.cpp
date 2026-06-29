// Fill out your copyright notice in the Description page of Project Settings.


#include "KartCube.h"

// Sets default values
AKartCube::AKartCube()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKartCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKartCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AKartCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

