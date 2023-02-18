// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/BoxComponent.h>

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Sphere Component �߰�
	compSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SPHERE"));
	SetRootComponent(compSphere);
	compSphere->SetSphereRadius(13);
	//���͵�� �浹�ϰ� �Ѵ�
	compSphere->SetCollisionProfileName(TEXT("BlockAll"));

	//StaticMesh Component �߰�
	compMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	compMesh->SetupAttachment(RootComponent);
	compMesh->SetRelativeLocation(FVector(0, 0, -13));
	compMesh->SetRelativeScale3D(FVector(0.26f));
	compMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//Sphere ���� �����ͼ� ��������
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (tempMesh.Succeeded())
	{
		compMesh->SetStaticMesh(tempMesh.Object);
	}

	//Projectile Movement Component ����
	compProjectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PROJECTILE"));
	//Movement �� �������� �� Component�� ����
	compProjectile->SetUpdatedComponent(compSphere);
	//�ʱ�ӷ�
	compProjectile->InitialSpeed = 2000;
	//�ִ�ӷ�
	compProjectile->MaxSpeed = 2000;
	//�ݵ�����(ƨ��¿���)
	compProjectile->bShouldBounce = true;
	//�󸶳� �� ƨ��� �Ұ����� (0 ~ 1)
	compProjectile->Bounciness = 0.5f;

	//���� �ð��� 2�ʷ� �Ѵ�.
	//InitialLifeSpan = 2;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
	//Timer ��������
	FTimerHandle deathTimer;
	GetWorld()->GetTimerManager().SetTimer(deathTimer, this, &ABullet::Die, destoryTime, false);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�չ������� ��� �̵��ϰ� �ʹ�
	//P = P0 + vt
	FVector p0 = GetActorLocation();
	FVector vt = GetActorForwardVector() * 2000 * DeltaTime;
	//SetActorLocation(p0 + vt);

	////�ð��� �������ش�
	//currTime += DeltaTime;
	////2�ʰ� ������ 
	//if (currTime > destoryTime)
	//{
	//	//���� �ı�����
	//	Destroy();
	//}
}

void ABullet::Die()
{
	Destroy();
}

