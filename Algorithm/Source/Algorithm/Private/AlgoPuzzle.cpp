// Fill out your copyright notice in the Description page of Project Settings.


#include "AlgoPuzzle.h"
#include <Components/Image.h>
#include <Components/CanvasPanelSlot.h>

void UAlgoPuzzle::NativeConstruct()
{
	Super::NativeConstruct();

	// 카드 이미지 가져와서 배열에 담자
	for (int32 i = 0; i < 9; i++)
	{
		FString str = FString::Printf(TEXT("Card%d"), i);
		UImage* img = Cast<UImage>(GetWidgetFromName(*str));
		cards.Add(img);
	}
	UE_LOG(LogTemp,Warning,TEXT("Total Card Count : %d"), cards.Num());

	// offset 값 셋팅
	UWidget* firstCard = GetWidgetFromName(TEXT("Card"));
	UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(firstCard->Slot);
	offX = slot->GetPosition().X;
	offY = slot->GetPosition().Y;

	// 카드 초기화
	InitCard();
}

void UAlgoPuzzle::InitCard()
{
	// cardValues 의 갯수를 0으로 하자
	cardValues.Empty();

	// samevalues 의 갯수를 0으로 하자
	sameCards.Empty();

	// 랜덤한 값(0,1)을 뽑아서 0이면 노랑, 1이면 파랑
	for (int32 i = 0; i < cards.Num(); i++)
	{
		int32 rand = FMath::RandRange(0,1);

		cardValues.Add(rand);

		if (rand == 0)
		{
			cards[i]->SetColorAndOpacity(FLinearColor::Yellow);
		}
		else
		{
			cards[i]->SetColorAndOpacity(FLinearColor::Blue);
		}
	}
}

void UAlgoPuzzle::SelectCard(FVector2D mousePos)
{
	// (마우스x / 카드(가로)크기 + 마우스y / 카드(세로)크기 * 가로카드갯수) = 선택된 카드 idx
	int32 x = (mousePos.X-offX)/cardSize;
	int32 y = (mousePos.Y-offY)/cardSize;

	int32 selectIdx = x+y * hCount;
	UE_LOG(LogTemp, Error, TEXT("select idx : %d"), selectIdx);

	// 만약에 범위를 벗어난 곳을 선택했따면 함수를 나가자
	if(selectIdx >= cards.Num()) return;

	// 선택한 카드를 빨간색으로 하자
	cards[selectIdx]->SetColorAndOpacity(FLinearColor::Red);
	
	// 선택한 카드 idx 를 sameCards에 넣자
	sameCards.AddUnique(selectIdx);

	// 선택된 카드의 값을 셋팅
	selectCardValue = cardValues[selectIdx];

	// 선택된 카드 좌,우,상,하 카드를 찾자
	FindNearCard(selectIdx);
}


void UAlgoPuzzle::FindNearCard(int32 idx)
{
	// 위
	if(idx / vCount > 0)
	{
		int32 upIdx = idx - hCount;
		FindSameValueCard(upIdx);
		UE_LOG(LogTemp,Warning, TEXT("%d"), upIdx);
	}
	
	// 왼쪽
	if (idx % hCount > 0) 
	{
		int32 leftIdx = idx - 1;
		FindSameValueCard(leftIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), leftIdx);
	}

	// 오른쪽
	if (idx % hCount < hCount-1)
	{
		int32 rightIdx = idx + 1;
		FindSameValueCard(rightIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), rightIdx);
	}

	// 아래
	if (idx / vCount < vCount-1)
	{
		int32 downIdx = idx + hCount;
		FindSameValueCard(downIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), downIdx);
	}
}


void UAlgoPuzzle::FindSameValueCard(int32 nearIdx)
{
	// 같은 값을 가지고 있니?
	if (selectCardValue == cardValues[nearIdx])
	{
		// nearIdx 가 sameCards 에 없다면
		if (sameCards.Contains(nearIdx) == false)
		{
			cards[nearIdx]->SetColorAndOpacity(FLinearColor::Red);

			// smaeCards 에 추가
			sameCards.Add(nearIdx);

			// nearIdx 로 다시
			FindNearCard(nearIdx);
		}
	}

}