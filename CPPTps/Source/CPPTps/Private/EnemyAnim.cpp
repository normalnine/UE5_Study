// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnim.h"
#include "Enemy.h"
#include "TpsPlayer.h"

void UEnemyAnim::NativeBeginPlay()
{
	//GetOwningActor(); <<-------- Actor �� �����´�.
	/*AActor* actor = GetOwningActor();
	APawn* p =Cast<APawn>(actor);*/

	//1. ���� �پ� �ִ� Pawn �� �����´�.
	APawn* pawn = TryGetPawnOwner();

	//2. AEnemy �� ����ȯ�Ѵ�.
	enemy = Cast<AEnemy>(pawn);
}

void UEnemyAnim::AnimNotify_DieEnd()
{
	//3. enemy �� ������ �ִ� fsm �� �̿��ؼ� bDieMove �� true
	enemy->fsm->bDieMove = true;

	//Cast<AEnemy>(TryGetPawnOwner())->fsm->bDieMove = true;
}

void UEnemyAnim::AnimNotify_EnemyAttack()
{
	//�÷��̾�� Damage �� ����
	enemy->fsm->target->ReceiveDamage(1);
}