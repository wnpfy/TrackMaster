// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "KartCube.generated.h"

UCLASS()
class TRACKMASTER_API AKartCube : public APawn   // ← 전부 대문자로 수정
{
	GENERATED_BODY()
public:
	AKartCube();
protected:
	virtual void BeginPlay() override;
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// 큐브의 형태를 담당할 스태틱 메시 컴포넌트
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* CubeMesh;
	// 이동 속도 조절용 변수
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed = 1000.0f;
private:
	// 앞뒤로 움직이는 로직을 담당할 함수
	void MoveForward(float Value);
};