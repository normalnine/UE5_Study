// Fill out your copyright notice in the Description page of Project Settings.


#include "GameOverUI.h"
#include <Kismet/GameplayStatics.h>
#include <Components/Button.h>
#include "TpsPlayer.h"

void UGameOverUI::NativeConstruct()
{
	Super::NativeConstruct();

	AActor* player = UGameplayStatics::GetActorOfClass(GetWorld(),ATpsPlayer::StaticClass());
	
	if (player != nullptr)
	{
		//마우스 보이게 하자
		GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;

		//게임 일시 정지
		UGameplayStatics::SetGamePaused(GetWorld(), true);

		//버튼 이벤트에 호출되는 함수 등록
		BtnRetry->OnHovered.AddDynamic(this, &UGameOverUI::OnHover);
		BtnRetry->OnUnhovered.AddDynamic(this, &UGameOverUI::UnHover);
		BtnRetry->OnClicked.AddDynamic(this, &UGameOverUI::OnClick);
		BtnRetry->OnPressed.AddDynamic(this, &UGameOverUI::OnPress);

		//BtnIdle anim 실행
		PlayAnimation(BtnIdle, 0, 0);

	}

}

void UGameOverUI::OnHover()
{
	StopAnimation(BtnIdle);
	PlayAnimation(BtnHover,0,1);
}

void UGameOverUI::UnHover()
{
	PlayAnimation(BtnHover, 0, 1,EUMGSequencePlayMode::Reverse);

	PlayAnimation(BtnIdle,0,0);
}

void UGameOverUI::OnClick()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("TpsMap"));
	
}

void UGameOverUI::OnPress()
{
	PlayAnimation(BtnClick, 0, 1);
}