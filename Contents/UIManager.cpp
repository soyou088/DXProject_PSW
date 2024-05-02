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
}

void UIManager::UISpawn()
{

	//EXP
	EXPBarBack = CreateWidget<UImage>(GetWorld(), "EXPBarBack");
	EXPBarBack->AddToViewPort(1);
	EXPBarBack->SetSprite("hud_expbar_bg_0.png");
	EXPBarBack->SetAutoSize(ContentsValue::MultipleSize, true);
	EXPBarBack->SetPosition(FVector(10.0f, 340.0f));

	//HUD
	
	Character = CreateWidget<UImage>(GetWorld(), "HUDCharacter");
	Character->AddToViewPort(2);
	Character->SetSprite("spr_KiaraPortrait_0.png");
	Character->SetAutoSize(ContentsValue::MultipleSize, true);
	Character->SetPosition(FVector(-590.f, 288.f));
	
	CharacterFrame = CreateWidget<UImage>(GetWorld(), "HUDCharacterFrame");
	CharacterFrame->AddToViewPort(1);
	CharacterFrame->SetSprite("HUDCharacterFrame.png");
	CharacterFrame->SetAutoSize(ContentsValue::MultipleSize, true);
	CharacterFrame->SetPosition(FVector(-587.f, 293.f));

	HUDHP = CreateWidget<UImage>(GetWorld(), "HUDHP");
	HUDHP->AddToViewPort(1);
	HUDHP->SetSprite("hud_new_HUDHP_0.png");
	HUDHP->SetAutoSize(ContentsValue::MultipleSize, true);
	HUDHP->SetPosition(FVector(-450.f, 269.f));

	HPBar = CreateWidget<UImage>(GetWorld(), "HPBar");
	HPBar->AddToViewPort(1);
	HPBar->SetSprite("hud_HUD_HP_green_0.png");
	HPBar->SetAutoSize(ContentsValue::MultipleSize, true);
	HPBar->SetPosition(FVector(-382.f, 320.f));
	
	HUDFrame = CreateWidget<UImage>(GetWorld(), "HUDFrame");
	HUDFrame->AddToViewPort(1);
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
	Gold->AddToViewPort(1);
	Gold->SetSprite("ui_holoCoin_0.png");
	Gold->SetAutoSize(ContentsValue::MultipleSize, true);
	Gold->SetPosition(FVector(360.f, 310.0f));
	
	KillCount = CreateWidget<UImage>(GetWorld(), "KillCount");
	KillCount->AddToViewPort(1);
	KillCount->SetSprite("ui_defeatedEnemies_0.png");
	KillCount->SetAutoSize(ContentsValue::MultipleSize, true);
	KillCount->SetPosition(FVector(360.f, 275.0f));

}


