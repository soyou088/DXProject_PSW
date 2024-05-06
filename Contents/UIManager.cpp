#include "PreCompile.h"
#include "UIManager.h"
#include "Player.h"
#include "PlayGameMode.h"

#include <EngineBase/EngineRandom.h>

UIManager::UIManager()
{
}

UIManager::~UIManager()
{
}

void UIManager::BeginPlay()
{
	Super::BeginPlay();
	UISpawn();
}

void UIManager::Tick(float _DeltaTime)
{
	Super::Tick(_DeltaTime);
	TimeUpdate(_DeltaTime);
	KillCountUpdate();
	PauseChack();

}

void UIManager::UISpawn()
{

	//EXP
	EXPBarBack = CreateWidget<UImage>(GetWorld(), "EXPBarBack");
	EXPBarBack->AddToViewPort(2);
	EXPBarBack->SetSprite("hud_expbar_bg_0.png");
	EXPBarBack->SetAutoSize(ContentsValue::MultipleSize, true);
	EXPBarBack->SetPosition(FVector(10.0f, 340.0f));

	EXPBar = CreateWidget<UImage>(GetWorld(), "EXPBar");
	EXPBar->AddToViewPort(3);
	EXPBar->SetSprite("hud_expbar_gauge_0.png");
	EXPBar->SetAutoSize(ContentsValue::MultipleSize, true);
	EXPBar->SetPosition(FVector(10.0f, 340.0f));

	//HUD
	
	Character = CreateWidget<UImage>(GetWorld(), "HUDCharacter");
	Character->AddToViewPort(3);
	Character->SetSprite("spr_KiaraPortrait_0.png");
	Character->SetAutoSize(ContentsValue::MultipleSize, true);
	Character->SetPosition(FVector(-590.f, 288.f));
	
	CharacterFrame = CreateWidget<UImage>(GetWorld(), "HUDCharacterFrame");
	CharacterFrame->AddToViewPort(2);
	CharacterFrame->SetSprite("HUDCharacterFrame.png");
	CharacterFrame->SetAutoSize(ContentsValue::MultipleSize, true);
	CharacterFrame->SetPosition(FVector(-587.f, 293.f));

	HUDHP = CreateWidget<UImage>(GetWorld(), "HUDHP");
	HUDHP->AddToViewPort(2);
	HUDHP->SetSprite("hud_new_HUDHP_0.png");
	HUDHP->SetAutoSize(ContentsValue::MultipleSize, true);
	HUDHP->SetPosition(FVector(-450.f, 269.f));

	HPBar = CreateWidget<UImage>(GetWorld(), "HPBar");
	HPBar->AddToViewPort(2);
	HPBar->SetSprite("hud_HUD_HP_green_0.png");
	HPBar->SetAutoSize(ContentsValue::MultipleSize, true);
	HPBar->SetPosition(FVector(-382.f, 320.f));
	
	HUDFrame = CreateWidget<UImage>(GetWorld(), "HUDFrame");
	HUDFrame->AddToViewPort(2);
	HUDFrame->SetSprite("hud_new_HUDFrame_0.png");
	HUDFrame->SetAutoSize(ContentsValue::MultipleSize, true);
	HUDFrame->SetPosition(FVector(-445.f, 270.0f));
	
	WeaponIcon.resize(6);
	for (int i = 0; i < 6; i++)
	{
		UImage* WeaponIconBack = CreateWidget<UImage>(GetWorld(), "WeaponIconBack");
		WeaponIconBack->AddToViewPort(1);
		WeaponIconBack->SetSprite("ui_empty_slot_weapon_0.png");
		WeaponIconBack->SetAutoSize(ContentsValue::MultipleSize, true);
		WeaponIconBack->SetPosition(FVector(-520.f + 50.f * i, 275.f));
		WeaponIconBack->SetMulColor({ 1.0f,1.0f,1.0f,0.7f });
		
		UImage* ITemIcon = CreateWidget<UImage>(GetWorld(), "ITemIconBack");
		ITemIcon->AddToViewPort(1);
		ITemIcon->SetSprite("ui_empty_slot_item_0.png");
		ITemIcon->SetAutoSize(ContentsValue::MultipleSize, true);
		ITemIcon->SetPosition(FVector(-520.f + 50.f * i, 225.f));
		ITemIcon->SetMulColor({ 1.0f,1.0f,1.0f,0.7f });

	}

	Gold = CreateWidget<UImage>(GetWorld(), "Gold");
	Gold->AddToViewPort(2);
	Gold->SetSprite("ui_holoCoin_0.png");
	Gold->SetAutoSize(ContentsValue::MultipleSize, true);
	Gold->SetPosition(FVector(360.f, 310.0f));
	
	KillCount = CreateWidget<UImage>(GetWorld(), "KillCount");
	KillCount->AddToViewPort(2);
	KillCount->SetSprite("ui_defeatedEnemies_0.png");
	KillCount->SetAutoSize(ContentsValue::MultipleSize, true);
	KillCount->SetPosition(FVector(360.f, 275.0f));

	TimeUI = CreateWidget<UTextWidget>(GetWorld(), "Time");
	TimeUI->AddToViewPort(5);
	TimeUI->SetScale(ContentsValue::MultipleSize * 10);
	TimeUI->SetFont("Galmuri9");
	TimeUI->SetColor(Color8Bit::White);
	TimeUI->SetPosition(FVector(0.f, 285.f));
	TimeUI->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));

	StageText = CreateWidget<UImage>(GetWorld(), "StageText");
	StageText->AddToViewPort(5);
	StageText->SetSprite("STAGE.png");
	StageText->SetAutoSize(0.6f, true);
	StageText->SetPosition(FVector(0.f, 305.f));

	//ESC´©¸¥ ÈÄ
	PuaseBack = CreateWidget<UImage>(GetWorld(), "PuaseBack");
	PuaseBack->AddToViewPort(1);
	PuaseBack->SetSprite("menu_charselecLocked_0.png");
	PuaseBack->SetAutoSize(ContentsValue::MultipleSize * 15, true);
	PuaseBack->SetPosition(FVector(0.f, 0.f));
	PuaseBack->SetActive(false);

	SetBack = CreateWidget<UImage>(GetWorld(), "SetBack");
	SetBack->AddToViewPort(1);
	SetBack->SetSprite("hud_pausemenu_0.png");
	SetBack->SetAutoSize(ContentsValue::MultipleSize, true);
	SetBack->SetPosition(FVector(0.f, 0.f));
	SetBack->SetActive(false);

	
	CharacterBack = CreateWidget<UImage>(GetWorld(), "SetBack");
	CharacterBack->AddToViewPort(1);
	CharacterBack->SetSprite("spr_Title_Kiara_0.png");
	CharacterBack->SetAutoSize(ContentsValue::MultipleSize * 1.5, true);
	CharacterBack->SetPosition(FVector(-550.f, 0.f));
	CharacterBack->SetMulColor({ 1.0f,1.0f,1.0f,0.5f });
	CharacterBack->SetActive(false);

	for (int i = 0; i < 5; i++)
	{
		UImage* SetBurton = CreateWidget<UImage>(GetWorld(), "SetBurton");
		SetBurton->AddToViewPort(2);
		SetBurton->SetSprite("hud_OptionButton_0.png");
		SetBurton->SetAutoSize(ContentsValue::MultipleSize, true);
		SetBurton->SetPosition(FVector(0.f, 100.f - 50.f * i));
		SetBurton->SetActive(false);
		SetBurtonVector.push_back(SetBurton);

		//SetBurtonCollision = CreateDefaultSubObject<UCollision>("SetBurtonCollision");
		//SetBurtonCollision->SetScale({ 85.0f, 80.0f });
		//SetBurtonCollision->SetPosition(FVector(0.f, 100.f - 50.f * i));
		//SetBurtonCollision->SetCollisionGroup(ECollisionOrder::Menu);
		//SetBurtonCollision->SetCollisionType(ECollisionType::Rect);
	}

	 
	HP = CreateWidget<UImage>(GetWorld(), "PuaseHP");
	HP->AddToViewPort(2);
	HP->SetSprite("hud_HPicon_0.png");
	HP->SetAutoSize(ContentsValue::MultipleSize, true);
	HP->SetPosition(FVector(-550.f, 0.f));
	HP->SetActive(false);

	ATK = CreateWidget<UImage>(GetWorld(), "PuaseATK");
	ATK->AddToViewPort(2);
	ATK->SetSprite("hud_atkicon_0.png");
	ATK->SetAutoSize(ContentsValue::MultipleSize, true);
	ATK->SetPosition(FVector(-550.f, -40.f));
	ATK->SetActive(false);
	
	SPD = CreateWidget<UImage>(GetWorld(), "PuaseSPD");
	SPD->AddToViewPort(2);
	SPD->SetSprite("hud_spdicon_0.png");
	SPD->SetAutoSize(ContentsValue::MultipleSize, true);
	SPD->SetPosition(FVector(-550.f, -80.f));
	SPD->SetActive(false);

	CRT = CreateWidget<UImage>(GetWorld(), "PuaseCRT");
	CRT->AddToViewPort(2);
	CRT->SetSprite("hud_criticon_0.png");
	CRT->SetAutoSize(ContentsValue::MultipleSize, true);
	CRT->SetPosition(FVector(-550.f, -120.f));
	CRT->SetActive(false);

	PickUP = CreateWidget<UImage>(GetWorld(), "PuasePickUP");
	PickUP->AddToViewPort(2);
	PickUP->SetSprite("hud_pickupicon_0.png");
	PickUP->SetAutoSize(ContentsValue::MultipleSize, true);
	PickUP->SetPosition(FVector(-550.f, -160.f));
	PickUP->SetActive(false);

	Haste = CreateWidget<UImage>(GetWorld(), "PuaseHaste");
	Haste->AddToViewPort(2);
	Haste->SetSprite("hud_cooldownicon_0.png");
	Haste->SetAutoSize(ContentsValue::MultipleSize, true);
	Haste->SetPosition(FVector(-550.f, -200.f));
	Haste->SetActive(false);



	
	
	
	


	// UI TEXT
	HPText = CreateWidget<UTextWidget>(GetWorld(), "HP");
	HPText->AddToViewPort(4);
	HPText->SetScale(15.f);
	HPText->SetFont("Galmuri9");
	HPText->SetColor(Color8Bit::White);
	HPText->SetPosition(FVector(-225.f, 320.f));
	
	HPTextBack = CreateWidget<UTextWidget>(GetWorld(), "HP");
	HPTextBack->AddToViewPort(3);
	HPTextBack->SetScale(ContentsValue::MultipleSize * 8);
	HPTextBack->SetFont("Galmuri9");
	HPTextBack->SetColor(Color8Bit::Black);
	HPTextBack->SetPosition(FVector(-225.f, 320.f));

	KillCountText = CreateWidget<UTextWidget>(GetWorld(), "KillCount");
	KillCountText->AddToViewPort(4);
	KillCountText->SetScale(ContentsValue::MultipleSize * 10);
	KillCountText->SetFont("Galmuri9");
	KillCountText->SetColor(Color8Bit::White);
	KillCountText->SetPosition(FVector(385.f, 275.f));
	KillCountText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

}


void UIManager::TimeUpdate(float _DeltaTime)
{
	ContentsValue::Time += _DeltaTime;

	int Time = static_cast<int>(ContentsValue::Time);
	int Second = Time % 60;
	int Minute = Time / 60;

	std::string SecondZeroPadding = "00" + std::to_string(Second);
	std::string MinuteZeroPadding = "00" + std::to_string(Minute);

	std::string SecondText = SecondZeroPadding.substr(SecondZeroPadding.size() - 2, 2);
	std::string MinuteText = MinuteZeroPadding.substr(MinuteZeroPadding.size() - 2, 2);

	TimeUI->SetText(MinuteText + " : " + SecondText);


}

void UIManager::KillCountUpdate()
{
	KillCountText->SetText(std::to_string(ContentsValue::KillCount));
}

void UIManager::HPUpdate()
{
	//HPText->APlayer::GetHp();
}

void UIManager::PauseChack()
{
	if (true == APlayGameMode::PauseON)
	{
		PuaseBack->SetActive(true);
		SetBack->SetActive(true);
		HP->SetActive(true);
		ATK->SetActive(true);
		SPD->SetActive(true);
		CRT->SetActive(true);
		PickUP->SetActive(true);
		Haste->SetActive(true);
		CharacterBack->SetActive(true);

		for (SetBurtonIter = SetBurtonVector.begin(); SetBurtonIter != SetBurtonVector.end(); SetBurtonIter++)
		{
			UImage* SetBurton = *SetBurtonIter;

			SetBurton->SetActive(true);
		}
	}
	else
	{
		PuaseBack->SetActive(false);
		SetBack->SetActive(false);
		HP->SetActive(false);
		ATK->SetActive(false);
		SPD->SetActive(false);
		CRT->SetActive(false);
		PickUP->SetActive(false);
		Haste->SetActive(false);
		CharacterBack->SetActive(false);


		for (SetBurtonIter = SetBurtonVector.begin(); SetBurtonIter != SetBurtonVector.end(); SetBurtonIter++)
		{
			UImage* SetBurton = *SetBurtonIter;

			SetBurton->SetActive(false);
		}
	}
}

void UIManager::CollisionChack()
{

}


