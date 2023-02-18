// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMove.h"
#include "TpsPlayer.h"
#include <GameFramework/SpringArmComponent.h>
#include <GameFramework/CharacterMovementComponent.h>

void UPlayerMove::BeginPlay()
{
	Super::BeginPlay();	

	//Controller �� ȸ������ ���� �� �Ӽ� ����
	me->bUseControllerRotationYaw = true;
	me->compArm->bUsePawnControlRotation = true;

	//���� Ƚ���� 2���� ����
	me->JumpMaxCount = 2;
	//�����̴� �ӷ��� walkSpeed �� ����	
	me->GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
	//�����ϴ� �ӷ��� 600���� ����
	me->GetCharacterMovement()->JumpZVelocity = 600;

	//ī�޶� ���� ȸ���� min, max ����
	APlayerController* playerController = Cast<APlayerController>(me->Controller);
	playerController->PlayerCameraManager->ViewPitchMin = -45;
	playerController->PlayerCameraManager->ViewPitchMax = 45;
}

void UPlayerMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//�̵�
	MoveAction(DeltaTime);
	//ȸ��	
	//RotateAction();
}

void UPlayerMove::SetupInputBinding(class UInputComponent* PlayerInputComponent)
{
	Super::SetupInputBinding(PlayerInputComponent);

	//A, D
	PlayerInputComponent->BindAxis(TEXT("Horizontal"), this, &UPlayerMove::InputHorizontal);
	//W, S
	PlayerInputComponent->BindAxis(TEXT("Vertical"), this, &UPlayerMove::InputVertical);
	//���콺 �¿�
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &UPlayerMove::InputTurn);
	//���콺 ����
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &UPlayerMove::InputLookUp);
	//Space Bar
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &UPlayerMove::InputJump);
	//Shift Ű
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Pressed, this, &UPlayerMove::InputRun);
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &UPlayerMove::InputRun);
}

void UPlayerMove::MoveAction(float deltaTime)
{
	//P = P0 + vt
	FVector p0 = me->GetActorLocation();
	FVector dir = me->GetActorForwardVector() * v + me->GetActorRightVector() * h;
	//(1, 0, 0) * v + (0, 1, 0) * h = (v, 0, 0) + (0, h, 0) = (v, h, 0);
	FVector vt = dir.GetSafeNormal() * walkSpeed * deltaTime;
	//SetActorLocation(p0 + vt);

	//Controller �� �̿��� �̵�
	me->AddMovementInput(dir.GetSafeNormal());
}

void UPlayerMove::RotateAction()
{
	//���콺 �¿쿡 ���� Actor �� ȸ�� ��Ű��
	me->SetActorRotation(FRotator(0, mx, 0));
	//���콺 ���Ͽ� ���� SpringArm�� ȸ�� ��Ű��
	me->compArm->SetRelativeRotation(FRotator(-my, 0, 0));
}

void UPlayerMove::InputHorizontal(float value)
{
	h = value;
}

void UPlayerMove::InputVertical(float value)
{
	v = value;
}

void UPlayerMove::InputLookUp(float value)
{
	me->AddControllerPitchInput(value);
	//my += value;
	//my = FMath::Clamp(my, -45, 45);

	////���࿡ my �� -45 ���� �۴ٸ�
	//if (my < -45)
	//{
	//	//my �� -45�� ����
	//	my = -45;
	//}
	////���࿡ my �� 45 ���� Ŀ����
	//if (my > 45)
	//{
	//	//my �� 45�� ����
	//	my = 45;
	//}
}

void UPlayerMove::InputTurn(float value)
{
	me->AddControllerYawInput(value);
	//mx += value;
}

void UPlayerMove::InputJump()
{
	me->Jump();
}

void UPlayerMove::InputRun()
{
	UCharacterMovementComponent* compMove = me->GetCharacterMovement();
	//1. ���࿡ MaxWalkSpeed ���� walkSpeed ���� ũ�ٸ�(�ٰ� �ִٸ�)
	if (compMove->MaxWalkSpeed > walkSpeed)
	{
		//2. MaxWalkSpeed ���� walkSpeed �� ����
		compMove->MaxWalkSpeed = walkSpeed;
	}
	//3. �׷��� ������(�Ȱ� �ִٸ�)
	else
	{
		//4. MaxWalkSpeed ���� runSpeed �� ����
		compMove->MaxWalkSpeed = runSpeed;
	}
}