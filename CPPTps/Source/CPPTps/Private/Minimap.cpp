// Fill out your copyright notice in the Description page of Project Settings.


#include "Minimap.h"
#include <Components/SceneCaptureComponent2D.h>
#include <Engine/TextureRenderTarget2D.h>
#include <Kismet/GameplayStatics.h>
#include "TpsPlayer.h"

AMinimap::AMinimap()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UTextureRenderTarget2D> tempTex(TEXT("TextureRenderTarget2D'/Game/Images/RT_Minimap.RT_Minimap'"));
	if (tempTex.Succeeded())
	{
		GetCaptureComponent2D()->TextureTarget = tempTex.Object;
	}
}

void AMinimap::BeginPlay()
{
	Super::BeginPlay();

	//�÷��̾� ã��
	target = UGameplayStatics::GetActorOfClass(GetWorld(), ATpsPlayer::StaticClass());
}

void AMinimap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//target ��ġ�� pos ���������� ��������
	FVector pos = target->GetActorLocation();
	//pos �� Z ���� 540 ���� ����
	pos.Z = 540;
	//���� ��ġ�� pos ������ �����Ѵ�.
	SetActorLocation(pos);
}