// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFSM.h"
#include <Kismet/GameplayStatics.h>
#include "TpsPlayer.h"
#include "Enemy.h"
#include <Components/CapsuleComponent.h>
#include <Kismet/KismetMathLibrary.h>
#include "EnemyAnim.h"
#include <AIModule/Classes/AIController.h>
#include <NavigationSystem.h>
#include "EnemyManager.h"

// Sets default values for this component's properties
UEnemyFSM::UEnemyFSM()
{
	//SetActive (true / false) �۵� �ǰ� ����!
	bAutoActivate = true;
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	//��Ÿ�� �ҷ�����
	ConstructorHelpers::FObjectFinder<UAnimMontage> tempMontage(TEXT("AnimMontage'/Game/Blueprints/AMT_EnemyDamage.AMT_EnemyDamage'"));
	if (tempMontage.Succeeded())
	{
		damageMontage = tempMontage.Object;
	}
}


// Called when the game starts
void UEnemyFSM::BeginPlay()
{
	Super::BeginPlay();

	//Ÿ�� ã��
	target = Cast<ATpsPlayer>(UGameplayStatics::GetActorOfClass(GetWorld(), ATpsPlayer::StaticClass()));
	//���� ã��
	me = Cast<AEnemy>(GetOwner());	
	
	//anim instance ã��
	/*USkeletalMeshComponent* mesh = me->GetMesh();
	UAnimInstance animInstance = mesh->GetAnimInstance();
	anim = Cast<UEnemyAnim>(animInstance);*/
	anim = Cast<UEnemyAnim>(me->GetMesh()->GetAnimInstance());

	//ai controller ã��
	ai = Cast<AAIController>(me->GetController());
	//ai = UAIBlueprintHelperLibrary::GetAIController(me);

	//���� �ʱ� ü���� ��������
	currHP = maxHP;

	//���� �ʱ� ��ġ�� ��������
	originPos = me->GetActorLocation();

}


// Called every frame
void UEnemyFSM::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	switch (currState)
	{
	case EEnemyState::Idle:
		UpdateIdle();
		break;
	case EEnemyState::Move:
		UpdateMove();
		break;
	case EEnemyState::Attack:
		UpdateAttack();
		break;
	case EEnemyState::AttackDelay:
		UpdaetAttackDelay();
		break;
	case EEnemyState::Damaged:
		UpdateDamaged();
		break;
	case EEnemyState::Die:
		UpdateDie();
		break;
	case EEnemyState::ReturnPos:
		UpdateReturnPos();
		break;
	}
}

void UEnemyFSM::UpdateIdle()
{
	//���࿡ �÷��̾ �Ѿ� �� �� �ִ�?
	if (IsTargetTrace())
	{
		//���¸� Move �� ��ȯ
		ChangeState(EEnemyState::Move);
	}
	else
	{
		//idleDelayTime �� ������	
		if (IsWaitComplete(idleDelayTime))
		{
			//������¸� Move �� �Ѵ�.
			ChangeState(EEnemyState::Move);
		}
	}
}

void UEnemyFSM::UpdateMove()
{
	// �þ߿� ���Դ��� ����
	bool bTrace = IsTargetTrace();

	//1. Ÿ���� ���ϴ� ������ ���ϰ�(target - me)
	FVector dir = target->GetActorLocation() - me->GetActorLocation();

	//ó�� ��ġ, ���� ���� ��ġ�� �Ÿ�
	float dist = FVector::Distance(originPos, me->GetActorLocation());
	
	//���࿡ dist �� moveRange ���� Ŀ���� (������ �� �ִ� �ݰ��� �Ѿ�ٸ�)
	if (dist > moveRange)
	{
		//���¸� ReturnPos �� ����
		ChangeState(EEnemyState::ReturnPos);
	}
	//���࿡ �þ߿� ���Դٸ�
	else if (bTrace)
	{
		//���࿡ target - me �Ÿ��� ���ݹ������� ������
		if (dir.Length() < attackRange)
		{
			//���¸� Attack ���� ����
			ChangeState(EEnemyState::Attack);
		}
		//�׷��� ������
		else
		{
			//2. �� �������� �̵��ϰ� �ʹ�.
			//me->AddMovementInput(dir.GetSafeNormal());
			//ai �� �̿��ؼ� ���������� �̵��ϰ� �ʹ�.	
			ai->MoveToLocation(target->GetActorLocation());
		}
	}
	//�þ߿� ������ �ʾҴٸ�
	else
	{
		// ������ ��ġ���� ������ �� Idle ���·� ��ȯ
		MoveToPos(randPos);
	}
	
}

void UEnemyFSM::UpdateAttack()
{	
	//2. ���¸� AttackDelay �� ��ȯ
	ChangeState(EEnemyState::AttackDelay);	
}

void UEnemyFSM::UpdaetAttackDelay()
{
	//2. ���࿡ ����ð��� attackDelayTime ���� Ŀ����
	if (IsWaitComplete(attackDelayTime))
	{
		//3. target �� me �Ÿ��� ������.
		FVector dir = target->GetActorLocation() - me->GetActorLocation();
		float dist = dir.Length();
		//4. ���࿡ �װŸ��� attackRange���� ������
		if (dist < attackRange)
		{
			//5. Attack ���·� ��ȯ
			ChangeState(EEnemyState::Attack);
		}
		else
		{
			//6. �׷��� ������ Idle ���·� ����
			ChangeState(EEnemyState::Idle);
		}
	}
}

void UEnemyFSM::UpdateDamaged()
{
	//damageDelayTime �� ������
	if (IsWaitComplete(damageDelayTime))
	{
		//Move ����
		ChangeState(EEnemyState::Idle);
	}
}

void UEnemyFSM::UpdateDie()
{
	//���࿡ bDieMove �� false ��� �Լ��� ������
	if (bDieMove == false) return;

	//P = P0 + vt
	//1. �Ʒ��� �������� ��ġ�� ���Ѵ�.
	FVector p0 = me->GetActorLocation();
	FVector vt = FVector::DownVector * dieSpeed * GetWorld()->DeltaTimeSeconds;
	FVector p = p0 + vt;

	//2. ���࿡ p.Z �� -200 ���� ������ �ı��Ѵ�
	if (p.Z < -200)
	{
		//me->Destroy();
		
		//���� ��Ȱ��ȭ
		me->SetActive(false);
		////EnemyManager ã��
		//AActor* actor = UGameplayStatics::GetActorOfClass(GetWorld(), AEnemyManager::StaticClass());
		//AEnemyManager* am = Cast<AEnemyManager>(actor);
		////ã�� �𿡼� enemyArray �� ���� �ٽ� ����
		//am->enemyArray.Add(me);
		//currHP �� maxHP
		currHP = maxHP;
		//���¸� Idle
		ChangeState(EEnemyState::Idle);
		//��Ÿ�ָ� �����ش�
		me->StopAnimMontage(damageMontage);
		//bDieMove �� false ��!
		bDieMove = false;
	}
	//3. �׷��� ������ �ش� ��ġ�� �����Ѵ�
	else
	{
		me->SetActorLocation(p);
	}
}

void UEnemyFSM::UpdateReturnPos()
{
	// ó�� ��ġ�� ���� �����ϸ� Idle ���·� ��ȯ�Ѵ�.
	MoveToPos(originPos);
	

	////1. �� ----> ó����ġ�� ���ϴ� ������ ���Ѵ�.
	//FVector dir = originPos - me->GetActorLocation();

	////2. ���࿡ �� --- ó����ġ�� �Ÿ��� 10���� ������
	//if (dir.Length() < 10)
	//{
	//	//3. Idle ���·� ��ȯ
	//	ChangeState(EEnemyState::Idle);
	//}
	////4. �׷��� ������ 
	//else
	//{
	//	//5. ��� 1������ ���� �������� �̵��Ѵ�
	//	me->AddMovementInput(dir.GetSafeNormal());
	//}
}

void UEnemyFSM::ChangeState(EEnemyState state)
{
	//���� ���� �α׸� �������
	UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EEnemyState"), true);
	if (enumPtr != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s -----> %s"),
			*enumPtr->GetNameStringByIndex((int32)currState),
			*enumPtr->GetNameStringByIndex((int32)state));
	}		

	//���� ���¸� ����
	currState = state;

	//anim �� ���� ����
	anim->state = state;

	//���� �ð� �ʱ�ȭ
	currTime = 0;	

	//ai �� ������ ������
	ai->StopMovement();

	//���¿� ���� �ʱ⼳��
	switch (currState)
	{
	case EEnemyState::Attack:
		//currTime = attackDelayTime;
		break;
	case EEnemyState::Move:
	{
		//�׺���̼� �ý��� ��������
		UNavigationSystemV1* ns = UNavigationSystemV1::GetNavigationSystem(GetWorld());
		//������ ��ġ�� �����
		FNavLocation loc;
		ns->GetRandomReachablePointInRadius(originPos, 1000, loc);
		randPos = loc.Location;
	}
		break;
	case EEnemyState::Damaged:
	{
		//1. ������ ���� �̴´� (0, 1 ��)
		int32 rand = FMath::RandRange(0, 1);
		//2. Damage0, Damage1 �̶� ���ڿ��� �����.
		FString sectionName = FString::Printf(TEXT("Damage%d"), rand);
		//3. ��Ÿ�ָ� �÷����Ѵ�.
		me->PlayAnimMontage(damageMontage, 1.0f, FName(*sectionName));
	}
		break;
	case EEnemyState::Die:		
		//�浹�ȵǰ� ����
		me->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		//Die ��Ÿ�� ����
		me->PlayAnimMontage(damageMontage, 1.0f, FName(TEXT("Die")));
		break;
	}
}

void UEnemyFSM::ReceiveDamage()
{
	//�Ǹ� ������
	currHP--;
	//hp �� 0���� ũ�� Damage ���·� ��ȯ
	if (currHP > 0)
	{
		ChangeState(EEnemyState::Damaged);
	}
	//�׷��� ������ Die ���·� ��ȯ
	else
	{

		ChangeState(EEnemyState::Die);
	}
}

bool UEnemyFSM::IsWaitComplete(float delayTime)
{
	//1. �ð��� �帣�� �Ѵ�.
	currTime += GetWorld()->DeltaTimeSeconds;
		
	//2. ���࿡ ����ð��� delayTime���� Ŀ���� 
	if (currTime > delayTime)
	{
		//3. ����ð��� 0���� �ʱ�ȭ
		currTime = 0;
		//4. true ��ȯ
		return true;
	}

	//5. �׷��� ������ false �� ��ȯ
	return false;
}


bool UEnemyFSM::IsTargetTrace()
{
	//1. �� ----> �÷��̾ ���ϴ� ����
	FVector dir = target->GetActorLocation() - me->GetActorLocation();

	//2. ���� �չ���� 1���� ���� ������ ����
	float dotValue = FVector::DotProduct(me->GetActorForwardVector(), dir.GetSafeNormal());

	//3. 2���� ���� ���� Acos --> �� ������ ���̰�
	float angle = UKismetMathLibrary::DegAcos(dotValue);
	
	//4. ���࿡ 3������ ���� ���� 30���� �۰�(�þ߰� 60)
	//   �� - Ÿ�� ���� �Ÿ��� traceRange ���� ������
	if (angle < 30 && dir.Length() < traceRange)
	{
		//Enemy -----> target LineTrace ����!!
		FHitResult hitInfo;
		FCollisionQueryParams param;
		param.AddIgnoredActor(me);

		bool bHit = GetWorld()->LineTraceSingleByChannel(
			hitInfo,
			me->GetActorLocation(),
			target->GetActorLocation(),
			ECollisionChannel::ECC_Visibility,
			param);

		//���࿡ �ε��� ���� �ִٸ�
		if (bHit)
		{
			//���࿡ �ε��� ���� �̸��� Player �� �����ϰ� �ִٸ�
			if (hitInfo.GetActor()->GetName().Contains(TEXT("Player")))
			{
				//5. true ��ȯ
				return true;
			}	
		}
	}

	//6. �׷��� ������ false ��ȯ	
	return false;

}

void UEnemyFSM::MoveToPos(FVector pos)
{
	//�ش� ��ġ(pos) �� ����
	EPathFollowingRequestResult::Type result = ai->MoveToLocation(pos);

	//���࿡ �������� �����ߴٸ�
	if (result == EPathFollowingRequestResult::AlreadyAtGoal)
	{
		//Idle ���·� ��ȯ
		ChangeState(EEnemyState::Idle);
	}
}
