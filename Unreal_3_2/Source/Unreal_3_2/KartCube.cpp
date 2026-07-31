// Fill out your copyright notice in the Description page of Project Settings.


#include "KartCube.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"

AKartCube::AKartCube()
{
    PrimaryActorTick.bCanEverTick = true;

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    AutoPossessPlayer = EAutoReceiveInput::Player0; // ¡ç ÇÊ¼ö!
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
        FVector Dir = GetActorForwardVector() * Value * MoveSpeed * GetWorld()->GetDeltaSeconds();
        AddActorLocalOffset(Dir, true);
    }
}