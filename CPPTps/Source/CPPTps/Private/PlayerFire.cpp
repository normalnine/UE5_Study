// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerFire.h"
#include "Bullet.h"
#include <Blueprint/UserWidget.h>
#include <Particles/ParticleSystem.h>
#include "ABP_Player.h"
#include "TpsPlayer.h"
#include <Camera/CameraComponent.h>
#include <CollisionQueryParams.h>
#include <Kismet/GameplayStatics.h>
#include "Enemy.h"
#include "EnemyFSM.h"
#include "MainUI.h"

UPlayerFire::UPlayerFire()
{	
	//BP_Bullet Ŭ���� ��������
	ConstructorHelpers::FClassFinder<ABullet> tempBullet(TEXT("Blueprint'/Game/Blueprints/BP_Bullet.BP_Bullet_C'"));
	if (tempBullet.Succeeded())
	{
		bulletFactory = tempBullet.Class;
	}

	//SpnierUI Ŭ���� ��������
	ConstructorHelpers::FClassFinder<UUserWidget> tempSniperUI(TEXT("WidgetBlueprint'/Game/Blueprints/SniperUI.SniperUI_C'"));
	if (tempSniperUI.Succeeded())
	{
		sniperUIFactory = tempSniperUI.Class;
	}

	//CommonUI Ŭ���� ��������
	ConstructorHelpers::FClassFinder<UUserWidget> tempCommonUI(TEXT("WidgetBlueprint'/Game/Blueprints/CommonUI.CommonUI_C'"));
	if (tempCommonUI.Succeeded())
	{
		commUIFactory = tempCommonUI.Class;
	}

	//���� ��ƼŬ ��������
	ConstructorHelpers::FObjectFinder<UParticleSystem> tempExplo(TEXT("ParticleSystem'/Game/StarterContent/Particles/P_Explosion.P_Explosion'"));
	if (tempExplo.Succeeded())
	{
		exploEffect = tempExplo.Object;
	}
}

void UPlayerFire::BeginPlay()
{
	Super::BeginPlay();

	//SniperUI ������
	sniperUI = CreateWidget(GetWorld(), sniperUIFactory);

	//CommonUI ����� ���̰� ����
	commonUI = CreateWidget(GetWorld(), commUIFactory);
	commonUI->AddToViewport();

	//ó�� �� ������ Sniper �� ����
	ChangeWeapon(true);
}

void UPlayerFire::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//1. ���࿡ bFire �� true ���
	if (bFire == true)
	{
		//2. ����ð��� �帣�� �ϰ�
		currCamShakeTime += DeltaTime;
		//3. ���࿡ ����ð��� ���ؽð����� ������
		if (currCamShakeTime < camShakeTime)
		{			
			//4. ī�޶� �����ϰ� ��ġ��Ű��
			float randY = FMath::RandRange(-5.0f, 5.0f);
			float randZ = FMath::RandRange(-5.0f, 5.0f);
			me->compCam->SetRelativeLocation(FVector(0, randY, randZ));
		}
		//5. �׷��� ������ �ʱ�ȭ(����ð�, bFire, ī�޶���ġ)
		else
		{
			currCamShakeTime = 0;
			bFire = false;
			me->compCam->SetRelativeLocation(FVector::ZeroVector);
		}
	}
}

void UPlayerFire::SetupInputBinding(class UInputComponent* PlayerInputComponent)
{
	Super::SetupInputBinding(PlayerInputComponent);

	//���콺 ���� ��ư
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &UPlayerFire::InputFire);


	DECLARE_DELEGATE_OneParam(FChangeWeapon, bool);
	//1�� Ű
	//PlayerInputComponent->BindAction(TEXT("Rifle"), IE_Released, this, &ATpsPlayer::InputRifle);
	PlayerInputComponent->BindAction<FChangeWeapon>(TEXT("Rifle"), IE_Released, this, &UPlayerFire::ChangeWeapon, false);
	//2�� Ű
	//PlayerInputComponent->BindAction(TEXT("Sniper"), IE_Released, this, &ATpsPlayer::InputSniper);
	PlayerInputComponent->BindAction<FChangeWeapon>(TEXT("Sniper"), IE_Released, this, &UPlayerFire::ChangeWeapon, true);

	//Ctrl Ű
	PlayerInputComponent->BindAction(TEXT("Zoom"), IE_Pressed, this, &UPlayerFire::InputZoomIn);
	PlayerInputComponent->BindAction(TEXT("Zoom"), IE_Released, this, &UPlayerFire::InputZoomOut);
}

void UPlayerFire::InputFire()
{
	//APlayerController* controller = GetWorld()->GetFirstPlayerController();
	////ī�޶� ��鸲�� ������
	//controller->PlayerCameraManager->StopAllCameraShakes();
	////ī�޶� �����
	//controller->PlayerCameraManager->StartCameraShake(cameraShake);

	//���� ����!!
	bFire = true;


	//�ѽ�� �ִϸ��̼��� ����
	UABP_Player* playerAnim = Cast<UABP_Player>(me->GetMesh()->GetAnimInstance());
	playerAnim->PlayAttackAnim();

	//���࿡ Rifle �� ���̴� ���¶��
	if (me->compRifle->IsVisible() == true)
	{
		//FirePos Transform �� ��������
		FTransform trFire = me->compRifle->GetSocketTransform(TEXT("FirePos"));

		//�Ѿ˻��� (��ġ, ȸ�� ����)
		GetWorld()->SpawnActor<ABullet>(bulletFactory, trFire);
	}
	//Rifle �� ������ �ʴ� ���¶�� (Sniper �� ���̴� ����)
	else
	{
		//Start, 
		FVector startPos = me->compCam->GetComponentLocation();
		//End (ī�޶���ġ + ī�޶� �չ��� * �Ÿ�)
		FVector endPos = startPos + me->compCam->GetForwardVector() * 5000;
		//�浹�� �Ǿ��� �� ������ ���� ����
		FHitResult hitInfo;
		//�浹 �ɼ� ����
		FCollisionQueryParams param;
		param.AddIgnoredActor(me);

		//1. Line �� �߻��Ѵ�.(LineTrace ���)
		bool bHit = GetWorld()->LineTraceSingleByChannel(hitInfo, startPos, endPos, ECC_Visibility, param);
		//2. ���࿡ ������ Line �� �¾Ҵٸ�
		if (bHit == true)
		{
			//3. ���� ��ġ�� ���� ȿ���� �����ش�.
			UGameplayStatics::SpawnEmitterAtLocation(
				GetWorld(),
				exploEffect,
				hitInfo.ImpactPoint);

			//4. ���࿡ �����ְ� isSimulatingPhysics �� Ȱ��ȭ �Ǿ� �ִٸ�
			UPrimitiveComponent* compHit = hitInfo.GetComponent();
			if (compHit->IsSimulatingPhysics() == true)
			{
				//5. ���������� ���� ���Ѵ�. 
				//F = m * a;
				FVector force = compHit->GetMass() * me->compCam->GetForwardVector() * 30000;
				compHit->AddForceAtLocation(force, hitInfo.ImpactPoint);
			}

			//���࿡ �������� Enemy ���
			AActor* actor = hitInfo.GetActor();
			AEnemy* enemy = Cast<AEnemy>(actor);
			if (enemy != nullptr)
			{
				//Enemy - fsm - ReceiveDamage �Լ� ȣ��					
				enemy->fsm->ReceiveDamage();
			}
		}
	}
}

void UPlayerFire::InputRifle()
{
	ChangeWeapon(false);
}

void UPlayerFire::InputSniper()
{
	ChangeWeapon(true);
}



void UPlayerFire::ChangeWeapon(bool useSniper)
{
	//���࿡ useSniper �� false (Rifle �� ���� ����)
	if (useSniper == false && sniperUI->IsInViewport() == true)
	{
		//Common UI�� ���̰� �Ѵ�
		InputZoomOut();
	}

	me->compRifle->SetVisibility(!useSniper);
	me->compSniper->SetVisibility(useSniper);

	//���� UI ����
	//if (me->mainUI != nullptr)
	{
		me->mainUI->UpdateWeapon(useSniper);
	}

	////2-1 ���࿡ useSniper �� true �̸�
	//if (useSniper == true)
	//{
	//	//2-2 rifle �� ������ �ʰ�, sniper ���̰�
	//	compRifle->SetVisibility(false);
	//	compSniper->SetVisibility(true);
	//}
	////2-3 �׷��� �ʴٸ�(useSinper �� false)
	//else
	//{
	//	//2-4 rifle �� ���̰�, sniper ������ �ʰ�
	//	compRifle->SetVisibility(true);
	//	compSniper->SetVisibility(false);
	//}
}

void UPlayerFire::InputZoomIn()
{
	//0 ���࿡ �������۰� ������ �ʴ� ���¶�� �Լ��� �����ڴ�.
	if (me->compSniper->IsVisible() == false) return;

	//1 ����� ���� UI ViewPort�� ���̰�
	sniperUI->AddToViewport();

	//2 ī�޶��� Field of View �� 45��
	me->compCam->SetFieldOfView(45);

	//3 Common UI �� ��������
	commonUI->RemoveFromParent();
}

void UPlayerFire::InputZoomOut()
{
	//0 ���࿡ �������۰� ������ �ʴ� ���¶�� �Լ��� �����ڴ�.
	if (me->compSniper->IsVisible() == false) return;

	//1. SniperUI �� ��������
	sniperUI->RemoveFromParent();
	//2. ī�޶��� Field of View �� 90��
	me->compCam->SetFieldOfView(90);

	//3. Common UI �� ViewPort �� ������
	commonUI->AddToViewport();

}
