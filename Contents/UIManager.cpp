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

	//ESC누른 후
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

	for (int i = 0; i < 6; i++)
	{
		UImage* SetBurton = CreateWidget<UImage>(GetWorld(), "SetBurton");
		SetBurton->AddToViewPort(2);
		SetBurton->SetSprite("hud_Button_0.png");
		SetBurton->SetAutoSize(ContentsValue::MultipleSize * 1.3, true);
		SetBurton->SetPosition(FVector(0.f, 120.f - 60.f * i));
		SetBurton->SetActive(false);
		SetBurtonVector.push_back(SetBurton);

		//SetBurtonCollision = CreateDefaultSubObject<UCollision>("SetBurtonCollision");
		//SetBurtonCollision->SetScale({ 85.0f, 80.0f });
		//SetBurtonCollision->SetPosition(FVector(0.f, 100.f - 50.f * i));
		//SetBurtonCollision->SetCollisionGroup(ECollisionOrder::Menu);
		//SetBurtonCollision->SetCollisionType(ECollisionType::Rect);
	}

	for (int i = 0; i < 6; i++)
	{
		UImage* StatLine = CreateWidget<UImage>(GetWorld(), "StatLine");
		StatLine->AddToViewPort(2);
		StatLine->SetSprite("ui_menu_stats_divider_0.png");
		StatLine->SetAutoSize(ContentsValue::MultipleSize, true);
		StatLine->SetPosition(FVector(-400.f, -10.f - 45.f * i));
		StatLine->SetActive(false);
		StatLineVector.push_back(StatLine);
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
	ATK->SetPosition(FVector(-550.f, -42.f));
	ATK->SetActive(false);
	
	SPD = CreateWidget<UImage>(GetWorld(), "PuaseSPD");
	SPD->AddToViewPort(2);
	SPD->SetSprite("hud_spdicon_0.png");
	SPD->SetAutoSize(ContentsValue::MultipleSize, true);
	SPD->SetPosition(FVector(-550.f, -84.f));
	SPD->SetActive(false);

	CRT = CreateWidget<UImage>(GetWorld(), "PuaseCRT");
	CRT->AddToViewPort(2);
	CRT->SetSprite("hud_criticon_0.png");
	CRT->SetAutoSize(ContentsValue::MultipleSize, true);
	CRT->SetPosition(FVector(-550.f, -130.f));
	CRT->SetActive(false);

	PickUP = CreateWidget<UImage>(GetWorld(), "PuasePickUP");
	PickUP->AddToViewPort(2);
	PickUP->SetSprite("hud_pickupicon_0.png");
	PickUP->SetAutoSize(ContentsValue::MultipleSize, true);
	PickUP->SetPosition(FVector(-550.f, -178.f));
	PickUP->SetActive(false);

	Haste = CreateWidget<UImage>(GetWorld(), "PuaseHaste");
	Haste->AddToViewPort(2);
	Haste->SetSprite("hud_cooldownicon_0.png");
	Haste->SetAutoSize(ContentsValue::MultipleSize, true);
	Haste->SetPosition(FVector(-550.f, -220.f));
	Haste->SetActive(false);
	

	// UI TEXT
	HPText = CreateWidget<UTextWidget>(GetWorld(), "HP");
	HPText->AddToViewPort(3);
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
	KillCountText->AddToViewPort(3);
	KillCountText->SetScale(ContentsValue::MultipleSize * 10);
	KillCountText->SetFont("Galmuri9");
	KillCountText->SetColor(Color8Bit::White);
	KillCountText->SetPosition(FVector(385.f, 275.f));
	KillCountText->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_LEFT | FW1_TEXT_FLAG::FW1_VCENTER));

	// StatUI TEXT
	StatHPText = CreateWidget<UTextWidget>(GetWorld(), "StatHPText");
	StatHPText->AddToViewPort(3);
	StatHPText->SetScale(ContentsValue::MultipleSize * 10);
	StatHPText->SetFont("Galmuri9");
	StatHPText->SetColor(Color8Bit::White);
	StatHPText->SetPosition(FVector(-507.f, 4.f));
	StatHPText->SetText("HP");
	StatHPText->SetActive(false);

	StatATKText = CreateWidget<UTextWidget>(GetWorld(), "StatATKText");
	StatATKText->AddToViewPort(3);
	StatATKText->SetScale(ContentsValue::MultipleSize * 10);
	StatATKText->SetFont("Galmuri9");
	StatATKText->SetColor(Color8Bit::White);
	StatATKText->SetPosition(FVector(-504.f, -40.f));
	StatATKText->SetText("ATK");
	StatATKText->SetActive(false);

	StatSPDText = CreateWidget<UTextWidget>(GetWorld(), "StatSPDText");
	StatSPDText->AddToViewPort(3);
	StatSPDText->SetScale(ContentsValue::MultipleSize * 10);
	StatSPDText->SetFont("Galmuri9");
	StatSPDText->SetColor(Color8Bit::White);
	StatSPDText->SetPosition(FVector(-504.f, -84.f));
	StatSPDText->SetText("SPD");
	StatSPDText->SetActive(false);

	StatCRTText = CreateWidget<UTextWidget>(GetWorld(), "StatCRTText");
	StatCRTText->AddToViewPort(3);
	StatCRTText->SetScale(ContentsValue::MultipleSize * 10);
	StatCRTText->SetFont("Galmuri9");
	StatCRTText->SetColor(Color8Bit::White);
	StatCRTText->SetPosition(FVector(-503.f, -128.f));
	StatCRTText->SetText("CRT");
	StatCRTText->SetActive(false);

	StatPickUPText = CreateWidget<UTextWidget>(GetWorld(), "StatPickUPText");
	StatPickUPText->AddToViewPort(3);
	StatPickUPText->SetScale(ContentsValue::MultipleSize * 10);
	StatPickUPText->SetFont("Galmuri9");
	StatPickUPText->SetColor(Color8Bit::White);
	StatPickUPText->SetPosition(FVector(-490.f, -175.f));
	StatPickUPText->SetText("PickUP");
	StatPickUPText->SetActive(false);

	StatHasteText = CreateWidget<UTextWidget>(GetWorld(), "StatHasteText");
	StatHasteText->AddToViewPort(3);
	StatHasteText->SetScale(ContentsValue::MultipleSize * 10);
	StatHasteText->SetFont("Galmuri9");
	StatHasteText->SetColor(Color8Bit::White);
	StatHasteText->SetPosition(FVector(-493.f, -218.f));
	StatHasteText->SetText("Haste");
	StatHasteText->SetActive(false);
	
	PuaseSkillText = CreateWidget<UTextWidget>(GetWorld(), "PuaseSkillText");
	PuaseSkillText->AddToViewPort(4);
	PuaseSkillText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseSkillText->SetFont("Galmuri9");
	PuaseSkillText->SetColor(Color8Bit::White);
	PuaseSkillText->SetPosition(FVector(0.f, 125.f));
	PuaseSkillText->SetText("스킬");
	PuaseSkillText->SetActive(false);
	
	PuaseStampText = CreateWidget<UTextWidget>(GetWorld(), "PuaseStampText");
	PuaseStampText->AddToViewPort(10);
	PuaseStampText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseStampText->SetFont("Galmuri9");
	PuaseStampText->SetColor(Color8Bit::White);
	PuaseStampText->SetPosition(FVector(0.f, 65.f));
	PuaseStampText->SetText("스탬프");
	PuaseStampText->SetActive(false);

	PuaseCollaborationText = CreateWidget<UTextWidget>(GetWorld(), "PuaseCollaborationText");
	PuaseCollaborationText->AddToViewPort(10);
	PuaseCollaborationText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseCollaborationText->SetFont("Galmuri9");
	PuaseCollaborationText->SetColor(Color8Bit::White);
	PuaseCollaborationText->SetPosition(FVector(0.f, 5.f));
	PuaseCollaborationText->SetText("콜라보");
	PuaseCollaborationText->SetActive(false);

	PuaseContinueText = CreateWidget<UTextWidget>(GetWorld(), "PuaseContinueText");
	PuaseContinueText->AddToViewPort(4);
	PuaseContinueText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseContinueText->SetFont("Galmuri9");
	PuaseContinueText->SetColor(Color8Bit::White);
	PuaseContinueText->SetPosition(FVector(0.f, -55.f));
	PuaseContinueText->SetText("이어서 하기");
	PuaseContinueText->SetActive(false);

	PuaseSettingText = CreateWidget<UTextWidget>(GetWorld(), "PuaseSettingText");
	PuaseSettingText->AddToViewPort(4);
	PuaseSettingText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseSettingText->SetFont("Galmuri9");
	PuaseSettingText->SetColor(Color8Bit::White);
	PuaseSettingText->SetPosition(FVector(0.f, -115.f));
	PuaseSettingText->SetText("설정");
	PuaseSettingText->SetActive(false);

	PuaseExitText = CreateWidget<UTextWidget>(GetWorld(), "PuaseExitText");
	PuaseExitText->AddToViewPort(4);
	PuaseExitText->SetScale(ContentsValue::MultipleSize * 11);
	PuaseExitText->SetFont("Galmuri9");
	PuaseExitText->SetColor(Color8Bit::White);
	PuaseExitText->SetPosition(FVector(0.f, -175.f));
	PuaseExitText->SetText("나가기");
	PuaseExitText->SetActive(false);

	
	
	
	

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

		StatHPText->SetActive(true);
		StatATKText->SetActive(true);
		StatSPDText->SetActive(true);
		StatCRTText->SetActive(true);
		StatPickUPText->SetActive(true);
		StatHasteText->SetActive(true);
		for (SetBurtonIter = SetBurtonVector.begin(); SetBurtonIter != SetBurtonVector.end(); SetBurtonIter++)
		{
			UImage* SetBurton = *SetBurtonIter;

			SetBurton->SetActive(true);
		}

		for (StatLineIter = StatLineVector.begin(); StatLineIter != StatLineVector.end(); StatLineIter++)
		{
			UImage* StatLine = *StatLineIter;

			StatLine->SetActive(true);
		}

		PuaseSkillText->SetActive(true);
		PuaseStampText->SetActive(true);
		PuaseCollaborationText->SetActive(true);
		PuaseContinueText->SetActive(true);
		PuaseSettingText->SetActive(true);
		PuaseExitText->SetActive(true);

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

		StatHPText->SetActive(false);
		StatATKText->SetActive(false);
		StatSPDText->SetActive(false);
		StatCRTText->SetActive(false);
		StatPickUPText->SetActive(false);
		StatHasteText->SetActive(false);
		for (SetBurtonIter = SetBurtonVector.begin(); SetBurtonIter != SetBurtonVector.end(); SetBurtonIter++)
		{
			UImage* SetBurton = *SetBurtonIter;

			SetBurton->SetActive(false);
		}


		for (StatLineIter = StatLineVector.begin(); StatLineIter != StatLineVector.end(); StatLineIter++)
		{
			UImage* StatLine = *StatLineIter;

			StatLine->SetActive(false);
		}

		PuaseSkillText->SetActive(false);
		PuaseStampText->SetActive(false);
		PuaseCollaborationText->SetActive(false);
		PuaseContinueText->SetActive(false);
		PuaseSettingText->SetActive(false);
		PuaseExitText->SetActive(false);
	}


}

void UIManager::CollisionChack()
{

}


