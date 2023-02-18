// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TpsPlayer.generated.h"


UCLASS()
class CPPTPS_API ATpsPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATpsPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere)
	class USpringArmComponent* compArm;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* compCam;

	UPROPERTY(EditAnywhere)
	class USkeletalMeshComponent* compRifle;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* compSniper;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> cameraShake;

	UPROPERTY(EditAnywhere)
	class UPlayerMove* compPlayerMove;
	UPROPERTY(EditAnywhere)
	class UPlayerFire* compPlayerFire;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UMainUI> mainUIFactory;
	UPROPERTY(EditAnywhere)
	class UMainUI* mainUI;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameOverUI> gameOverUIFactory;
	UPROPERTY(EditAnywhere)
	class UGameOverUI* gameOverUI;

	//���� HP
	float currHP;
	//�ִ� HP
	float maxHP = 1;
	//���� HP
	float prevHP;
	//HP UI �� ������ �� �ִ�?
	bool bUpdateHP = false;
	//HP UI �پ��� ����
	float ratioHP = 0.0f;


	//�̴ϸ� �������Ʈ Ŭ����
	UPROPERTY()
	TSubclassOf<class AMinimap> miniFactory;

public:
	void ReceiveDamage(float damage);	
};
