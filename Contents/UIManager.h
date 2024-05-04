#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Image.h>
#include <EngineCore/TextWidget.h>

// Ό³Έν :
class UIManager : public AActor
{
	GENERATED_BODY(AActor)
public:
	// constrcuter destructer
	UIManager();
	~UIManager();

	// delete Function
	UIManager(const UIManager& _Other) = delete;
	UIManager(UIManager&& _Other) noexcept = delete;
	UIManager& operator=(const UIManager& _Other) = delete;
	UIManager& operator=(UIManager&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void UISpawn();
	void TimeUpdate(float _DeltaTime);
	void KillCountUpdate();
	void HPUpdate();

	UImage* Character = nullptr;
	UImage* CharacterFrame = nullptr;
	UImage* HPBar = nullptr;
	UImage* HPBarBack = nullptr;
	UImage* EXPBar = nullptr;
	UImage* EXPBarBack = nullptr;
	UImage* HUDHP = nullptr;
	UImage* HUDFrame = nullptr;

	UImage* Weapon = nullptr;
	UImage* Item = nullptr;

	UImage* StageText = nullptr;
	UImage* Gold = nullptr;
	UImage* KillCount = nullptr;

	UTextWidget* HPText = nullptr;
	UTextWidget* HPTextBack = nullptr;
	UTextWidget* TimeUI = nullptr;
	UTextWidget* GoldText = nullptr;
	UTextWidget* KillCountText = nullptr;
	UTextWidget* StateText = nullptr;
	UTextWidget* CharacterName = nullptr;

	std::vector<UImage*> WeaponIconBack;
	std::vector<std::vector<UImage*>> WeaponIcon;

	std::vector<UImage*> ITemIconBack;
	std::vector<std::vector<UImage*>> ITemIcon;

private:

};

