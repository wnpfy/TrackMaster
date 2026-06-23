// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KartPawn.generated.h"

UCLASS()
// ★ 중요: TRACKMASTER_API 라고 대문자와 _API까지 정확하게 적어주어야 에러가 안 납니다!
class TRACKMASTER_API AKartPawn : public APawn 
{
    GENERATED_BODY()

public:
    AKartPawn();

protected:
    virtual void BeginPlay() override;

public:	
    virtual void Tick(float DeltaTime) override;

    // --- 네모 외형 컴포넌트 ---
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Kart")
    class UStaticMeshComponent* MeshComponent;

    // --- 카트 속성 설정 ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float MAX_SPEED = 203.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float MAX_BOOSTER = 100.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float BASE_ACCEL = 80.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float TURN_SPEED = 120.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float TURN_DECEL_RATE = 15.0f;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    float NATURAL_DECEL = 25.0f;

    // --- 현재 상태 변수 ---
    UPROPERTY(BlueprintReadOnly, Category = "Kart")
    float currentSpeed = 0.0f;
    UPROPERTY(BlueprintReadOnly, Category = "Kart")
    float headingAngle = 0.0f;
    UPROPERTY(BlueprintReadOnly, Category = "Kart")
    float driftAngle = 0.0f;
    UPROPERTY(BlueprintReadOnly, Category = "Kart")
    float boosterGauge = 0.0f;
    UPROPERTY(BlueprintReadOnly, Category = "Kart")
    bool isDrifting = false;

    // --- 입력 상태 변수 ---
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    bool bInputUp = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    bool bInputLeft = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    bool bInputRight = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    bool bInputDrift = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Kart")
    bool bInputBooster = false;

    // --- 기능 함수 ---
    UFUNCTION(BlueprintCallable, Category = "Kart")
    void Respawn();

    UFUNCTION(BlueprintCallable, Category = "Kart")
    void UseBooster();
};