// Fill out your copyright notice in the Description page of Project Settings.


#include "KartCube.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h" // 키 입력 처리를 위해 추가!
#include "Engine/World.h"              // GetWorld()를 사용하기 위해 추가!

AKartCube::AKartCube()
{
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;
}

void AKartCube::BeginPlay()
{
	Super::BeginPlay();
}

void AKartCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKartCube::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AKartCube::MoveForward);
}

void AKartCube::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		FVector MoveDirection = GetActorForwardVector() * Value * MoveSpeed * GetWorld()->GetDeltaSeconds();
		AddActorLocalOffset(MoveDirection, true);
	}
}