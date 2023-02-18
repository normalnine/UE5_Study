// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "Enemy.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Enemy ���� ����
	ConstructorHelpers::FClassFinder<AEnemy> tempEnemy(TEXT("Blueprint'/Game/Blueprints/BP_Enemy.BP_Enemy_C'"));
	if (tempEnemy.Succeeded())
	{
		enemyFactory = tempEnemy.Class;
	}

	
}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
	//ó�� �����ð� ����
	createTime = FMath::RandRange(minTime, maxTime);

	//SpawnPos ����
	FindSpawnPos();

	//���� �̸� 10�� ������
	for (int32 i = 0; i < 3; i++)
	{
		//� ��Ȳ�̴� ������ �����Ѵٴ� �ɼ�
		FActorSpawnParameters param;
		param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		/�� ����/
		AEnemy* e = GetWorld()->SpawnActor<AEnemy>(enemyFactory, GetActorLocation(), GetActorRotation(), param);		
		//���� �׾��� �� ȣ��Ǵ� �Լ� ���
		e->dieDelegate.BindUObject(this, &AEnemyManager::AddEnemy);
		//���� ��Ȱ��ȭ ����
		e->SetActive(false);
	}
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//���࿡ �� źâ ������ 0�̸� �Լ��� ������
	if (enemyArray.Num() == 0)
	{
		//�ֳʹ̸� ��������
		return;
	}

	//�ð��� �帣�� �Ѵ�
	currTime += DeltaTime;
	//���࿡ ����ð��� �����ð����� Ŀ����
	if (currTime > createTime)
	{
		//��� ��ġ�� ������ ����
		//int32 rand = FMath::RandRange(0, spawnPosArray.Num() - 1);
		//���õ� spawnPos �� ��� ��Ƶ���
		AActor* spawn = spawnPosArray[spawnIdx];

		//1. ������ yaw �� ������( 0 ~ 360 )
		float yaw = FMath::RandRange(0.0f, 360.0f);
		//2. ���� ���� spawnPosArray �� yaw ���� ����
		spawn->SetActorRotation(FRotator(0, yaw, 0));
		//3. ������ ���� ������( 0 ~ 500 )
		float length = FMath::RandRange(300.0f, 1000.0f);
		//4. spawnPosArray �չ��� * ���� ����
		FVector pos = spawn->GetActorForwardVector()* length;
		//5. 4������ ���� ���� + spawnPosArray �� ��ġ		
				
		//�� ��ġ, ȸ�� ����
		enemyArray[0]->SetActorLocation(spawn->GetActorLocation() + pos);
		enemyArray[0]->SetActorRotation(spawn->GetActorRotation());
		//�� źâ���� 0��° �� Ȱ��ȭ 
		enemyArray[0]->SetActive(true);
		//enemyArray ���� ����
		enemyArray.RemoveAt(0);

		//0 ~ ���� �������
		//���� �ڸ��� ����
		spawnIdx++;
		spawnIdx = spawnIdx % spawnPosArray.Num();

		////���࿡ spawnIdx �� spawnPosArray ������ ��������
		//if (spawnIdx == spawnPosArray.Num())
		//{
		//	//spawnIdx �� 0 ���� �Ѵ�.
		//	spawnIdx = 0;
		//}

		//����ð� �ʱ�ȭ
		currTime = 0;
		//�����ð� ���Ӱ� ����
		createTime = FMath::RandRange(minTime, maxTime);
	}
}


void AEnemyManager::FindSpawnPos()
{
	//���� ���͸� ã�Ƽ� ��������
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), actors);

	for (int32 i = 0; i < actors.Num(); i++)
	{
		//���࿡ �̸��� SpawnPos �� ���ԵǾ� �ִٸ�
		if (actors[i]->GetName().Contains(TEXT("SpawnPos")))
		{
			
			//spawnPosArray �� �߰��Ѵ�
			spawnPosArray.Add(actors[i]);
		}
	}
}

void AEnemyManager::AddEnemy(AEnemy* e)
{
	enemyArray.Add(e);
}
