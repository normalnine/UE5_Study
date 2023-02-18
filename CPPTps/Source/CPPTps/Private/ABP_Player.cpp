// Fill out your copyright notice in the Description page of Project Settings.


#include "ABP_Player.h"
#include "TpsPlayer.h"
#include <GameFramework/CharacterMovementComponent.h>

UABP_Player::UABP_Player()
{
	//attack montage ��������
	ConstructorHelpers::FObjectFinder<UAnimMontage> tempMontage(TEXT("AnimMontage'/Game/Blueprints/AMT_Attack.AMT_Attack'"));
	if (tempMontage.Succeeded())
	{
		attackAnimMontage = tempMontage.Object;
	}
}

void UABP_Player::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	//ATpsPlayer ������ ����
	//1. ���� �� ��������
	APawn* pawn = TryGetPawnOwner();

	//2. ATpsPlayer �� ĳ����
	me = Cast<ATpsPlayer>(pawn);
}

void UABP_Player::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);		

	//���࿡ me �� nullptr �ƴϸ�
	if (me != nullptr)
	{    
		//3. �ӵ� , �չ���, ������ ���� ��������
		FVector velocity = me->GetVelocity();
		FVector forward = me->GetActorForwardVector();
		FVector right = me->GetActorRightVector();

		//4. �� ���͸� ������ �� dirV �� ���� (������ ���� �ִ���? �ڷ� ���� �ִ���?)
		dirV = FVector::DotProduct(velocity, forward);		

		//5. ���������� ���� �ִ���? �������� ���� �ִ���?
		dirH = FVector::DotProduct(velocity, right);

		//���߿� �ִ��� ���� ����
		bAir = me->GetCharacterMovement()->IsFalling();
	}
}

void UABP_Player::PlayAttackAnim()
{
	Montage_Play(attackAnimMontage);
}