// Copyright Epic Games, Inc. All Rights Reserved.


#include "CPPShootingGameModeBase.h"
#include <Blueprint/UserWidget.h>
#include "MainUI.h"
#include <Kismet/GameplayStatics.h>
#include "BestScoreData.h"
#include "GameOverUI.h"

ACPPShootingGameModeBase::ACPPShootingGameModeBase()
{
	ConstructorHelpers::FClassFinder<UMainUI> tempMainUI(TEXT("WidgetBlueprint'/Game/Blueprints/BP_MainUI.BP_MainUI_C'"));
	if (tempMainUI.Succeeded())
	{
		mainWidget = tempMainUI.Class;
	}

	ConstructorHelpers::FClassFinder<UGameOverUI> tempGameOverUI(TEXT("WidgetBlueprint'/Game/Blueprints/BP_GameOverUI.BP_GameOverUI_C'"));
	if (tempGameOverUI.Succeeded())
	{
		gameOverWidget = tempGameOverUI.Class;
	}
}

void ACPPShootingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	//mainUI �� �����
	mainUI = CreateWidget<UMainUI>(GetWorld(), mainWidget);

	//���� UI�� Viewport�� ������.
	mainUI->AddToViewport();	

	//�ְ������� ��������
	//mainUI->UpdateBestScoreUI(bestScore);

	//�ְ����� �ҷ�����
	LoadBestScore();
}

void ACPPShootingGameModeBase::AddScore(int32 addValue)
{
	currScore += addValue;
	mainUI->UpdateCurrScoreUI(currScore);

	//�ְ����� ���� ���� (�������� > �ְ�����)
	if (currScore > bestScore)
	{
		bestScore = currScore;
		mainUI->UpdateBestScoreUI(bestScore);
		
	}
	//�����ϸ� �ְ����� ����
	//�ְ����� ���

	//UE_LOG(LogTemp, Warning, TEXT("currscore : %d"), currScore);

	SaveBestScore();
}

void ACPPShootingGameModeBase::SaveBestScore()
{
	//bestScore -> BestScoreData �� �ִ� saveBestScore ������ �ִ´�

	//1. UBestScoreData �� �ϳ� �����Ѵ�. (USaveGame*)
	USaveGame* saveGame = UGameplayStatics::CreateSaveGameObject(UBestScoreData::StaticClass());

	//2. ������ ���� UBestScoreData �� Cast ����
	UBestScoreData* bestScoreData = Cast<UBestScoreData>(saveGame);

	//3. saveBestScore = bestScore
	bestScoreData->saveBestScore = bestScore;
	
	//4. �����Ѵ�
	UGameplayStatics::SaveGameToSlot(saveGame, TEXT("BEST_SCORE"),0);

}
void ACPPShootingGameModeBase::LoadBestScore()
{
	//1. "BEST_SCORE" ���� �Ǿ� �ִ� �����͸� �ҷ��´�. (USaveGame*)
	USaveGame* saveGame = UGameplayStatics::LoadGameFromSlot(TEXT("BEST_SCORE"), 0);
	
	//2. �ҷ��� ���� UBestScoreData �� Cast ����
	UBestScoreData* bestScoreData = Cast<UBestScoreData>(saveGame);

	//���࿡ bestScoreData �� nullptr �� �ƴ϶��
	if (bestScoreData != nullptr) 
	{
		//3. bestScore = saveBestScore
		bestScore = bestScoreData->saveBestScore;

		//4. BestScore UI �� �����Ѵ�.
		mainUI->UpdateBestScoreUI(bestScore);
	}
}

void ACPPShootingGameModeBase::ShowGameOverUI()
{
	//GameOverUI �� �ϳ� �����.
	gameOverUI = CreateWidget<UGameOverUI>(GetWorld(), gameOverWidget);

	//���� UI �� ȭ�鿡 ����.
	gameOverUI->AddToViewport();
}


void ACPPShootingGameModeBase::ShuffleStudy()
{
	//int �� 100�� ���� �� �ִ� �迭�� �����.
	//�ʱⰪ�� 1 ~ 100���� ���� �Ѵ�

	int32 a[100];
	
	for (int32 i = 0; i < 100; i++)
	{
		a[i] = i + 1;
	}
	for (int32 i = 0; i < 100; i++)
	{
		int32 randA = FMath::RandRange(0, 99);
		int32 randB = FMath::RandRange(0, 99);

		int32 temp = a[randA];
		a[randA] = a[randB];
		a[randB] = temp;
	}
	for (int32 i = 0; i < 100; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("a[%d] value is %d"), i, a[i]);
	}
}
