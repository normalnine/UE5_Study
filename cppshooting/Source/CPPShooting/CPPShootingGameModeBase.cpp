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
	
	//mainUI 를 만든다
	mainUI = CreateWidget<UMainUI>(GetWorld(), mainWidget);

	//만든 UI를 Viewport에 붙힌다.
	mainUI->AddToViewport();	

	//최고점수를 세팅하자
	//mainUI->UpdateBestScoreUI(bestScore);

	//최고점수 불러오자
	LoadBestScore();
}

void ACPPShootingGameModeBase::AddScore(int32 addValue)
{
	currScore += addValue;
	mainUI->UpdateCurrScoreUI(currScore);

	//최고점수 갱신 조건 (현재점수 > 최고점수)
	if (currScore > bestScore)
	{
		bestScore = currScore;
		mainUI->UpdateBestScoreUI(bestScore);
		
	}
	//만족하면 최고점수 갱신
	//최고점수 출력

	//UE_LOG(LogTemp, Warning, TEXT("currscore : %d"), currScore);

	SaveBestScore();
}

void ACPPShootingGameModeBase::SaveBestScore()
{
	//bestScore -> BestScoreData 에 있는 saveBestScore 변수에 넣는다

	//1. UBestScoreData 를 하나 생성한다. (USaveGame*)
	USaveGame* saveGame = UGameplayStatics::CreateSaveGameObject(UBestScoreData::StaticClass());

	//2. 생성한 놈을 UBestScoreData 로 Cast 하자
	UBestScoreData* bestScoreData = Cast<UBestScoreData>(saveGame);

	//3. saveBestScore = bestScore
	bestScoreData->saveBestScore = bestScore;
	
	//4. 저장한다
	UGameplayStatics::SaveGameToSlot(saveGame, TEXT("BEST_SCORE"),0);

}
void ACPPShootingGameModeBase::LoadBestScore()
{
	//1. "BEST_SCORE" 으로 되어 있는 데이터를 불러온다. (USaveGame*)
	USaveGame* saveGame = UGameplayStatics::LoadGameFromSlot(TEXT("BEST_SCORE"), 0);
	
	//2. 불러온 놈을 UBestScoreData 로 Cast 하자
	UBestScoreData* bestScoreData = Cast<UBestScoreData>(saveGame);

	//만약에 bestScoreData 가 nullptr 이 아니라면
	if (bestScoreData != nullptr) 
	{
		//3. bestScore = saveBestScore
		bestScore = bestScoreData->saveBestScore;

		//4. BestScore UI 를 갱신한다.
		mainUI->UpdateBestScoreUI(bestScore);
	}
}

void ACPPShootingGameModeBase::ShowGameOverUI()
{
	//GameOverUI 를 하나 만든다.
	gameOverUI = CreateWidget<UGameOverUI>(GetWorld(), gameOverWidget);

	//만든 UI 를 화면에 띄운다.
	gameOverUI->AddToViewport();
}


void ACPPShootingGameModeBase::ShuffleStudy()
{
	//int 를 100개 담을 수 있는 배열을 만든다.
	//초기값을 1 ~ 100까지 들어가게 한다

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
