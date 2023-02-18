// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

UCLASS()
class CPPTPS_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//�����ð�
	float createTime = 0;
	//����ð�
	float currTime = 0;
	//�ּҽð�
	float minTime = 1;
	//�ִ�ð�
	float maxTime = 5;
	//Enemy ����
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemy> enemyFactory;

	//�� ���� ��ġ��
	UPROPERTY(EditAnywhere)
	TArray<AActor*> spawnPosArray;

	//Enemy źâ
	UPROPERTY(EditAnywhere)
	TArray<class AEnemy*> enemyArray;

public:
	int32 spawnIdx = 0;
	void FindSpawnPos();

	UFUNCTION()
	void AddEnemy(class AEnemy* e);
};
