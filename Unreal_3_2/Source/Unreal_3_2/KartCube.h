// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KartCube.generated.h"

UCLASS()
class UNREAL_3_2_API AKartCube : public APawn   // ← 여기만 바꾸면 됨!
{
    GENERATED_BODY()
public:
    AKartCube();
protected:
    virtual void BeginPlay() override;
public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* CubeMesh;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed = 1000.0f;

private:
    void MoveForward(float Value);
};
