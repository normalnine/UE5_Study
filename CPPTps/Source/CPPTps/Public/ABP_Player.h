// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ABP_Player.generated.h"

/**
 * 
 */
UCLASS()
class CPPTPS_API UABP_Player : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UABP_Player();

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

public:

	//Player Actor
	UPROPERTY()
	class ATpsPlayer* me;

	// ��, �ڸ� �Ǻ��ϴ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float dirV = 0;

	// ������, ������ �Ǻ��ϴ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float dirH = 0;
	
	//���߿� �ִ��� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bAir = false;

	UPROPERTY(EditAnywhere)
	class UAnimMontage* attackAnimMontage;

public:
	void PlayAttackAnim();
};
