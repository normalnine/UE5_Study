// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerBaseComponent.h"
#include "PlayerMove.generated.h"

/**
 * 
 */
UCLASS()
class CPPTPS_API UPlayerMove : public UPlayerBaseComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void SetupInputBinding(class UInputComponent* PlayerInputComponent) override;

public:
	//�ȱ� �ӷ�
	float walkSpeed = 350;
	//�ٱ� �ӷ�
	float runSpeed = 700;

	//W, A, S, D Ű�� ���� �� ����
	float h = 0;
	float v = 0;

	//���콺 �����ӿ� ���� �� ����
	float mx = 0;
	float my = 0;

public:
	void MoveAction(float deltaTime);
	void RotateAction();

	void InputHorizontal(float value);
	void InputVertical(float value);
	void InputLookUp(float value);
	void InputTurn(float value);
	void InputJump();
	void InputRun();
};
