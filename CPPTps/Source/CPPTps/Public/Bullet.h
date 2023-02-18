// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class CPPTPS_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere)
	class USphereComponent* compSphere;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* compMesh;

	//�߻�ü ������ Component
	UPROPERTY(EditAnywhere)
	class UProjectileMovementComponent* compProjectile;

	//�����ð�
	float currTime = 0;
	//�ı��ð�
	float destoryTime = 2;

public:
	void Die();
};
