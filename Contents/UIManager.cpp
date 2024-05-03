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

}

void UIManager::UISpawn()
{

	//EXP
	EXPBarBack = CreateWidget<UImage>(GetWorld(), "EXPBarBack");
	EXPBarBack->AddToViewPort(2);
	EXPBarBack->SetSprite("hud_expbar_bg_0.png");
	EXPBarBack->SetAutoSize(ContentsValue::MultipleSize, true);
	EXPBarBack->SetPosition(FVector(10.0f, 340.0f));

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
	
	//Weapon = CreateWidget<UImage>(GetWorld(), "HUDWeapon");
	//Weapon->AddToViewPort(1);
	//Weapon->SetSprite("ui_empty_slot_weapon_0.png");
	//Weapon->SetAutoSize(ContentsValue::MultipleSize, true);
	//Weapon->SetPosition(FVector(-445.f, 270.0f));

	//Item = CreateWidget<UImage>(GetWorld(), "HUDItem");
	//Item->AddToViewPort(1);
	//Item->SetSprite("ui_empty_slot_item_0.png");
	//Item->SetAutoSize(ContentsValue::MultipleSize, true);
	//Item->SetPosition(FVector(-445.f, 270.0f));

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
	TimeUI->SetScale(20.f);
	TimeUI->SetFont("Galmuri9");
	TimeUI->SetColor(Color8Bit::White);
	TimeUI->SetPosition(FVector(0.f, 285.f));
	TimeUI->SetFlag(static_cast<FW1_TEXT_FLAG>(FW1_TEXT_FLAG::FW1_CENTER | FW1_TEXT_FLAG::FW1_VCENTER));

	StageText = CreateWidget<UImage>(GetWorld(), "StageText");
	StageText->AddToViewPort(5);
	StageText->SetSprite("STAGE.png");
	StageText->SetAutoSize(0.6f, true);
	StageText->SetPosition(FVector(0.f, 305.f));

	// UI TEXT
	HPText = CreateWidget<UTextWidget>(GetWorld(), "HP");
	HPText->AddToViewPort(4);
	HPText->SetScale(15.f);
	HPText->SetFont("Galmuri9");
	HPText->SetColor(Color8Bit::White);
	HPText->SetPosition(FVector(-225.f, 320.f));
	
	HPTextBack = CreateWidget<UTextWidget>(GetWorld(), "HP");
	HPTextBack->AddToViewPort(3);
	HPTextBack->SetScale(16.f);
	HPTextBack->SetFont("Galmuri9");
	HPTextBack->SetColor(Color8Bit::Black);
	HPTextBack->SetPosition(FVector(-225.f, 320.f));

	KillCountText = CreateWidget<UTextWidget>(GetWorld(), "KillCount");
	KillCountText->AddToViewPort(4);
	KillCountText->SetScale(20.f);
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
