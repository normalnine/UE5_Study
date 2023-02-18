// Fill out your copyright notice in the Description page of Project Settings.


#include "AlgoPuzzle.h"
#include <Components/Image.h>
#include <Components/CanvasPanelSlot.h>

void UAlgoPuzzle::NativeConstruct()
{
	Super::NativeConstruct();

	// ī�� �̹��� �����ͼ� �迭�� ����
	for (int32 i = 0; i < 9; i++)
	{
		FString str = FString::Printf(TEXT("Card%d"), i);
		UImage* img = Cast<UImage>(GetWidgetFromName(*str));
		cards.Add(img);
	}
	UE_LOG(LogTemp,Warning,TEXT("Total Card Count : %d"), cards.Num());

	// offset �� ����
	UWidget* firstCard = GetWidgetFromName(TEXT("Card"));
	UCanvasPanelSlot* slot = Cast<UCanvasPanelSlot>(firstCard->Slot);
	offX = slot->GetPosition().X;
	offY = slot->GetPosition().Y;

	// ī�� �ʱ�ȭ
	InitCard();
}

void UAlgoPuzzle::InitCard()
{
	// cardValues �� ������ 0���� ����
	cardValues.Empty();

	// samevalues �� ������ 0���� ����
	sameCards.Empty();

	// ������ ��(0,1)�� �̾Ƽ� 0�̸� ���, 1�̸� �Ķ�
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
	// (���콺x / ī��(����)ũ�� + ���콺y / ī��(����)ũ�� * ����ī�尹��) = ���õ� ī�� idx
	int32 x = (mousePos.X-offX)/cardSize;
	int32 y = (mousePos.Y-offY)/cardSize;

	int32 selectIdx = x+y * hCount;
	UE_LOG(LogTemp, Error, TEXT("select idx : %d"), selectIdx);

	// ���࿡ ������ ��� ���� �����ߵ��� �Լ��� ������
	if(selectIdx >= cards.Num()) return;

	// ������ ī�带 ���������� ����
	cards[selectIdx]->SetColorAndOpacity(FLinearColor::Red);
	
	// ������ ī�� idx �� sameCards�� ����
	sameCards.AddUnique(selectIdx);

	// ���õ� ī���� ���� ����
	selectCardValue = cardValues[selectIdx];

	// ���õ� ī�� ��,��,��,�� ī�带 ã��
	FindNearCard(selectIdx);
}


void UAlgoPuzzle::FindNearCard(int32 idx)
{
	// ��
	if(idx / vCount > 0)
	{
		int32 upIdx = idx - hCount;
		FindSameValueCard(upIdx);
		UE_LOG(LogTemp,Warning, TEXT("%d"), upIdx);
	}
	
	// ����
	if (idx % hCount > 0) 
	{
		int32 leftIdx = idx - 1;
		FindSameValueCard(leftIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), leftIdx);
	}

	// ������
	if (idx % hCount < hCount-1)
	{
		int32 rightIdx = idx + 1;
		FindSameValueCard(rightIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), rightIdx);
	}

	// �Ʒ�
	if (idx / vCount < vCount-1)
	{
		int32 downIdx = idx + hCount;
		FindSameValueCard(downIdx);
		UE_LOG(LogTemp, Warning, TEXT("%d"), downIdx);
	}
}


void UAlgoPuzzle::FindSameValueCard(int32 nearIdx)
{
	// ���� ���� ������ �ִ�?
	if (selectCardValue == cardValues[nearIdx])
	{
		// nearIdx �� sameCards �� ���ٸ�
		if (sameCards.Contains(nearIdx) == false)
		{
			cards[nearIdx]->SetColorAndOpacity(FLinearColor::Red);

			// smaeCards �� �߰�
			sameCards.Add(nearIdx);

			// nearIdx �� �ٽ�
			FindNearCard(nearIdx);
		}
	}

}