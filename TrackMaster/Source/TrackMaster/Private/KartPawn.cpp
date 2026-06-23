// Fill out your copyright notice in the Description page of Project Settings.


#include "KartPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Engine/Engine.h"

AKartPawn::AKartPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // 루트 컴포넌트로 사용할 스태틱 메시(네모) 생성
    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;

    // 물리 시뮬레이션은 끄고 코드로 직접 제어합니다.
    MeshComponent->SetSimulatePhysics(false);
}

void AKartPawn::BeginPlay()
{
    Super::BeginPlay();
    
    // 시작할 때 액터의 현재 회전값(Yaw)을 headingAngle 초기값으로 설정
    headingAngle = GetActorRotation().Yaw;
}

void AKartPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // 1. 가속 및 감속 로직
    if (bInputUp) 
    {
        float speedRatio = currentSpeed / MAX_SPEED;
        float currentAccel = BASE_ACCEL * (1.0f - (speedRatio * speedRatio));
        
        currentSpeed += currentAccel * DeltaTime;
        if (currentSpeed > MAX_SPEED) currentSpeed = MAX_SPEED;
    } 
    else 
    {
        currentSpeed -= NATURAL_DECEL * DeltaTime;
        if (currentSpeed < 0) currentSpeed = 0.0f;
    }

    // 2. 조향 및 조향 감속 로직
    if (bInputLeft || bInputRight) 
    {
        if (currentSpeed > 0.0f) 
        {
            float turnAmount = TURN_SPEED * DeltaTime;
            if (bInputLeft)  headingAngle -= turnAmount;
            if (bInputRight) headingAngle += turnAmount;

            currentSpeed -= TURN_DECEL_RATE * DeltaTime;
            if (currentSpeed < 0.0f) currentSpeed = 0.0f;
        }
    }

    // 3. 드리프트 및 부스터 게이지 충전 로직
    isDrifting = bInputDrift && (bInputLeft || bInputRight) && (currentSpeed > 30.0f);

    if (isDrifting) 
    {
        driftAngle += 150.0f * DeltaTime; 
        if (driftAngle > 180.0f) driftAngle = 180.0f;

        float driftAngleRad = FMath::DegreesToRadians(driftAngle);
        float chargeRate = currentSpeed * FMath::Sin(driftAngleRad) * 0.05f; 
        
        boosterGauge += chargeRate * DeltaTime;
        if (boosterGauge > MAX_BOOSTER) boosterGauge = MAX_BOOSTER;
    } 
    else 
    {
        driftAngle = 0.0f; 
    }

    // 4. 부스터 사용 로직
    if (bInputBooster && boosterGauge >= MAX_BOOSTER) 
    {
        UseBooster();
    }

    // 5. 실제 네모 회전 및 이동 반영
    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw = headingAngle;
    SetActorRotation(NewRotation);

    // km/h 단위를 언리얼 단위(cm/s)로 변환하기 위해 약 27.78을 곱함
    float SpeedInUnrealUnit = currentSpeed * 27.7778f; 
    FVector ForwardDirection = GetActorForwardVector();
    FVector NewLocation = GetActorLocation() + (ForwardDirection * SpeedInUnrealUnit * DeltaTime);
    SetActorLocation(NewLocation);

    // 디버그 출력
    if (GEngine) {
        FString DebugMsg = FString::Printf(TEXT("Speed: %.1f km/h | Booster: %.1f%%"), currentSpeed, boosterGauge);
        GEngine->AddOnScreenDebugMessage(1, 0.0f, FColor::Green, DebugMsg);
    }
}

void AKartPawn::Respawn()
{
    currentSpeed = 0.0f;
    driftAngle = 0.0f;
    isDrifting = false;
    
    // 리스폰 시 살짝 위 공중(Z=100)으로 이동
    SetActorLocation(FVector(0.0f, 0.0f, 100.0f));
    headingAngle = 0.0f;

    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Yellow, TEXT("카트 리스폰 됨!"));
}

void AKartPawn::UseBooster()
{
    boosterGauge = 0.0f;
    currentSpeed = MAX_SPEED + 50.0f; // 한계 돌파 속도 달성
    
    if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("부스터 발동!!!"));
}